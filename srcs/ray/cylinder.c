/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 21:25:56 by smizuoch          #+#    #+#             */
/*   Updated: 2024/06/18 15:20:05 by smizuoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cylinder.h"
#include <math.h>
#include <stdlib.h>

typedef struct s_side
{
	t_vec3	oc;
	t_vec3	axis;
	double	a;
	double	half_b;
	double	c;
	double	discriminant;
	double	sqrt_d;
	double	root;
	t_vec3	point;
	t_vec3	relative_point;
	double	height_along_axis;
}	t_side;

typedef struct s_cup
{
	double	min;
	double	max;
	t_vec3	cap_center;
}	t_cup;

int	hit_cylinder_side(t_cylinder *cyl,
	t_ray *ray, t_limits l, t_hit_record *rec)
{
	t_side	s;

	s.oc = vec_sub(ray->origin, cyl->center);
	s.axis = vec_normalize(cyl->axisnorm);
	s.a = vec_dot(ray->direction, ray->direction)
		- pow(vec_dot(ray->direction, s.axis), 2);
	s.half_b = vec_dot(s.oc, ray->direction)
		- vec_dot(s.oc, s.axis) * vec_dot(ray->direction, s.axis);
	s.c = vec_dot(s.oc, s.oc)
		- pow(vec_dot(s.oc, s.axis), 2) - pow(cyl->diameter / 2, 2);
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
	s.point = ray_at(*ray, s.root);
	s.relative_point = vec_sub(s.point, cyl->center);
	s.height_along_axis = vec_dot(s.relative_point, s.axis);
	if (s.height_along_axis < 0 || s.height_along_axis > cyl->height)
		return (0);
	rec->t = s.root;
	rec->point = s.point;
	rec->normal = vec_normalize(vec_sub(vec_sub(s.point, cyl->center),
				vec_scalar(s.axis, vec_dot(vec_sub(s.point,
							cyl->center), s.axis))));
	rec->front_face = vec_dot(ray->direction, rec->normal) < 0;
	rec->color = cyl->color;
	rec->material = cyl->material;
	return (1);
}

int	hit_cylinder_cap(t_cylinder *cyl, t_ray *ray, t_hit_record *rec, t_cup c)
{
	t_vec3	axis;
	double	denom;
	double	t;
	t_vec3	point;
	t_vec3	d;

	axis = vec_normalize(cyl->axisnorm);
	denom = vec_dot(ray->direction, axis);
	if (fabs(denom) < 1e-6)
		return (0);
	t = vec_dot(vec_sub(c.cap_center, ray->origin), axis) / denom;
	if (t < c.min || t > c.max)
		return (0);
	point = ray_at(*ray, t);
	d = vec_sub(point, c.cap_center);
	if (vec_dot(d, d) > (cyl->diameter / 2) * (cyl->diameter / 2))
		return (0);
	rec->t = t;
	rec->point = point;
	rec->normal = axis;
	rec->front_face = vec_dot(ray->direction, rec->normal) < 0;
	rec->color = cyl->color;
	rec->material = cyl->material;
	return (1);
}

t_cup	init_cup(double min, double max, t_vec3 cap_center)
{
	t_cup	cup;

	cup.min = min;
	cup.max = max;
	cup.cap_center = cap_center;
	return (cup);
}

int	hit_cylinder(t_hittable *self, t_ray *ray, t_limits l, t_hit_record *rec)
{
	t_cylinder		*cyl;
	t_hit_record	temp_rec;
	int				hit_anything;
	t_limits		c;

	cyl = (t_cylinder *)self->data;
	hit_anything = 0;
	c.max = l.max;
	c.min = l.min;
	if (hit_cylinder_side(cyl, ray, c, &temp_rec))
	{
		hit_anything = 1;
		l.max = temp_rec.t;
		*rec = temp_rec;
	}
	if (hit_cylinder_cap(cyl, ray, &temp_rec, init_cup(c.min, c.max,
				vec_add(cyl->center, vec_scalar(cyl->axisnorm, 0)))))
	{
		hit_anything = 1;
		c.max = temp_rec.t;
		*rec = temp_rec;
	}
	if (hit_cylinder_cap(cyl, ray, &temp_rec, init_cup(c.min, c.max,
				vec_add(cyl->center, vec_scalar(cyl->axisnorm, cyl->height)))))
	{
		hit_anything = 1;
		c.max = temp_rec.t;
		*rec = temp_rec;
	}
	return (hit_anything);
}

t_hittable	new_cylinder(t_cylinder c)
{
	t_cylinder	*cyl_data;
	t_hittable	hittable_cylinder;

	cyl_data = xmalloc(sizeof(t_cylinder));
	cyl_data->center = c.center;
	cyl_data->axisnorm = vec_normalize(c.axisnorm);
	cyl_data->diameter = c.diameter;
	cyl_data->height = c.height;
	cyl_data->color = c.color;
	cyl_data->material = c.material;
	hittable_cylinder.data = cyl_data;
	hittable_cylinder.hit = hit_cylinder;
	return (hittable_cylinder);
}
