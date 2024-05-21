#include "metal.h"
#include <stdlib.h>

typedef struct s_metal {
    t_vec3 center;
    double radius;
    t_color color;
    double fuzz; // 反射のぼやけ具合
} t_metal;

t_vec3 reflect(t_vec3 v, t_vec3 n) {
    return vec_sub(v, vec_scalar(n, 2 * vec_dot(v, n)));
}

int hit_metal(t_hittable *self, t_ray *ray, double t_min, double t_max, t_hit_record *rec) {
    t_metal *metal = (t_metal *)self->data;
    t_vec3 oc = vec_sub(ray->origin, metal->center);
    double a = vec_dot(ray->direction, ray->direction);
    double half_b = vec_dot(oc, ray->direction);
    double c = vec_dot(oc, oc) - metal->radius * metal->radius;
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
    t_vec3 outward_normal = vec_normalize(vec_sub(rec->point, metal->center));
    set_face_normal(rec, ray, outward_normal);
    rec->color = metal->color;
    rec->fuzz = metal->fuzz < 1 ? metal->fuzz : 1; // fuzzの値を1以下に制限

    return 1;
}

t_hittable new_metal(t_vec3 center, double radius, t_color color, double fuzz) {
    t_metal *metal_data = malloc(sizeof(t_metal));
    metal_data->center = center;
    metal_data->radius = radius;
    metal_data->color = color;
    metal_data->fuzz = fuzz;

    t_hittable hittable_metal;
    hittable_metal.data = metal_data;
    hittable_metal.hit = hit_metal;

    return hittable_metal;
}
