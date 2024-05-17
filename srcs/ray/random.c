/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 14:30:15 by smizuoch          #+#    #+#             */
/*   Updated: 2024/05/17 13:22:06 by smizuoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double random_double() {
    return rand() / (RAND_MAX + 1.0);
}

double random_double_range(double min, double max) {
    return min + (max - min) * random_double();
}

t_vec3 random_in_unit_sphere() {
    while (1) {
        t_vec3 p = vec_new(random_double_range(-1, 1), random_double_range(-1, 1), random_double_range(-1, 1));
        if (vec_length(p) >= 1) continue;
        return p;
    }
}

t_vec3 random_unit_vector() {
    return vec_normalize(random_in_unit_sphere());
}
