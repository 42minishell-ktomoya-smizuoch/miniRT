#include "hittable.h"
#include <stdlib.h>
#include <math.h>

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
