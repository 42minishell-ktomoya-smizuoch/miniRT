#include "cylinder.h"
#include <math.h>
#include <stdlib.h>

int hit_cylinder_side(t_cylinder *cyl, t_ray *ray, double t_min, double t_max, t_hit_record *rec) {
    t_vec3 oc = vec_sub(ray->origin, cyl->center);
    t_vec3 axis = vec_normalize(cyl->axisnorm);

    double a = vec_dot(ray->direction, ray->direction) - pow(vec_dot(ray->direction, axis), 2);
    double half_b = vec_dot(oc, ray->direction) - vec_dot(oc, axis) * vec_dot(ray->direction, axis);
    double c = vec_dot(oc, oc) - pow(vec_dot(oc, axis), 2) - pow(cyl->diameter / 2, 2);

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

    t_vec3 point = ray_at(*ray, root);
    t_vec3 relative_point = vec_sub(point, cyl->center);
    double height_along_axis = vec_dot(relative_point, axis);

    if (height_along_axis < 0 || height_along_axis > cyl->height)
        return 0;

    rec->t = root;
    rec->point = point;
    t_vec3 outward_normal = vec_sub(vec_sub(point, cyl->center), vec_scalar(axis, vec_dot(vec_sub(point, cyl->center), axis)));
    rec->normal = vec_normalize(outward_normal);
    rec->front_face = vec_dot(ray->direction, rec->normal) < 0;
    rec->color = cyl->color;
    rec->material = cyl->material;
    return 1;
}

int hit_cylinder_cap(t_cylinder *cyl, t_ray *ray, double t_min, double t_max, t_hit_record *rec, t_vec3 cap_center) {
    t_vec3 axis = vec_normalize(cyl->axisnorm);
    double denom = vec_dot(ray->direction, axis);

    if (fabs(denom) < 1e-6)
        return 0;

    double t = vec_dot(vec_sub(cap_center, ray->origin), axis) / denom;
    if (t < t_min || t > t_max)
        return 0;

    t_vec3 point = ray_at(*ray, t);
    t_vec3 d = vec_sub(point, cap_center);
    if (vec_dot(d, d) > (cyl->diameter / 2) * (cyl->diameter / 2))
        return 0;

    rec->t = t;
    rec->point = point;
    rec->normal = axis;
    rec->front_face = vec_dot(ray->direction, rec->normal) < 0;
    rec->color = cyl->color;
    rec->material = cyl->material;
    return 1;
}

int hit_cylinder(t_hittable *self, t_ray *ray, t_limits l, t_hit_record *rec) {
    t_cylinder *cyl = (t_cylinder *)self->data;
    t_hit_record temp_rec;
    int hit_anything = 0;
    double closest_so_far = l.max;

    if (hit_cylinder_side(cyl, ray, l.min, closest_so_far, &temp_rec)) {
        hit_anything = 1;
        closest_so_far = temp_rec.t;
        *rec = temp_rec;
    }
    if (hit_cylinder_cap(cyl, ray, l.min, closest_so_far, &temp_rec, vec_add(cyl->center, vec_scalar(cyl->axisnorm, 0)))) {
        hit_anything = 1;
        closest_so_far = temp_rec.t;
        *rec = temp_rec;
    }
    if (hit_cylinder_cap(cyl, ray, l.min, closest_so_far, &temp_rec, vec_add(cyl->center, vec_scalar(cyl->axisnorm, cyl->height)))) {
        hit_anything = 1;
        closest_so_far = temp_rec.t;
        *rec = temp_rec;
    }

    return hit_anything;
}

t_hittable new_cylinder(t_vec3 center, t_vec3 axisnorm, double diameter, double height, t_color color, t_material_type material) {
    t_cylinder *cyl_data = xmalloc(sizeof(t_cylinder));
    cyl_data->center = center;
    cyl_data->axisnorm = vec_normalize(axisnorm);
    cyl_data->diameter = diameter;
    cyl_data->height = height;
    cyl_data->color = color;
    cyl_data->material = material;

    t_hittable hittable_cylinder;
    hittable_cylinder.data = cyl_data;
    hittable_cylinder.hit = hit_cylinder;

    return hittable_cylinder;
}
