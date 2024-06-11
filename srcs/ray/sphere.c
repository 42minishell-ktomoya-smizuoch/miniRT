/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 12:29:33 by smizuoch          #+#    #+#             */
/*   Updated: 2024/06/11 17:17:21 by smizuoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hittable.h"

// 球のヒット関数
int hit_sphere(t_hittable *self, t_ray *ray, double t_min, double t_max, t_hit_record *rec)
{
    t_sphere *sphere = (t_sphere *)self->data;
    t_vec3 oc = vec_sub(ray->origin, sphere->center);
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
    rec->point = ray_at(*ray, rec->t);
    t_vec3 outward_normal = vec_normalize(vec_sub(rec->point, sphere->center));
    set_face_normal(rec, ray, outward_normal);
    rec->color = sphere->color;

    return 1;
}

// 球の初期化関数
t_hittable new_sphere(t_vec3 center, double radius, t_color color)
{
    t_sphere *sphere_data = xmalloc(sizeof(t_sphere));
    sphere_data->center = center;
    sphere_data->radius = radius;
    sphere_data->color = color;

    t_hittable hittable_sphere;
    hittable_sphere.data = sphere_data;
    hittable_sphere.hit = hit_sphere;

    return hittable_sphere;
}
