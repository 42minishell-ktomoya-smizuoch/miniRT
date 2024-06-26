/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <twbtomoya2@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 16:26:22 by ktomoya           #+#    #+#             */
/*   Updated: 2024/06/26 12:40:50 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "cylinder.h"
#include "lambertian.h"

void	parse_cylinder(const char *line, t_hittable_list *obj_list)
{
	t_cylinder	cylinder;

	ft_memset(&cylinder, 0, sizeof(t_cylinder));
	scan_cylinder(line, &cylinder);
	if (is_vec3_out_of_range(cylinder.axisnorm, -1.0, 1.0) == true)
		exit_with_error("Error:cylinder:vector:out of range\n");
	if (is_rgb_out_of_range(cylinder.color) == true)
		exit_with_error("Error:cylinder:color:out of range\n");
	if (is_out_of_range_int(cylinder.material, 0, 3) == true)
		exit_with_error("Error:cylinder:material:out of range\n");
	cylinder.color = compress_rgb(cylinder.color);
	add_hittable(obj_list, new_cylinder(cylinder));
}
