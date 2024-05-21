#include "lambertian.h"
#include <stdlib.h>

typedef struct s_lambertian {
    t_vec3 center;
    double radius;
    t_color color;
} t_lambertian;

int hit_lambertian(t_hittable *self, t_ray *ray, double t_min, double t_max, t_hit_record *rec) {
    t_lambertian *lambertian = (t_lambertian *)self->data;
    t_vec3 oc = vec_sub(ray->origin, lambertian->center);
    double a = vec_dot(ray->direction, ray->direction);
    double half_b = vec_dot(oc, ray->direction);
    double c = vec_dot(oc, oc) - lambertian->radius * lambertian->radius;
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
    t_vec3 outward_normal = vec_normalize(vec_sub(rec->point, lambertian->center));
    set_face_normal(rec, ray, outward_normal);
    rec->color = lambertian->color;
    rec->fuzz = 0;
    rec->ref_idx = 0;
    rec->material = LAMBERTIAN;

    return 1;
}

t_hittable new_lambertian(t_vec3 center, double radius, t_color color) {
    t_lambertian *lambertian_data = malloc(sizeof(t_lambertian));
    lambertian_data->center = center;
    lambertian_data->radius = radius;
    lambertian_data->color = color;

    t_hittable hittable_lambertian;
    hittable_lambertian.data = lambertian_data;
    hittable_lambertian.hit = hit_lambertian;

    return hittable_lambertian;
}
