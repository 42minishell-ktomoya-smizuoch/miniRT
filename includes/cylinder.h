#ifndef CYLINDER_H
#define CYLINDER_H

#include "hittable.h"
#include "minirt.h"

t_hittable new_cylinder(t_vec3 center, t_vec3 axisnorm, double diameter, double height, t_color color, t_material_type material);

#endif
