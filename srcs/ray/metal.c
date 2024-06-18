/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   metal.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 15:34:29 by smizuoch          #+#    #+#             */
/*   Updated: 2024/06/16 21:22:46 by smizuoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "metal.h"
#include <stdlib.h>

typedef struct s_metal
{
	t_vec3	center;
	double	radius;
	t_color	color;
	double	fuzz;
}	t_metal;

typedef struct s_hit_metal
{
	t_vec3	oc;
	double	a;
	double	half_b;
	double	c;
	double	discriminant;
	double	sqrt_d;
	double	root;
	t_vec3	outward_normal;
}	t_hit_metal;

t_vec3	reflect(t_vec3 v, t_vec3 n)
{
	return (vec_sub(v, vec_scalar(n, 2 * vec_dot(v, n))));
}

int	hit_metal(t_hittable *self, t_ray *ray, t_limits l, t_hit_record *rec)
{
	t_metal		*metal;
	t_hit_metal	m;

	metal = (t_metal *)self->data;
	m.oc = vec_sub(ray->origin, metal->center);
	m.a = vec_dot(ray->direction, ray->direction);
	m.half_b = vec_dot(m.oc, ray->direction);
	m.c = vec_dot(m.oc, m.oc) - metal->radius * metal->radius;
	m.discriminant = m.half_b * m.half_b - m.a * m.c;
	if (m.discriminant < 0)
		return (0);
	m.sqrt_d = sqrt(m.discriminant);
	m.root = (-m.half_b - m.sqrt_d) / m.a;
	if (m.root < l.min || m.root > l.max)
	{
		m.root = (-m.half_b + m.sqrt_d) / m.a;
		if (m.root < l.min || m.root > l.max)
			return (0);
	}
	rec->t = m.root;
	rec->point = ray_at(*ray, rec->t);
	m.outward_normal = vec_normalize(vec_sub(rec->point, metal->center));
	set_face_normal_with_radius(rec, ray, m.outward_normal, metal->radius);
	rec->color = metal->color;
	rec->fuzz = metal->fuzz;
	rec->ref_idx = 0;
	rec->material = METAL;
	return (1);
}

t_hittable	new_metal(t_vec3 center, double radius, t_color color, double fuzz)
{
	t_metal		*metal_data;
	t_hittable	hittable_metal;

	metal_data = xmalloc(sizeof(t_metal));
	metal_data->center = center;
	metal_data->radius = radius;
	metal_data->color = color;
	metal_data->fuzz = fuzz;
	hittable_metal.data = metal_data;
	hittable_metal.hit = hit_metal;
	return (hittable_metal);
}
