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

t_ray_color init_ray_color(t_data *data)
{
	t_ray_color	r;

	r.world = data->world;
	r.lights = &data->lights;
	r.ambient = &data->ambient;
	r.depth = data->max_depth;
	return (r);
}

void render(t_data *data)
{
    int x, y, s;
    for (y = 0; y < WINDOW_HEIGHT; y++) {
        for (x = 0; x < WINDOW_WIDTH; x++) {
            t_vec3 accumulated_color = {0, 0, 0};
            for (s = 0; s < data->samples_per_pixel; s++) {
                double u = (x + random_double()) / (WINDOW_WIDTH - 1);
                double v = ((WINDOW_HEIGHT - 1 - y) + random_double()) / (WINDOW_HEIGHT - 1);
                t_ray ray = get_ray(&data->camera, u, v);
                t_color sample_color = ray_color(&ray, init_ray_color(data));
                accumulated_color = vec_add(accumulated_color, color_to_vec3(sample_color));
            }
            accumulated_color.x /= data->samples_per_pixel;
            accumulated_color.y /= data->samples_per_pixel;
            accumulated_color.z /= data->samples_per_pixel;

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