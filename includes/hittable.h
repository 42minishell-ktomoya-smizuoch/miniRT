/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hittable.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 09:10:40 by smizuoch          #+#    #+#             */
/*   Updated: 2024/06/18 14:33:24 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HITTABLE_H
# define HITTABLE_H

# include "minirt.h"

void			set_face_normal(t_hit_record *rec,
					t_ray *r, t_vec3 outward_normal);
void			set_face_normal_with_radius(t_hit_record *rec,
					t_ray *r, t_vec3 outward_normal, double radius);
t_hittable_list	*new_hittable_list(int initial_capacity);
void			add_hittable(t_hittable_list *list, t_hittable object);
int				hit_list(t_hittable_list *list,
					t_ray *ray, t_limits limit, t_hit_record *rec);
void			free_hittable_list(t_hittable_list *list);

int				hit_sphere(t_hittable *self,
					t_ray *ray, t_limits l, t_hit_record *rec);
t_hittable		new_sphere(t_vec3 center, double radius, t_color color);

#endif
