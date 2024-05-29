#include "hittable.h"
#include <stdlib.h>

t_vec3 reflect(t_vec3 v, t_vec3 n) {
    return vec_sub(v, vec_scalar(n, 2 * vec_dot(v, n)));
}
