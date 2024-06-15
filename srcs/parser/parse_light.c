/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 17:22:55 by ktomoya           #+#    #+#             */
/*   Updated: 2024/06/16 05:27:17 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parse_light(const char *line, t_light *light)
{
	if (ft_sscanf(line, "%lf,%lf,%lf %lf %lf,%lf,%lf",
			&light->position.x, &light->position.y, &light->position.z,
			&light->intensity,
			&light->color.r, &light->color.g, &light->color.b) != 7)
		exit_with_error("ErrorL\n");
	if (is_out_of_range(light->intensity, 0.0, 1.0) == true)
		exit_with_error("ErrorL:out of range\n");
}
