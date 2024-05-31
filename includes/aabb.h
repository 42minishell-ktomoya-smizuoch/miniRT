#ifndef AABB_H
#define AABB_H

#include "minirt.h"

typedef struct s_aabb {
    t_vec3 _min;
    t_vec3 _max;
} t_aabb;

t_aabb aabb_new(t_vec3 a, t_vec3 b);
int aabb_hit(const t_aabb *box, const t_ray *r, double tmin, double tmax);

#endif
