/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 16:37:14 by ktomoya           #+#    #+#             */
/*   Updated: 2024/06/25 16:23:18 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "camera.h"

void	parse_camera(const char *line, t_camera *camera)
{
	t_init_cam	setter;

	ft_memset(&setter, 0, sizeof(t_init_cam));
	scan_camera(line, &setter);
	if (is_vec3_out_of_range(setter.lookat, -1.0, 1.0) == true)
		exit_with_error("Error:C:vec3:out of ragne\n");
	if (is_out_of_range_double(setter.vfov, 0.0, 180.0) == true)
		exit_with_error("Error:C:vfov:out of range\n");
	if (setter.no_option)
	{
		setter.vup.x = 0;
		setter.vup.y = 1;
		setter.vup.z = 0;
		setter.aperture = 0.1;
		setter.focus_dist = 10;
	}
	setter.aspect_ratio = (double)WINDOW_WIDTH / (double)WINDOW_HEIGHT;
	setter.time0 = 0.0;
	setter.time1 = 1.0;
	*camera = camera_new(setter);
}
