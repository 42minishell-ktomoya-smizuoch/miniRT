/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hittable_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 16:21:12 by smizuoch          #+#    #+#             */
/*   Updated: 2024/06/14 17:00:55 by smizuoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hittable.h"

void	set_face_normal(t_hit_record *rec, t_ray *r, t_vec3 outward_normal)
{
	rec->front_face = vec_dot(r->direction, outward_normal) < 0;
	if (rec->front_face)
		rec->normal = outward_normal;
	else
		rec->normal = vec_scalar(outward_normal, -1);
}

void	set_face_normal_with_radius(t_hit_record *rec, t_ray *r,
						t_vec3 outward_normal, double radius)
{
	if (radius < 0)
		outward_normal = vec_scalar(outward_normal, -1);
	set_face_normal(rec, r, outward_normal);
}

t_hittable_list	*new_hittable_list(int initial_capacity)
{
	t_hittable_list	*list;

	list = xmalloc(sizeof(t_hittable_list));
	if (!list)
		return (NULL);
	list->objects = xmalloc(sizeof(t_hittable) * initial_capacity);
	if (!list->objects)
	{
		free(list);
		return (NULL);
	}
	list->size = 0;
	list->capacity = initial_capacity;
	return (list);
}

void	add_hittable(t_hittable_list *list, t_hittable object)
{
	if (list->size == list->capacity)
	{
		list->capacity *= 2;
		list->objects = ft_realloc(list->objects, sizeof(t_hittable) * list->capacity);
		if (!list->objects)
		{
			perror("malloc");
			exit(EXIT_FAILURE);
		}
	}
	list->objects[list->size++] = object;
}

int	hit_list(t_hittable_list *list, t_ray *ray, double t_min, double t_max, t_hit_record *rec)
{
	t_hit_record	temp_rec;
	int				hit_anything;
	int				i;
	t_limits		l;//closest_so_far
	
	
	hit_anything = 0;
	i = 0;
	l.max = t_max;
	l.min = t_min;
	while (i < list->size)
	{
		if (list->objects[i].hit(&list->objects[i], ray, l.min, l.max, &temp_rec))
		{
			hit_anything = 1;
			l.max = temp_rec.t;//closest_so_far
			*rec = temp_rec;
		}
		i++;
	}
	return (hit_anything);
}

void	free_hittable_list(t_hittable_list *list)
{
	int	i;

	i = 0;
	while (i < list->size)
	{
		list->objects[i].free_data(list->objects[i].data);
		i++;
	}
	free(list->objects);
	free(list);
}
