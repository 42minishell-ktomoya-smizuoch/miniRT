/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 16:37:14 by ktomoya           #+#    #+#             */
/*   Updated: 2024/06/24 11:14:10 by ktomoya          ###   ########.fr       */
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
    setter.aspect_ratio = (double)WINDOW_WIDTH / (double)WINDOW_HEIGHT;
	setter.time0 = 0.0;
	setter.time1 = 1.0;
	*camera = camera_new(setter);
}
