#include "lambertian.h"
#include <stdlib.h>

typedef struct s_lambertian
{
    t_vec3	center;
    double	radius;
    t_color	color;
}	t_lambertian;


int	hit_lambertian(t_hittable *self, t_ray *ray, double t_min, double t_max, t_hit_record *rec)
{
	t_lambertian	*lambertian;
	t_vec3			oc;
	double			a;
	double			half_b;
	double			c;
	double			discriminant;
	double			sqrt_d;
	double			root;
	t_vec3			outward_normal;

	lambertian = (t_lambertian *)self->data;
	oc = vec_sub(ray->origin, lambertian->center);
	a = vec_dot(ray->direction, ray->direction);
	half_b = vec_dot(oc, ray->direction);
	c = vec_dot(oc, oc) - lambertian->radius * lambertian->radius;
	discriminant = half_b * half_b - a * c;
	if (discriminant < 0)
		return (0);
	sqrt_d = sqrt(discriminant);
	root = (-half_b - sqrt_d) / a;
	if (root < t_min || root > t_max)
	{
		root = (-half_b + sqrt_d) / a;
		if (root < t_min || root > t_max)
			return (0);
	}
	rec->t = root;
	rec->point = ray_at(*ray, rec->t);
	outward_normal = vec_normalize(vec_sub(rec->point, lambertian->center));
	set_face_normal_with_radius(rec, ray, outward_normal, lambertian->radius);
	rec->color = lambertian->color;
	rec->fuzz = 0;
	rec->ref_idx = 0;
	rec->material = LAMBERTIAN;
	return (1);
}

t_hittable	new_lambertian(t_vec3 center, double radius, t_color color)
{
	t_lambertian	*lambertian_data;
	t_hittable		hittable_lambertian;

	lambertian_data = xmalloc(sizeof(t_lambertian));
	lambertian_data->center = center;
	lambertian_data->radius = radius;
	lambertian_data->color = color;
	hittable_lambertian.data = lambertian_data;
	hittable_lambertian.hit = hit_lambertian;
	return (hittable_lambertian);
}
