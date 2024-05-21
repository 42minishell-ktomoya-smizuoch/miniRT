#include "dielectric.h"
#include <stdlib.h>
#include <math.h>

typedef struct s_dielectric {
    t_vec3 center;
    double radius;
    double ref_idx; // 屈折率
} t_dielectric;

t_vec3 refract(t_vec3 uv, t_vec3 n, double etai_over_etat) {
    double cos_theta = fmin(vec_dot(vec_scalar(uv, -1), n), 1.0);
    t_vec3 r_out_perp = vec_scalar(vec_add(uv, vec_scalar(n, cos_theta)), etai_over_etat);
    t_vec3 r_out_parallel = vec_scalar(n, -sqrt(fabs(1.0 - vec_dot(r_out_perp, r_out_perp))));
    return vec_add(r_out_perp, r_out_parallel);
}

double schlick(double cosine, double ref_idx) {
    double r0 = (1 - ref_idx) / (1 + ref_idx);
    r0 = r0 * r0;
    return r0 + (1 - r0) * pow((1 - cosine), 5);
}

int hit_dielectric(t_hittable *self, t_ray *ray, double t_min, double t_max, t_hit_record *rec) {
    t_dielectric *dielectric = (t_dielectric *)self->data;
    t_vec3 oc = vec_sub(ray->origin, dielectric->center);
    double a = vec_dot(ray->direction, ray->direction);
    double half_b = vec_dot(oc, ray->direction);
    double c = vec_dot(oc, oc) - dielectric->radius * dielectric->radius;
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
    t_vec3 outward_normal = vec_normalize(vec_sub(rec->point, dielectric->center));
    set_face_normal(rec, ray, outward_normal);
    rec->color = (t_color){1.0, 1.0, 1.0}; // 誘電体は透明
    rec->fuzz = 0; // 誘電体にはぼやけはない
    rec->ref_idx = dielectric->ref_idx;
    rec->material = DIELECTRIC;

    return 1;
}

t_hittable new_dielectric(t_vec3 center, double radius, double ref_idx) {
    t_dielectric *dielectric_data = malloc(sizeof(t_dielectric));
    dielectric_data->center = center;
    dielectric_data->radius = radius;
    dielectric_data->ref_idx = ref_idx;

    t_hittable hittable_dielectric;
    hittable_dielectric.data = dielectric_data;
    hittable_dielectric.hit = hit_dielectric;

    return hittable_dielectric;
}
