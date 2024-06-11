#include "moving_sphere.h"
#include <stdlib.h>

t_vec3 moving_sphere_center(t_moving_sphere *sphere, double time) {
    return vec_add(sphere->center0, vec_scalar(vec_sub(sphere->center1, sphere->center0), (time - sphere->time0) / (sphere->time1 - sphere->time0)));
}

int hit_moving_sphere(t_hittable *self, t_ray *ray, double t_min, double t_max, t_hit_record *rec) {
    t_moving_sphere *sphere = (t_moving_sphere *)self->data;
    t_vec3 oc = vec_sub(ray->origin, moving_sphere_center(sphere, ray->time));
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
    t_vec3 outward_normal = vec_normalize(vec_sub(rec->point, moving_sphere_center(sphere, ray->time)));
    set_face_normal(rec, ray, outward_normal);
    rec->color = sphere->color;
    rec->fuzz = sphere->fuzz;
    rec->ref_idx = sphere->ref_idx;
    rec->material = sphere->material;

    return 1;
}

t_hittable new_moving_sphere(t_vec3 center0, t_vec3 center1, double time0, double time1, double radius, t_color color, t_material_type material, double fuzz, double ref_idx) {
    t_moving_sphere *sphere_data = xmalloc(sizeof(t_moving_sphere));
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
    hittable_sphere.hit = hit_moving_sphere;

    return hittable_sphere;
}
