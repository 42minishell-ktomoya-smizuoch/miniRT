/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 16:37:14 by ktomoya           #+#    #+#             */
/*   Updated: 2024/06/22 21:59:13 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "camera.h"

void	parse_camera(const char *line, t_camera *camera)
{
	t_init_cam	setter;

	// origin->lookfrom, normal->lookat, vup<-new, fov->vfov, lens_radius->aperture, focus_distance->focus_dist
	// sscanfの対象: lookfrom, lookat, vup, vfov, aperture, focus_dist
	if (ft_sscanf(line, "%lf,%lf,%lf %lf,%lf,%lf %lf,%lf,%lf %lf %lf %lf",
			&setter.lookfrom.x, &setter.lookfrom.y, &setter.lookfrom.z,
			&setter.lookat.x, &setter.lookat.y, &setter.lookat.z,
			&setter.vup.x, &setter.vup.y, &setter.vup.z,
			&setter.vfov, 	&setter.aperture, &setter.focus_dist) != 12)
		exit_with_error("Error:C\n");
	if (is_vec3_out_of_range(setter.lookat, -1.0, 1.0) == true)
		exit_with_error("Error:C:vec3:out of ragne\n");
	if (is_out_of_range_double(setter.vfov, 0.0, 180.0) == true)
		exit_with_error("Error:C:vfov:out of range\n");
    setter.aspect_ratio = (double)WINDOW_WIDTH / (double)WINDOW_HEIGHT;
	setter.time0 = 0.0;
	setter.time1 = 1.0;
	*camera = camera_new(setter);
}
