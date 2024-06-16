/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 16:37:14 by ktomoya           #+#    #+#             */
/*   Updated: 2024/06/16 07:31:52 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parse_camera(const char *line, t_camera *camera)
{
	if (ft_sscanf(line, "%lf,%lf,%lf %lf,%lf,%lf %lf %lf,%lf,%lf",
			&camera->origin.x, &camera->origin.y, &camera->origin.z,
			&camera->normal.x, &camera->normal.y, &camera->normal.z,
			&camera->fov, &camera->lower_left_corner.x,
			&camera->lower_left_corner.y, &camera->lower_left_corner.z) != 10)
		exit_with_error("Error:C\n");
	if (is_vec3_out_of_range(camera->normal, -1.0, 1.0) == true)
		exit_with_error("Error:C:vec3:out of ragne\n");
	if (is_out_of_range(camera->fov, 0.0, 180.0) == true)
		exit_with_error("Error:C:fov:out of range\n");
}
