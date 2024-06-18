#include "hittable.h"
#include "minirt.h"
#include "math_utils.h"
#include "metal.h"
#include "lambertian.h"
#include "dielectric.h"
#include "camera.h"
#include "rectangle.h"
#include "light.h"
#include "cylinder.h"
#include "ambient.h"
#include "plane.h"

void render(t_data *data, t_camera *camera, t_hittable_list *world, t_light_list *lights, t_ambient *ambient, int samples_per_pixel, int max_depth)
{
    int x, y, s;
    for (y = 0; y < WINDOW_HEIGHT; y++) {
        for (x = 0; x < WINDOW_WIDTH; x++) {
            t_vec3 accumulated_color = {0, 0, 0};
            for (s = 0; s < samples_per_pixel; s++) {
                double u = (x + random_double()) / (WINDOW_WIDTH - 1);
                double v = ((WINDOW_HEIGHT - 1 - y) + random_double()) / (WINDOW_HEIGHT - 1);
                t_ray ray = get_ray(camera, u, v);
                t_color sample_color = ray_color(&ray, world, lights, ambient, max_depth);
                accumulated_color = vec_add(accumulated_color, color_to_vec3(sample_color));
            }
            accumulated_color.x /= samples_per_pixel;
            accumulated_color.y /= samples_per_pixel;
            accumulated_color.z /= samples_per_pixel;

            t_color pixel_color = {
                sqrt(accumulated_color.x),
                sqrt(accumulated_color.y),
                sqrt(accumulated_color.z)
            };
            int color = vec_to_color(pixel_color);
            my_mlx_pixel_put(data, x, y, color);
        }
        print_progress(y + 1, WINDOW_HEIGHT);
    }
    printf("Rendering complete!\n");
    mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}