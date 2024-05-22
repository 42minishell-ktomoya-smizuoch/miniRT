#ifndef LAMBERTIAN_H
#define LAMBERTIAN_H

#include "minirt.h"
#include "hittable.h"

t_hittable new_lambertian(t_vec3 center, double radius, t_color color);

#endif
