/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lambertian.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 16:16:12 by smizuoch          #+#    #+#             */
/*   Updated: 2024/06/19 15:56:45 by smizuoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lambertian.h"
#include <stdlib.h>

typedef struct s_lambertian
{
	t_vec3	center;
	double	radius;
	t_color	color;
}	t_lambertian;

typedef struct s_hit_lambertian
{
	double	a;
	double	half_b;
	double	c;
	double	discriminant;
	double	sqrt_d;
	double	root;
}	t_hit_lambertian;

static int	calculate_discriminant(t_lambertian *lambertian, t_ray *ray,
								t_limits l, t_hit_lambertian *h)
{
	t_vec3	oc;

	oc = vec_sub(ray->origin, lambertian->center);
	h->a = vec_dot(ray->direction, ray->direction);
	h->half_b = vec_dot(oc, ray->direction);
	h->c = vec_dot(oc, oc) - lambertian->radius * lambertian->radius;
	h->discriminant = h->half_b * h->half_b - h->a * h->c;
	if (h->discriminant < 0)
		return (0);
	h->sqrt_d = sqrt(h->discriminant);
	h->root = (-h->half_b - h->sqrt_d) / h->a;
	if (h->root < l.min || h->root > l.max)
	{
		h->root = (-h->half_b + h->sqrt_d) / h->a;
		if (h->root < l.min || h->root > l.max)
			return (0);
	}
	return (1);
}

static void	fill_hit_record(t_hit_record *rec, t_hit_lambertian *h,
							t_lambertian *lambertian, t_ray *ray)
{
	t_vec3	outward_normal;

	rec->t = h->root;
	rec->point = ray_at(*ray, rec->t);
	outward_normal = vec_normalize(vec_sub(rec->point, lambertian->center));
	set_face_normal_with_radius(rec, ray, outward_normal, lambertian->radius);
	rec->color = lambertian->color;
	rec->fuzz = 0;
	rec->ref_idx = 0;
	rec->material = LAMBERTIAN;
}

int	hit_lambertian(t_hittable *self, t_ray *ray, t_limits l, t_hit_record *rec)
{
	t_lambertian		*lambertian;
	t_hit_lambertian	h;

	lambertian = (t_lambertian *)self->data;
	if (!calculate_discriminant(lambertian, ray, l, &h))
		return (0);
	fill_hit_record(rec, &h, lambertian, ray);
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
