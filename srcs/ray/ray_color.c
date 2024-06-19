/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 18:11:39 by smizuoch          #+#    #+#             */
/*   Updated: 2024/06/19 14:59:11 by smizuoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

typedef struct s_compute_lighting
{
	t_color	total_light_color;
	int		i;
	t_light	*light;
	t_vec3	light_dir;
	double	light_intensity;
	t_vec3	light_color_vec;
	t_color	light_color;
}	t_compute_lighting;

typedef struct s_scatter_dielectric
{
	double	etai_over_etat;
	t_vec3	unit_direction;
	double	cos_theta;
	double	sin_theta;
	t_vec3	reflected;
	t_vec3	refracted;
}	t_scatter_dielectric;

static t_color	compute_lighting(t_ray_color r, t_hit_record *rec)
{
	t_compute_lighting	c;

	c.total_light_color = vec3_to_color(vec_scalar(
				color_to_vec3(r.ambient->color), r.ambient->ratio));
	c.i = 0;
	while (c.i < r.lights->count)
	{
		c.light = &r.lights->lights[c.i];
		c.light_dir = vec_normalize(vec_sub(c.light->position, rec->point));
		c.light_intensity = c.light->intensity
			* fmax(0.0, vec_dot(rec->normal, c.light_dir));
		c.light_color_vec = vec_scalar
			(color_to_vec3(c.light->color), c.light_intensity);
		c.light_color = vec3_to_color(c.light_color_vec);
		c.total_light_color = vec3_to_color(vec_add(
					color_to_vec3(c.total_light_color),
					color_to_vec3(c.light_color)));
		c.i++;
	}
	return (c.total_light_color);
}

static void	scatter_ray(t_hit_record *rec, t_ray *ray, t_ray *scattered,
						t_color *attenuation)
{
	t_vec3	target;
	t_vec3	reflected;

	if (rec->material == LAMBERTIAN)
	{
		target = vec_add(rec->point,
				vec_add(rec->normal, random_unit_vector()));
		*scattered = (t_ray){rec->point,
			vec_sub(target, rec->point), ray->time};
		*attenuation = rec->color;
	}
	else if (rec->material == METAL)
	{
		reflected = reflect(vec_normalize(ray->direction), rec->normal);
		*scattered = (t_ray){rec->point, vec_add(reflected,
				vec_scalar(random_in_unit_sphere(), rec->fuzz)), ray->time};
		*attenuation = rec->color;
	}
}

static void	scatter_dielectric(t_hit_record *rec, t_ray *ray, t_ray *scattered,
							t_color *attenuation)
{
	t_scatter_dielectric	s;

	if (rec->front_face)
		s.etai_over_etat = 1.0 / rec->ref_idx;
	else
		s.etai_over_etat = rec->ref_idx;
	s.unit_direction = vec_normalize(ray->direction);
	s.cos_theta = fmin(vec_dot
			(vec_scalar(s.unit_direction, -1), rec->normal), 1.0);
	s.sin_theta = sqrt(1.0 - s.cos_theta * s.cos_theta);
	if (s.etai_over_etat * s.sin_theta > 1.0 || schlick
		(s.cos_theta, s.etai_over_etat) > random_double())
	{
		s.reflected = reflect(s.unit_direction, rec->normal);
		*scattered = (t_ray){rec->point, s.reflected, ray->time};
	}
	else
	{
		s.refracted = refract(s.unit_direction, rec->normal, s.etai_over_etat);
		*scattered = (t_ray){rec->point, s.refracted, ray->time};
	}
	*attenuation = rec->color;
}

t_color	ray_color(t_ray *ray, t_ray_color r)
{
	t_hit_record	rec;
	t_limits		l;
	t_ray			scattered;
	t_color			attenuation;
	t_color			total_light_color;
	t_color			scattered_color;
	t_vec3			result_color;

	l.min = 0.001;
	l.max = INFINITY;
	if (r.depth <= 0)
		return ((t_color){0, 0, 0});
	if (hit_list(r.world, ray, l, &rec))
	{
		total_light_color = compute_lighting(r, &rec);
		if (rec.material == DIELECTRIC)
			scatter_dielectric(&rec, ray, &scattered, &attenuation);
		else
			scatter_ray(&rec, ray, &scattered, &attenuation);
		r.depth -= 1;
		scattered_color = ray_color(&scattered, r);
		result_color = vec_add(color_to_vec3(total_light_color),
			vec_mul(color_to_vec3(attenuation), color_to_vec3(scattered_color)));
		return (vec3_to_color(result_color));
	}
	return (vec3_to_color(vec_scalar(color_to_vec3(r.ambient->color), r.ambient->ratio)));
}
