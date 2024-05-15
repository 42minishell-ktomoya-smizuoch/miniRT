/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hittable.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 09:10:40 by smizuoch          #+#    #+#             */
/*   Updated: 2024/05/15 09:12:19 by smizuoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HITTABLE_H
# define HITTABLE_H

# include "minirt.h"

// ヒット情報を格納する構造体
typedef struct s_hit_record
{
	t_vec3	point;
	t_vec3	normal;
	double	t;
	int		front_face;
	t_color	color;
}	t_hit_record;

struct		s_hittable;
typedef int	(*t_hit_fn)(struct s_hittable *,
	t_ray *, double, double, t_hit_record *);

// ヒッタブル構造体
typedef struct s_hittable
{
	void		*data;
	t_hit_fn	hit;
}	t_hittable;

typedef struct s_hittable_list
{
	t_hittable	*objects;
	int			size;
	int			capacity;
}	t_hittable_list;

void	set_face_normal(t_hit_record *rec, t_ray *r, t_vec3 outward_normal)
{
	rec->front_face = (vec_dot(r->direction, outward_normal) < 0);
	if (rec->front_face)
		rec->normal = outward_normal;
	else
		rec->normal = vec_scalar(outward_normal, -1);
}

#endif
