#include "rectangle.h"
#include <stdlib.h>

int hit_rectangle(t_hittable *self, t_ray *ray, t_limits l, t_hit_record *rec) {
    t_rectangle *rect = (t_rectangle *)self->data;
    double t = vec_dot(vec_sub(rect->p0, ray->origin), rect->normal) / vec_dot(ray->direction, rect->normal);

    if (t < l.min || t > l.max)
        return 0;

    t_vec3 p = ray_at(*ray, t);
    t_vec3 c0 = vec_sub(rect->p1, rect->p0);
    t_vec3 c1 = vec_sub(rect->p3, rect->p0);
    t_vec3 c = vec_sub(p, rect->p0);

    double dot00 = vec_dot(c0, c0);
    double dot01 = vec_dot(c0, c1);
    double dot02 = vec_dot(c0, c);
    double dot11 = vec_dot(c1, c1);
    double dot12 = vec_dot(c1, c);

    double inv_denom = 1.0 / (dot00 * dot11 - dot01 * dot01);
    double u = (dot11 * dot02 - dot01 * dot12) * inv_denom;
    double v = (dot00 * dot12 - dot01 * dot02) * inv_denom;

    if (u < 0 || u > 1 || v < 0 || v > 1)
        return 0;

    rec->t = t;
    rec->point = p;
    rec->normal = rect->normal;
    rec->front_face = vec_dot(ray->direction, rect->normal) < 0;
    rec->color = rect->color;
    rec->material = rect->material;
    return 1;
}

t_hittable new_rectangle(t_vec3 p0, t_vec3 p1, t_vec3 p2, t_vec3 p3, t_vec3 normal, t_color color, t_material_type material) {
    t_rectangle *rect_data = xmalloc(sizeof(t_rectangle));
    rect_data->p0 = p0;
    rect_data->p1 = p1;
    rect_data->p2 = p2;
    rect_data->p3 = p3;
    rect_data->normal = normal;
    rect_data->color = color;
    rect_data->material = material;

    t_hittable hittable_rect;
    hittable_rect.data = rect_data;
    hittable_rect.hit = hit_rectangle;

    return hittable_rect;
}
