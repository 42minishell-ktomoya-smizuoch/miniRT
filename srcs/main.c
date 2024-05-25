#include "hittable.h"
#include "minirt.h"
#include "math_utils.h"
#include "metal.h"
#include "lambertian.h"
#include "dielectric.h"
#include "camera.h"

// t_color型に変換する関数
t_color vec3_to_color(t_vec3 v) {
    return (t_color){v.x, v.y, v.z};
}

// t_vec3型に変換する関数
t_vec3 color_to_vec3(t_color c) {
    return (t_vec3){c.r, c.g, c.b};
}

// レイの色を計算する関数
t_color ray_color(t_ray *ray, t_hittable_list *world, int depth) {
    t_hit_record rec;
    if (depth <= 0)
        return (t_color){0, 0, 0};

    if (hit_list(world, ray, 0.001, INFINITY, &rec)) {
        t_ray scattered;
        t_color attenuation;
        t_vec3 unit_direction = vec_normalize(ray->direction);
        double etai_over_etat = (rec.front_face) ? (1.0 / rec.ref_idx) : (rec.ref_idx);
        double cos_theta = fmin(vec_dot(vec_scalar(unit_direction, -1), rec.normal), 1.0);
        double sin_theta = sqrt(1.0 - cos_theta * cos_theta);
        if (rec.material == DIELECTRIC) {
            // 屈折と全反射
            if (etai_over_etat * sin_theta > 1.0 || schlick(cos_theta, etai_over_etat) > random_double()) {
                t_vec3 reflected = reflect(unit_direction, rec.normal);
                scattered = (t_ray){rec.point, reflected};
            } else {
                t_vec3 refracted = refract(unit_direction, rec.normal, etai_over_etat);
                scattered = (t_ray){rec.point, refracted};
            }
            attenuation = rec.color;
        } else if (rec.material == METAL) {
            // 金属反射
            t_vec3 reflected = reflect(vec_normalize(ray->direction), rec.normal);
            scattered.origin = rec.point;
            scattered.direction = vec_add(reflected, vec_scalar(random_in_unit_sphere(), rec.fuzz));
            attenuation = rec.color;
            if (vec_dot(scattered.direction, rec.normal) <= 0) {
                return (t_color){0, 0, 0};
            }
        } else {
            // ランバーティアン
            t_vec3 target = vec_add(rec.point, vec_add(rec.normal, random_unit_vector()));
            scattered.origin = rec.point;
            scattered.direction = vec_sub(target, rec.point);
            attenuation = rec.color;
        }

        t_color scattered_color = ray_color(&scattered, world, depth - 1);
        return vec3_to_color(vec_mul(color_to_vec3(attenuation), color_to_vec3(scattered_color)));
    }

    t_vec3 unit_direction = vec_normalize(ray->direction);
    double t = 0.5 * (unit_direction.y + 1.0);
    return (t_color){(1.0 - t) * 1.0 + t * 0.5, (1.0 - t) * 1.0 + t * 0.7, (1.0 - t) * 1.0 + t * 1.0};
}

// ピクセルカラーをスケールし、サンプルの平均を計算
t_color scale_color(t_color color, int samples_per_pixel) {
    double scale = 1.0 / samples_per_pixel;
    color.r = sqrt(scale * color.r);
    color.g = sqrt(scale * color.g);
    color.b = sqrt(scale * color.b);
    return color;
}

void render(t_data *data, t_camera *camera, t_hittable_list *world, int samples_per_pixel, int max_depth) {
    int x, y, s;
    for (y = 0; y < WINDOW_HEIGHT; y++) {
        for (x = 0; x < WINDOW_WIDTH; x++) {
            t_color pixel_color = {0, 0, 0};
            for (s = 0; s < samples_per_pixel; s++) {
                double u = (x + random_double()) / (WINDOW_WIDTH - 1);
                double v = ((WINDOW_HEIGHT - 1 - y) + random_double()) / (WINDOW_HEIGHT - 1);
                t_ray ray = get_ray(camera, u, v);
                pixel_color = vec3_to_color(vec_add(color_to_vec3(pixel_color), color_to_vec3(ray_color(&ray, world, max_depth))));
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
    int samples_per_pixel = 1;
    int max_depth = 50;
    double aspect_ratio = (double)WINDOW_WIDTH / (double)WINDOW_HEIGHT;
    double aperture = 0.0;
    double focus_dist = 10.0;
    t_camera camera = camera_new(
        vec_new(13, 2, 3), // カメラの位置
        vec_new(0, 0, 0), // カメラが向かう方向
        vec_new(0, 1, 0), // カメラのアップベクトル
        20.0, // 視野角
        aspect_ratio, // アスペクト比
        aperture, // 絞り
        focus_dist // 焦点距離
    );

    init_data(&data);

    world = new_hittable_list(5); // 初期容量を5に設定
    // 地面
    add_hittable(world, new_lambertian(vec_new(0, -1000, 0), 1000, (t_color){0.5, 0.5, 0.5}));

    // 球
    add_hittable(world, new_dielectric(vec_new(0, 1, 0), 1.0, 1.5)); // 大きなガラス球
    add_hittable(world, new_lambertian(vec_new(-4, 1, 0), 1.0, (t_color){0.4, 0.2, 0.1})); // 拡散球
    add_hittable(world, new_metal(vec_new(4, 1, 0), 1.0, (t_color){0.7, 0.6, 0.5}, 0.0)); // 金属球

    // // 小さな球のクラスター
    for (int a = -11; a < 11; a++) {
        for (int b = -11; b < 11; b++) {
            double choose_mat = random_double();
            t_vec3 center = vec_new(a + 0.9 * random_double(), 0.2, b + 0.9 * random_double());
            if (vec_length(vec_sub(center, vec_new(4, 0.2, 0))) > 0.9) {
                if (choose_mat < 0.8) {
                    // 拡散
                    t_color albedo = vec3_to_color(vec_mul(color_to_vec3((t_color){random_double(), random_double(), random_double()}), color_to_vec3((t_color){random_double(), random_double(), random_double()})));
                    add_hittable(world, new_lambertian(center, 0.2, albedo));
                } else if (choose_mat < 0.95) {
                    // 金属
                    t_color albedo = (t_color){0.5 * (1 + random_double()), 0.5 * (1 + random_double()), 0.5 * (1 + random_double())};
                    double fuzz = 0.5 * random_double();
                    add_hittable(world, new_metal(center, 0.2, albedo, fuzz));
                } else {
                    // ガラス
                    add_hittable(world, new_dielectric(center, 0.2, 1.5));
                }
            }
        }
    }

    render(&data, &camera, world, samples_per_pixel, max_depth);
    wait_input(&data);

    // メモリの解放
    free_hittable_list(world);

    return 0;
}
