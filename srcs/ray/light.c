#include "light.h"
#include <stdlib.h>

t_light new_light(t_vec3 position, t_color color, double intensity) {
    t_light light;
    light.position = position;
    light.color = color;
    light.intensity = intensity;
    return light;
}

t_light_list new_light_list(int count) {
    t_light_list list;
    list.lights = (t_light *)malloc(count * sizeof(t_light));
    list.count = 0;
    return list;
}

void add_light(t_light_list *list, t_light light) {
    list->lights[list->count] = light;
    list->count++;
}
