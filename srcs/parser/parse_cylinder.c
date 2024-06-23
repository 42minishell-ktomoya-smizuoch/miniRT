/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <twbtomoya2@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 16:26:22 by ktomoya           #+#    #+#             */
/*   Updated: 2024/06/23 20:01:47 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "cylinder.h"
#include "lambertian.h"

void	parse_cylinder(const char *line, t_hittable_list *obj_list)
{
	t_cylinder	cylinder;

	ft_memset(&cylinder, 0, sizeof(t_cylinder));
	if (ft_sscanf(line, "%lf,%lf,%lf %lf,%lf,%lf %lf %lf %lf,%lf,%lf %d",
			&cylinder.center.x, &cylinder.center.y, &cylinder.center.z,
			&cylinder.axisnorm.x, &cylinder.axisnorm.y, &cylinder.axisnorm.z,
			&cylinder.diameter, &cylinder.height,
			&cylinder.color.r, &cylinder.color.g, &cylinder.color.b,
			&cylinder.material) != 12)
		exit_with_error("Error:cy\n");
	if (is_vec3_out_of_range(cylinder.axisnorm, -1.0, 1.0) == true)
		exit_with_error("Error:cy:vec3:out of range\n");
	if (is_rgb_out_of_range(cylinder.color) == true)
		exit_with_error("Error:cy:rgb:out of range\n");
	if (is_out_of_range_int(cylinder.material, 0, 3) == true)
		exit_with_error("Error:cy:material:out of range\n");
    add_hittable(obj_list, new_cylinder(cylinder));
}
