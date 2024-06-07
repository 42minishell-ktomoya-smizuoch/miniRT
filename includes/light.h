#ifndef LIGHT_H
#define LIGHT_H

#include "minirt.h"

t_light new_light(t_vec3 position, t_color color, double intensity);
t_light_list new_light_list(int count);
void add_light(t_light_list *list, t_light light);

#endif
