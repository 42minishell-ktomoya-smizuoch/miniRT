/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 12:29:33 by smizuoch          #+#    #+#             */
/*   Updated: 2024/06/16 16:11:33 by smizuoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hittable.h"

int	hit_sphere(t_hittable *self, t_ray *ray, t_limits l, t_hit_record *rec)
{
	t_sphere	*sphere;
	t_vec3		oc;
	double		a;
	double		half_b;
	double		c;
	double		discriminant;
	double		sqrt_d;
	double		root;
	t_vec3		outward_normal;

	sphere = (t_sphere *)self->data;
	oc = vec_sub(ray->origin, sphere->center);
	a = vec_dot(ray->direction, ray->direction);
	half_b = vec_dot(oc, ray->direction);
	c = vec_dot(oc, oc) - sphere->radius * sphere->radius;
	discriminant = half_b * half_b - a * c;
	if (discriminant < 0)
		return (0);
	sqrt_d = sqrt(discriminant);
	root = (-half_b - sqrt_d) / a;
	if (root < l.min || root > l.max)
	{
		root = (-half_b + sqrt_d) / a;
		if (root < l.min || root > l.max)
			return (0);
	}
	rec->t = root;
	rec->point = ray_at(*ray, rec->t);
	outward_normal = vec_normalize(vec_sub(rec->point, sphere->center));
	set_face_normal(rec, ray, outward_normal);
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