/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 16:37:14 by ktomoya           #+#    #+#             */
/*   Updated: 2024/06/15 16:35:58 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parse_camera(const char *line, t_camera *camera)
{
	if (ft_sscanf(line, "%lf,%lf,%lf %lf,%lf,%lf %lf",
			&camera->origin.x, &camera->origin.y, &camera->origin.z,
			&camera->normal.x, &camera->normal.y, &camera->normal.z,
			&camera->fov) != 7)
		exit_with_error("ErrorC\n");
}
