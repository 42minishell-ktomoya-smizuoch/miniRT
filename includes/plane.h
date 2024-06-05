#ifndef PLANE_H
#define PLANE_H

#include "minirt.h"
#include "hittable.h"

t_hittable new_plane(t_vec3 point, t_vec3 normal, t_color color, t_material_type material);

#endif
