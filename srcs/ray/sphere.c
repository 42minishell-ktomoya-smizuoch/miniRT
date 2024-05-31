/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 12:29:33 by smizuoch          #+#    #+#             */
/*   Updated: 2024/05/31 13:06:21 by smizuoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hittable.h"
#include <stdlib.h>

t_vec3 sphere_center(const t_sphere *sphere, double time) {
    return vec_add(sphere->center0, vec_scalar(vec_sub(sphere->center1, sphere->center0), (time - sphere->time0) / (sphere->time1 - sphere->time1)));
}

int hit_sphere(t_hittable *self, t_ray *ray, double t_min, double t_max, t_hit_record *rec) {
    t_sphere *sphere = (t_sphere *)self->data;
    t_vec3 oc = vec_sub(ray->origin, sphere_center(sphere, ray->time));
    double a = vec_dot(ray->direction, ray->direction);
    double half_b = vec_dot(oc, ray->direction);
    double c = vec_dot(oc, oc) - sphere->radius * sphere->radius;
    double discriminant = half_b * half_b - a * c;

    if (discriminant < 0)
        return 0;

    double sqrt_d = sqrt(discriminant);
    double root = (-half_b - sqrt_d) / a;

    if (root < t_min || root > t_max) {
        root = (-half_b + sqrt_d) / a;
        if (root < t_min || root > t_max)
            return 0;
    }

    rec->t = root;
    rec->point = ray_at(ray, rec->t);
    t_vec3 outward_normal = vec_normalize(vec_sub(rec->point, sphere_center(sphere, ray->time)));
    set_face_normal(rec, ray, outward_normal);
    rec->color = sphere->color;
    rec->fuzz = sphere->fuzz;
    rec->ref_idx = sphere->ref_idx;
    rec->material = sphere->material;

    return 1;
}

int bounding_box_sphere(const t_hittable *self, double t0, double t1, struct s_aabb *output_box) {
    t_sphere *sphere = (t_sphere *)self->data;
    t_vec3 radius_vec = vec_new(sphere->radius, sphere->radius, sphere->radius);
    if (sphere->center0.x == sphere->center1.x && sphere->center0.y == sphere->center1.y && sphere->center0.z == sphere->center1.z) {
        *output_box = aabb_new(vec_sub(sphere->center0, radius_vec), vec_add(sphere->center0, radius_vec));
    } else {
        t_aabb box0 = aabb_new(vec_sub(sphere_center(sphere, t0), radius_vec), vec_add(sphere_center(sphere, t0), radius_vec));
        t_aabb box1 = aabb_new(vec_sub(sphere_center(sphere, t1), radius_vec), vec_add(sphere_center(sphere, t1), radius_vec));
        *output_box = surrounding_box(box0, box1);
    }
    return 1;
}

t_hittable new_sphere(t_vec3 center0, t_vec3 center1, double time0, double time1, double radius, t_color color, t_material_type material, double fuzz, double ref_idx) {
    t_sphere *sphere_data = malloc(sizeof(t_sphere));
    sphere_data->center0 = center0;
    sphere_data->center1 = center1;
    sphere_data->time0 = time0;
    sphere_data->time1 = time1;
    sphere_data->radius = radius;
    sphere_data->color = color;
    sphere_data->material = material;
    sphere_data->fuzz = fuzz;
    sphere_data->ref_idx = ref_idx;

    t_hittable hittable_sphere;
    hittable_sphere.data = sphere_data;
    hittable_sphere.hit = hit_sphere;
    hittable_sphere.bounding_box = bounding_box_sphere;

    return hittable_sphere;
}
