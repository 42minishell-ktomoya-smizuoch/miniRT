/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 17:22:55 by ktomoya           #+#    #+#             */
/*   Updated: 2024/06/25 16:24:09 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "light.h"

void	parse_light(const char *line, t_data *data)
{
	t_light	light;

	ft_memset(&light, 0, sizeof(t_light));
	scan_light(line, &light);
	if (is_out_of_range_double(light.intensity, 0.0, 1.0) == true)
		exit_with_error("Error:L:intensity:out of range\n");
	if (is_rgb_out_of_range(light.color) == true)
		exit_with_error("Error:L:rgb:out of range\n");
	add_light(&data->lights, new_light(light.position,
			light.color, light.intensity));
}
