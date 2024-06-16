/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 17:35:13 by ktomoya           #+#    #+#             */
/*   Updated: 2024/06/16 06:34:17 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parse_sphere(const char *line, t_sphere *sphere)
{
	if (ft_sscanf(line, "%lf,%lf,%lf %lf %lf,%lf,%lf",
			&sphere->center.x, &sphere->center.y, &sphere->center.z,
			&sphere->diameter, &sphere->color.r, &sphere->color.g,
			&sphere->color.b) != 7)
		exit_with_error("Error:sp\n");
	if (is_rgb_out_of_range(sphere->color) == true)
		exit_with_error("Error:sp:rgb:out of range\n");
}
