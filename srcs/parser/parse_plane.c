/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <twbtomoya2@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 16:18:57 by ktomoya           #+#    #+#             */
/*   Updated: 2024/06/16 17:36:42 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parse_plane(const char *line, t_plane *plane)
{
	if (ft_sscanf(line, "%lf,%lf,%lf %lf,%lf,%lf %lf,%lf,%lf %d",
			&plane->point.x, &plane->point.y, &plane->point.z,
			&plane->normal.x, &plane->normal.y, &plane->normal.z,
			&plane->color.r, &plane->color.g, &plane->color.b,
			&plane->material) != 10)
		exit_with_error("Error:pl\n");
	if (is_vec3_out_of_range(plane->normal, -1.0, 1.0) == true)
		exit_with_error("Error:pl:vec3:out of ragne\n");
	if (is_rgb_out_of_range(plane->color) == true)
		exit_with_error("Error:pl:rgb:out of range\n");
	if (is_out_of_range_int(plane->material, 0, 3) == true)
		exit_with_error("Error:pl:material:out of range\n");
}
