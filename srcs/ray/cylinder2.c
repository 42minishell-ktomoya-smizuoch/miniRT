/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 16:24:07 by smizuoch          #+#    #+#             */
/*   Updated: 2024/06/21 13:57:56 by smizuoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cylinder.h"
#include <math.h>
#include <stdlib.h>

static int	calculate_cylinder_intersection(t_cylinder *cyl, t_ray *ray,
											t_limits l, t_side *s)
{
	s->oc = vec_sub(ray->origin, cyl->center);
	s->axis = vec_normalize(cyl->axisnorm);
	s->a = vec_dot(ray->direction, ray->direction)
		- pow(vec_dot(ray->direction, s->axis), 2);
	s->half_b = vec_dot(s->oc, ray->direction)
		- vec_dot(s->oc, s->axis) * vec_dot(ray->direction, s->axis);
	s->c = vec_dot(s->oc, s->oc)
		- pow(vec_dot(s->oc, s->axis), 2) - pow(cyl->diameter / 2, 2);
	s->discriminant = s->half_b * s->half_b - s->a * s->c;
	if (s->discriminant < 0)
		return (0);
	s->sqrt_d = sqrt(s->discriminant);
	s->root = (-s->half_b - s->sqrt_d) / s->a;
	if (s->root < l.min || s->root > l.max)
	{
		s->root = (-s->half_b + s->sqrt_d) / s->a;
		if (s->root < l.min || s->root > l.max)
			return (0);
	}
	return (1);
}

static int	check_cylinder_side(t_cylinder *cyl, t_ray *ray, t_side *s,
								t_hit_record *rec)
{
	s->point = ray_at(*ray, s->root);
	s->relative_point = vec_sub(s->point, cyl->center);
	s->height_along_axis = vec_dot(s->relative_point, s->axis);
	if (s->height_along_axis < 0 || s->height_along_axis > cyl->height)
		return (0);
	rec->t = s->root;
	rec->point = s->point;
	rec->normal = vec_normalize(vec_sub(vec_sub(s->point, cyl->center),
				vec_scalar(s->axis, vec_dot
					(vec_sub(s->point, cyl->center), s->axis))));
	rec->front_face = vec_dot(ray->direction, rec->normal) < 0;
	rec->color = cyl->color;
	rec->material = cyl->material;
	return (1);
}

int	hit_cylinder_side(t_cylinder *cyl,
	t_ray *ray, t_limits l, t_hit_record *rec)
{
	t_side	s;

	if (!calculate_cylinder_intersection(cyl, ray, l, &s))
		return (0);
	return (check_cylinder_side(cyl, ray, &s, rec));
}
