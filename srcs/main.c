#include "hittable.h"
#include "minirt.h"
#include "math_utils.h"
#include "metal.h"
#include "lambertian.h"
#include "dielectric.h"
#include "camera.h"
#include "rectangle.h"
#include "light.h"

// t_color型に変換する関数
t_color vec3_to_color(t_vec3 v) {
    return (t_color){v.x, v.y, v.z};
}

// t_vec3型に変換する関数
t_vec3 color_to_vec3(t_color c) {
    return (t_vec3){c.r, c.g, c.b};
}

t_color ray_color(t_ray *ray, t_hittable_list *world, t_light_list *lights, int depth) {
    t_hit_record rec;
    if (depth <= 0)
        return (t_color){0, 0, 0};

    if (hit_list(world, ray, 0.001, INFINITY, &rec)) {
        t_color total_light_color = {0, 0, 0};
        for (int i = 0; i < lights->count; i++) {
            t_light *light = &lights->lights[i];
            t_vec3 light_dir = vec_normalize(vec_sub(light->position, rec.point));
            double light_intensity = light->intensity * fmax(0.0, vec_dot(rec.normal, light_dir));
            t_vec3 light_color_vec = vec_scalar(color_to_vec3(light->color), light_intensity);
            t_color light_color = vec3_to_color(light_color_vec);
            total_light_color = vec3_to_color(vec_add(color_to_vec3(total_light_color), color_to_vec3(light_color)));
        }

        t_ray scattered;
        t_color attenuation;
        if (rec.material == LAMBERTIAN) {
            t_vec3 target = vec_add(rec.point, vec_add(rec.normal, random_unit_vector()));
            scattered = (t_ray){rec.point, vec_sub(target, rec.point), ray->time};
            attenuation = rec.color;
        } else if (rec.material == METAL) {
            t_vec3 reflected = reflect(vec_normalize(ray->direction), rec.normal);
            scattered = (t_ray){rec.point, vec_add(reflected, vec_scalar(random_in_unit_sphere(), rec.fuzz)), ray->time};
            attenuation = rec.color;
        } else if (rec.material == DIELECTRIC) {
            double etai_over_etat = rec.front_face ? (1.0 / rec.ref_idx) : rec.ref_idx;
            t_vec3 unit_direction = vec_normalize(ray->direction);
            double cos_theta = fmin(vec_dot(vec_scalar(unit_direction, -1), rec.normal), 1.0);
            double sin_theta = sqrt(1.0 - cos_theta * cos_theta);
            if (etai_over_etat * sin_theta > 1.0 || schlick(cos_theta, etai_over_etat) > random_double()) {
                t_vec3 reflected = reflect(unit_direction, rec.normal);
                scattered = (t_ray){rec.point, reflected, ray->time};
            } else {
                t_vec3 refracted = refract(unit_direction, rec.normal, etai_over_etat);
                scattered = (t_ray){rec.point, refracted, ray->time};
            }
            attenuation = rec.color;
        } else {
            return (t_color){0, 0, 0};
        }

        t_color scattered_color = ray_color(&scattered, world, lights, depth - 1);
        t_vec3 result_color = vec_add(color_to_vec3(total_light_color), vec_mul(color_to_vec3(attenuation), color_to_vec3(scattered_color)));
        return vec3_to_color(result_color);
    }

    // t_vec3 unit_direction = vec_normalize(ray->direction);
    // double t = 0.5 * (unit_direction.y + 1.0);
    // return (t_color){(1.0 - t) * 1.0 + t * 0.5, (1.0 - t) * 1.0 + t * 0.7, (1.0 - t) * 1.0 + t * 1.0};

	return (t_color){0.1, 0.1, 0.1};
}



// ピクセルカラーをスケールし、サンプルの平均を計算
t_color scale_color(t_color color, int samples_per_pixel) {
    double scale = 1.0 / samples_per_pixel;
    color.r = sqrt(scale * color.r);
    color.g = sqrt(scale * color.g);
    color.b = sqrt(scale * color.b);
    return color;
}

void render(t_data *data, t_camera *camera, t_hittable_list *world, t_light_list *lights, int samples_per_pixel, int max_depth) {
    int x, y, s;
    for (y = 0; y < WINDOW_HEIGHT; y++) {
        for (x = 0; x < WINDOW_WIDTH; x++) {
            t_color pixel_color = {0, 0, 0};
            for (s = 0; s < samples_per_pixel; s++) {
                double u = (x + random_double()) / (WINDOW_WIDTH - 1);
                double v = ((WINDOW_HEIGHT - 1 - y) + random_double()) / (WINDOW_HEIGHT - 1);
                t_ray ray = get_ray(camera, u, v);
                pixel_color = vec3_to_color(vec_add(color_to_vec3(pixel_color), color_to_vec3(ray_color(&ray, world, lights, max_depth))));
            }
            pixel_color = scale_color(pixel_color, samples_per_pixel);
            int color = vec_to_color(pixel_color);
            my_mlx_pixel_put(data, x, y, color);
        }
        print_progress(y + 1, WINDOW_HEIGHT);
    }
    printf("\n");
    mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

int main(void) {
    t_data data;
    t_hittable_list *world;
    t_light_list lights;
    int samples_per_pixel = 10;
    int max_depth = 50;
    double aspect_ratio = (double)WINDOW_WIDTH / (double)WINDOW_HEIGHT;
    double aperture = 0.1;
    double focus_dist = 10.0;
    t_camera camera = camera_new(
        vec_new(13, 2, 3), // カメラの位置
        vec_new(0, 0, 0), // カメラが向かう方向
        vec_new(0, 1, 0), // カメラのアップベクトル
        20.0, // 視野角
        aspect_ratio, // アスペクト比
        aperture, // 絞り
        focus_dist, // 焦点距離
        0.0, // シャッターの開く時間
        1.0 // シャッターの閉じる時間
    );

    init_data(&data);

    world = new_hittable_list(5); // 初期容量を5に設定
    // 地面
    add_hittable(world, new_lambertian(vec_new(0, -1000, 0), 1000, (t_color){0.5, 0.5, 0.5}));

    // 球
    add_hittable(world, new_dielectric(vec_new(0, 1, 0), 1.0, 1.5)); // 大きなガラス球
    add_hittable(world, new_lambertian(vec_new(-4, 1, 0), 1.0, (t_color){0.4, 0.9, 0.1})); // 拡散球
    add_hittable(world, new_metal(vec_new(4, 1, 0), 1.0, (t_color){0.7, 0.6, 0.5}, 0.0)); // 金属球

	add_hittable(world, new_dielectric(vec_new(0, 1, 0), -0.8, 1.5));

	//水色の球
	// add_hittable(world, new_lambertian(vec_new(0, 1, 0), 1.0, (t_color){0.1, 0.1, 0.9}));

    // 長方形
    add_hittable(world, new_rectangle(
        vec_new(-2, 0, -2), // p0
        vec_new(-2, 0, 2),  // p1
        vec_new(2, 0, 2),   // p2
        vec_new(2, 0, -2),  // p3
        vec_new(0, 1, 0),   // normal
        (t_color){0.9, 0.1, 0.1}, // color
        LAMBERTIAN // material
    ));

    // // 複数のライトを追加
    lights = new_light_list(1);
    // add_light(&lights, new_light(vec_new(5, 5, 5), (t_color){1.0, 1.0, 1.0}, 0.2));
    // add_light(&lights, new_light(vec_new(-5, 5, 5), (t_color){1.0, 1.0, 1.0}, 0.2));
    add_light(&lights, new_light(vec_new(0, 5, -5), (t_color){1, 0.1, 1}, 0.05));

    render(&data, &camera, world, &lights, samples_per_pixel, max_depth);
    wait_input(&data);

    // メモリの解放
    free(lights.lights);
    free_hittable_list(world);

    return 0;
}
