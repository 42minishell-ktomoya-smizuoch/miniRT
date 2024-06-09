/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_sphere.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 16:14:39 by smizuoch          #+#    #+#             */
/*   Updated: 2024/06/09 16:14:58 by smizuoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVING_SPHERE_H
# define MOVING_SPHERE_H

# include "hittable.h"
# include "minirt.h"

typedef struct s_moving_sphere
{
    t_vec3 center0, center1;
    double time0, time1;
    double radius;
    t_color color;
    t_material_type material;
    double fuzz;
    double ref_idx;
} t_moving_sphere;

t_hittable	new_moving_sphere(t_vec3 center0, t_vec3 center1, double time0, double time1, double radius, t_color color, t_material_type material, double fuzz, double ref_idx);

#endif
