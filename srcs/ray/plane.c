/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 16:09:40 by smizuoch          #+#    #+#             */
/*   Updated: 2024/06/16 16:15:05 by smizuoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "plane.h"
#include <stdlib.h>

int	hit_plane(t_hittable *self, t_ray *ray, t_limits l, t_hit_record *rec)
{
	t_plane	*pl;
	double	denom;
	double	t;

	pl = (t_plane *)self->data;
	denom = vec_dot(pl->normal, ray->direction);
	if (fabs(denom) > 1e-6)
	{
		t = vec_dot(vec_sub(pl->point, ray->origin), pl->normal) / denom;
		if (t < l.min || t > l.max)
			return (0);
		rec->t = t;
		rec->point = ray_at(*ray, t);
		rec->normal = pl->normal;
		rec->front_face = vec_dot(ray->direction, rec->normal) < 0;
		rec->color = pl->color;
		rec->material = pl->material;
		return (1);
	}
	return (0);
}

t_hittable	new_plane(t_vec3 point, t_vec3 normal, t_color color,
			t_material_type material)
{
	t_plane		*pl_data;
	t_hittable	hittable_plane;

	pl_data = xmalloc(sizeof(t_plane));
	pl_data->point = point;
	pl_data->normal = vec_normalize(normal);
	pl_data->color = color;
	pl_data->material = material;
	hittable_plane.data = pl_data;
	hittable_plane.hit = hit_plane;
	return (hittable_plane);
}
