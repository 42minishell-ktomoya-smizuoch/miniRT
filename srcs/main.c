#include "../includes/minirt.h"
#include "../includes/hittable.h"

int hit_list(t_hittable_list *list, t_ray *ray, double t_min, double t_max, t_hit_record *rec);

// 球のヒット関数
int hit_sphere(t_hittable *self, t_ray *ray, double t_min, double t_max, t_hit_record *rec)
{
	t_sphere *sphere = (t_sphere *)self->data;
	t_vec3 oc = vec_sub(ray->origin, sphere->center);
	double a = vec_dot(ray->direction, ray->direction);
	double half_b = vec_dot(oc, ray->direction);
	double c = vec_dot(oc, oc) - sphere->radius * sphere->radius;
	double discriminant = half_b * half_b - a * c;

	if (discriminant < 0)
		return 0;

	double sqrt_d = sqrt(discriminant);
	double root = (-half_b - sqrt_d) / a;

	if (root < t_min || root > t_max)
	{
		root = (-half_b + sqrt_d) / a;
		if (root < t_min || root > t_max)
			return 0;
	}

	rec->t = root;
	rec->point = ray_at(*ray, rec->t);
	t_vec3 outward_normal = vec_normalize(vec_sub(rec->point, sphere->center));
	set_face_normal(rec, ray, outward_normal);
	rec->color = sphere->color;

	return 1;
}

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

// 球の初期化関数
t_hittable new_sphere(t_vec3 center, double radius, t_color color)
{
    t_sphere *sphere_data = malloc(sizeof(t_sphere));
    sphere_data->center = center;
    sphere_data->radius = radius;
    sphere_data->color = color;

    t_hittable hittable_sphere;
    hittable_sphere.data = sphere_data;
    hittable_sphere.hit = hit_sphere;

    return hittable_sphere;
}

t_hittable_list *new_hittable_list(int initial_capacity)
{
    t_hittable_list *list = malloc(sizeof(t_hittable_list));
    list->objects = malloc(sizeof(t_hittable) * initial_capacity);
    list->size = 0;
    list->capacity = initial_capacity;
    return list;
}

void add_hittable(t_hittable_list *list, t_hittable object)
{
    if (list->size == list->capacity) {
        list->capacity *= 2;
        list->objects = realloc(list->objects, sizeof(t_hittable) * list->capacity);
    }
    list->objects[list->size++] = object;
}

int hit_list(t_hittable_list *list, t_ray *ray, double t_min, double t_max, t_hit_record *rec)
{
    t_hit_record temp_rec;
    int hit_anything = 0;
    double closest_so_far = t_max;

    for (int i = 0; i < list->size; i++) {
        if (list->objects[i].hit(&list->objects[i], ray, t_min, closest_so_far, &temp_rec)) {
            hit_anything = 1;
            closest_so_far = temp_rec.t;
            *rec = temp_rec;
        }
    }

    return hit_anything;
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

    world = new_hittable_list(1);
    add_hittable(world, new_sphere(vec_new(0, 0, -1), 0.5, (t_color){1, 0, 0}));

    render(&data, &camera, world);
    wait_input(&data);

    free(world->objects);
    free(world);

    return 0;
}
