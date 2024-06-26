/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 10:52:27 by ktomoya           #+#    #+#             */
/*   Updated: 2024/06/26 12:43:11 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "camera.h"

void	scan_camera(const char *line, t_init_cam *setter)
{
	char	extra;

	extra = 0;
	if (ft_sscanf(line, "%lf,%lf,%lf %lf,%lf,%lf %lf %lf,%lf,%lf %lf %lf %c",
			&setter->lookfrom.x, &setter->lookfrom.y, &setter->lookfrom.z,
			&setter->lookat.x, &setter->lookat.y, &setter->lookat.z,
			&setter->vfov,
			&setter->vup.x, &setter->vup.y, &setter->vup.z,
			&setter->aperture, &setter->focus_dist, &extra) != 13
		|| extra != '\0')
	{
		setter->no_option = 1;
		if (ft_sscanf(line, "%lf,%lf,%lf %lf,%lf,%lf %lf %c",
				&setter->lookfrom.x, &setter->lookfrom.y, &setter->lookfrom.z,
				&setter->lookat.x, &setter->lookat.y, &setter->lookat.z,
				&setter->vfov, &extra) != 8
			|| extra != '\0')
			exit_with_error("Error:camera:The format is incorrect\n");
	}
}
