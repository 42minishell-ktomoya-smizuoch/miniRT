#include "ambient.h"

t_ambient new_ambient(t_color color, double ratio) {
    t_ambient ambient;
    ambient.color = color;
    ambient.ratio = ratio;
    return ambient;
}
