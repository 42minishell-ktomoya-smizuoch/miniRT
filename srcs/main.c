#include "../includes/minirt.h"

int hit_sphere(t_ray *ray, t_sphere *sphere, double *t)
{
    t_vec3 oc = vec_sub(ray->origin, sphere->center);
    double a = vec_dot(ray->direction, ray->direction);
    double half_b = vec_dot(oc, ray->direction);
    double c = vec_dot(oc, oc) - sphere->radius * sphere->radius;
    double discriminant = half_b * half_b - a * c;
    if (discriminant < 0)
    {
        return 0;
    }
    else
    {
        *t = (-half_b - sqrt(discriminant)) / a;
        return 1;
    }
}


t_color ray_color(t_ray *ray, t_sphere *sphere)
{
    double t;
    if (hit_sphere(ray, sphere, &t))
    {
        t_vec3 hit_point = ray_at(*ray, t);
        t_vec3 normal = vec_normalize(vec_sub(hit_point, sphere->center));
        return (t_color){(normal.x + 1) * 0.5, (normal.y + 1) * 0.5, (normal.z + 1) * 0.5};
    }
    t_vec3 unit_direction = vec_normalize(ray->direction);
    t = 0.5 * (unit_direction.y + 1.0);
    return (t_color){(1.0 - t) * 1.0 + t * 0.5, (1.0 - t) * 1.0 + t * 0.7, (1.0 - t) * 1.0 + t * 1.0};
}

void render(t_data *data, t_camera *camera, t_sphere *sphere)
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
            double v = (double)(WINDOW_HEIGHT - 1 - y) / (double)(WINDOW_HEIGHT - 1);  // yを逆にする

            t_ray ray;
            ray.origin = camera->origin;
            ray.direction = vec_sub(vec_add(vec_add(lower_left_corner, vec_scalar(horizontal, u)), vec_scalar(vertical, v)), camera->origin);

            t_color pixel_color = ray_color(&ray, sphere);
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
    t_sphere sphere;

    init_data(&data);
    camera.origin = vec_new(0, 0, 0);
    sphere.center = vec_new(0, 0, -1);
    sphere.radius = 0.5;
    sphere.color = (t_color){1, 0, 0};

    render(&data, &camera, &sphere);
    wait_input(&data);

    return 0;
}
