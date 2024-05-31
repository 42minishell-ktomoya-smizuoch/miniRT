#include "aabb.h"
#include <math.h>

t_aabb aabb_new(t_vec3 a, t_vec3 b) {
    t_aabb box;
    box._min = a;
    box._max = b;
    return box;
}

int aabb_hit(const t_aabb *box, const t_ray *r, double tmin, double tmax) {
    for (int a = 0; a < 3; a++) {
        double invD = 1.0 / (a == 0 ? r->direction.x : (a == 1 ? r->direction.y : r->direction.z));
        double t0 = ((a == 0 ? box->_min.x : (a == 1 ? box->_min.y : box->_min.z)) - (a == 0 ? r->origin.x : (a == 1 ? r->origin.y : r->origin.z))) * invD;
        double t1 = ((a == 0 ? box->_max.x : (a == 1 ? box->_max.y : box->_max.z)) - (a == 0 ? r->origin.x : (a == 1 ? r->origin.y : r->origin.z))) * invD;
        if (invD < 0.0) {
            double temp = t0;
            t0 = t1;
            t1 = temp;
        }
        tmin = t0 > tmin ? t0 : tmin;
        tmax = t1 < tmax ? t1 : tmax;
        if (tmax <= tmin)
            return 0;
    }
    return 1;
}

struct s_aabb surrounding_box(struct s_aabb box0, struct s_aabb box1) {
    t_vec3 small = vec_new(fmin(box0._min.x, box1._min.x), fmin(box0._min.y, box1._min.y), fmin(box0._min.z, box1._min.z));
    t_vec3 big = vec_new(fmax(box0._max.x, box1._max.x), fmax(box0._max.y, box1._max.y), fmax(box0._max.z, box1._max.z));
    return aabb_new(small, big);
}
