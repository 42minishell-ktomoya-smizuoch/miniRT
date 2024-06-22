/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 12:29:33 by smizuoch          #+#    #+#             */
/*   Updated: 2024/06/16 20:57:44 by smizuoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hittable.h"

typedef struct s_hit_sphere
{
	t_vec3		oc;
	double		a;
	double		half_b;
	double		c;
	double		discriminant;
	double		sqrt_d;
	double		root;
	t_vec3		outward_normal;
}	t_hit_sphere;

int	hit_sphere(t_hittable *self, t_ray *ray, t_limits l, t_hit_record *rec)
{
	t_sphere		*sphere;
	t_hit_sphere	s;

	sphere = (t_sphere *)self->data;
	s.oc = vec_sub(ray->origin, sphere->center);
	s.a = vec_dot(ray->direction, ray->direction);
	s.half_b = vec_dot(s.oc, ray->direction);
	s.c = vec_dot(s.oc, s.oc) - sphere->radius * sphere->radius;
	s.discriminant = s.half_b * s.half_b - s.a * s.c;
	if (s.discriminant < 0)
		return (0);
	s.sqrt_d = sqrt(s.discriminant);
	s.root = (-s.half_b - s.sqrt_d) / s.a;
	if (s.root < l.min || s.root > l.max)
	{
		s.root = (-s.half_b + s.sqrt_d) / s.a;
		if (s.root < l.min || s.root > l.max)
			return (0);
	}
	rec->t = s.root;
	rec->point = ray_at(*ray, rec->t);
	s.outward_normal = vec_normalize(vec_sub(rec->point, sphere->center));
	set_face_normal(rec, ray, s.outward_normal);
	rec->color = sphere->color;
	return (1);
}

t_hittable	new_sphere(t_vec3 center, double radius, t_color color)
{
	t_sphere	*sphere_data;
	t_hittable	hittable_sphere;

	sphere_data = xmalloc(sizeof(t_sphere));
	sphere_data->center = center;
	sphere_data->radius = radius;
	sphere_data->color = color;
	hittable_sphere.data = sphere_data;
	hittable_sphere.hit = hit_sphere;
	return (hittable_sphere);
}
