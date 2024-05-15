/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hittable_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 12:23:19 by smizuoch          #+#    #+#             */
/*   Updated: 2024/05/15 14:26:41 by smizuoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hittable.h"

void set_face_normal(t_hit_record *rec, t_ray *r, t_vec3 outward_normal)
{
    rec->front_face = vec_dot(r->direction, outward_normal) < 0;
    rec->normal = rec->front_face ? outward_normal : vec_scalar(outward_normal, -1);
}

t_hittable_list *new_hittable_list(int initial_capacity)
{
    t_hittable_list *list = malloc(sizeof(t_hittable_list));
    list->objects = malloc(sizeof(t_hittable) * initial_capacity);
    list->size = 0;
    list->capacity = initial_capacity;
    return list;
}

void add_hittable(t_hittable_list *list, t_hittable object)
{
    if (list->size == list->capacity) {
        list->capacity *= 2;
        list->objects = realloc(list->objects, sizeof(t_hittable) * list->capacity);
    }
    list->objects[list->size++] = object;
}

int hit_list(t_hittable_list *list, t_ray *ray, double t_min, double t_max, t_hit_record *rec)
{
    t_hit_record temp_rec;
    int hit_anything = 0;
    double closest_so_far = t_max;

    for (int i = 0; i < list->size; i++) {
        if (list->objects[i].hit(&list->objects[i], ray, t_min, closest_so_far, &temp_rec))
		{
            hit_anything = 1;
            closest_so_far = temp_rec.t;
            *rec = temp_rec;
        }
    }

    return hit_anything;
}

void free_hittable_list(t_hittable_list *list)
{
    for (int i = 0; i < list->size; i++) {
        list->objects[i].free_data(list->objects[i].data);
    }
    free(list->objects);
    free(list);
}
