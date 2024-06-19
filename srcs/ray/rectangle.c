/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rectangle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 15:45:24 by smizuoch          #+#    #+#             */
/*   Updated: 2024/06/19 15:14:43 by smizuoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rectangle.h"
#include <stdlib.h>

typedef struct s_hit_rectangle
{
	double		t;
	t_vec3		p;
	t_vec3		c0;
	t_vec3		c1;
	t_vec3		c;
	double		dot00;
	double		dot01;
	double		dot02;
	double		dot11;
	double		dot12;
	double		inv_denom;
	double		u;
	double		v;
}	t_hit_rectangle;

static int	check_intersection(t_rectangle *rect, t_ray *ray, t_limits l,
							t_hit_rectangle *r)
{
	r->t = vec_dot(vec_sub(rect->p0, ray->origin), rect->normal)
		/ vec_dot(ray->direction, rect->normal);
	if (r->t < l.min || r->t > l.max)
		return (0);
	r->p = ray_at(*ray, r->t);
	r->c0 = vec_sub(rect->p1, rect->p0);
	r->c1 = vec_sub(rect->p3, rect->p0);
	r->c = vec_sub(r->p, rect->p0);
	r->dot00 = vec_dot(r->c0, r->c0);
	r->dot01 = vec_dot(r->c0, r->c1);
	r->dot02 = vec_dot(r->c0, r->c);
	r->dot11 = vec_dot(r->c1, r->c1);
	r->dot12 = vec_dot(r->c1, r->c);
	r->inv_denom = 1.0 / (r->dot00 * r->dot11 - r->dot01 * r->dot01);
	r->u = (r->dot11 * r->dot02 - r->dot01 * r->dot12) * r->inv_denom;
	r->v = (r->dot00 * r->dot12 - r->dot01 * r->dot02) * r->inv_denom;
	if (r->u < 0 || r->u > 1 || r->v < 0 || r->v > 1)
		return (0);
	return (1);
}

static void	fill_hit_record(t_hit_record *rec,
		t_hit_rectangle *r, t_rectangle *rect, t_ray *ray)
{
	rec->t = r->t;
	rec->point = r->p;
	rec->normal = rect->normal;
	rec->front_face = vec_dot(ray->direction, rect->normal) < 0;
	rec->color = rect->color;
	rec->material = rect->material;
}

int	hit_rectangle(t_hittable *self, t_ray *ray, t_limits l, t_hit_record *rec)
{
	t_rectangle		*rect;
	t_hit_rectangle	r;

	rect = (t_rectangle *)self->data;
	if (!check_intersection(rect, ray, l, &r))
		return (0);
	fill_hit_record(rec, &r, rect, ray);
	return (1);
}

t_hittable	new_rectangle(t_rectangle r)
{
	t_rectangle	*rect_data;
	t_hittable	hittable_rect;

	rect_data = xmalloc(sizeof(t_rectangle));
	rect_data->p0 = r.p0;
	rect_data->p1 = r.p1;
	rect_data->p2 = r.p2;
	rect_data->p3 = r.p3;
	rect_data->normal = r.normal;
	rect_data->color = r.color;
	rect_data->material = r.material;
	hittable_rect.data = rect_data;
	hittable_rect.hit = hit_rectangle;
	return (hittable_rect);
}
