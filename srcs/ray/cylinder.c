/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 21:25:56 by smizuoch          #+#    #+#             */
/*   Updated: 2024/06/21 13:57:17 by smizuoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cylinder.h"
#include <math.h>
#include <stdlib.h>

typedef struct s_cup
{
	double	min;
	double	max;
	t_vec3	cap_center;
}	t_cup;

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

static int	hit_cylinder_side_and_caps(t_cylinder *cyl, t_ray *ray, t_limits *c,
									t_hit_record *rec)
{
	t_hit_record	temp_rec;
	int				hit_anything;

	hit_anything = 0;
	if (hit_cylinder_side(cyl, ray, *c, &temp_rec))
	{
		hit_anything = 1;
		c->max = temp_rec.t;
		*rec = temp_rec;
	}
	if (hit_cylinder_cap(cyl, ray, &temp_rec, init_cup(c->min, c->max,
				vec_add(cyl->center, vec_scalar(cyl->axisnorm, 0)))))
	{
		hit_anything = 1;
		c->max = temp_rec.t;
		*rec = temp_rec;
	}
	if (hit_cylinder_cap(cyl, ray, &temp_rec, init_cup(c->min, c->max,
				vec_add(cyl->center, vec_scalar(cyl->axisnorm, cyl->height)))))
	{
		hit_anything = 1;
		c->max = temp_rec.t;
		*rec = temp_rec;
	}
	return (hit_anything);
}

int	hit_cylinder(t_hittable *self, t_ray *ray, t_limits l, t_hit_record *rec)
{
	t_cylinder	*cyl;
	t_limits	c;

	cyl = (t_cylinder *)self->data;
	c.max = l.max;
	c.min = l.min;
	return (hit_cylinder_side_and_caps(cyl, ray, &c, rec));
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
