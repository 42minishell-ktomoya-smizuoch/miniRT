#include "hittable.h"
#include "math_utils.h"
#include "minirt.h"

// t_color型に変換する関数
t_color	vec3_to_color(t_vec3 v)
{
    return ((t_color){v.x, v.y, v.z});
}

// レイの色を計算する関数
t_color ray_color(t_ray *ray, t_hittable_list *world)
{
    t_hit_record rec;
    if (hit_list(world, ray, 0.001, INFINITY, &rec))
    {
        // 法線ベクトルに基づいた色を返す
        return vec3_to_color(vec_scalar(vec_add(rec.normal, vec_new(1, 1, 1)), 0.5));
    }
    t_vec3 unit_direction = vec_normalize(ray->direction);
    double t = 0.5 * (unit_direction.y + 1.0);
    return (t_color){(1.0 - t) * 1.0 + t * 0.5, (1.0 - t) * 1.0 + t * 0.7, (1.0 - t) * 1.0 + t * 1.0};
}

void render(t_data *data, t_camera *camera, t_hittable_list *world)
{
    int x, y;
    double viewport_height = 2.0;
    double viewport_width = (double)WINDOW_WIDTH / (double)WINDOW_HEIGHT * viewport_height;
    double focal_length = 1.0;

    t_vec3 horizontal = vec_new(viewport_width, 0.0, 0.0);
    t_vec3 vertical = vec_new(0.0, viewport_height, 0.0);
    t_vec3 lower_left_corner = vec_sub(vec_sub(vec_sub(camera->origin, vec_scalar(horizontal, 0.5)), vec_scalar(vertical, 0.5)), vec_new(0.0, 0.0, focal_length));

    for (y = 0; y < WINDOW_HEIGHT; y++)
    {
        for (x = 0; x < WINDOW_WIDTH; x++)
        {
            double u = (double)x / (double)(WINDOW_WIDTH - 1);
            double v = (double)(WINDOW_HEIGHT - 1 - y) / (double)(WINDOW_HEIGHT - 1);

            t_ray ray;
            ray.origin = camera->origin;
            ray.direction = vec_sub(vec_add(vec_add(lower_left_corner, vec_scalar(horizontal, u)), vec_scalar(vertical, v)), camera->origin);

            t_color pixel_color = ray_color(&ray, world);
            int color = vec_to_color(pixel_color);
            my_mlx_pixel_put(data, x, y, color);
        }
    }
    mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

int main(void)
{
    t_data data;
    t_camera camera;
    t_hittable_list *world;

    init_data(&data);
    camera.origin = vec_new(0, 0, 0);

    world = new_hittable_list(2); // 初期容量を2に設定
    add_hittable(world, new_sphere(vec_new(0, 0, -1), 0.5, (t_color){1, 0, 0}));
    add_hittable(world, new_sphere(vec_new(0, -100.5, -1), 100, (t_color){0.8, 0.8, 0.0})); // 地面の球

    render(&data, &camera, world);
    wait_input(&data);

    // メモリの解放
    free_hittable_list(world);
    return 0;
}
