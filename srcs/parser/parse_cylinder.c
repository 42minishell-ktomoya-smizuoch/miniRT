/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <twbtomoya2@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 16:26:22 by ktomoya           #+#    #+#             */
/*   Updated: 2024/06/16 06:52:28 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parse_cylinder(const char *line, t_cylinder *cylinder)
{
	if (ft_sscanf(line, "%lf,%lf,%lf %lf,%lf,%lf %lf %lf %lf,%lf,%lf",
			&cylinder->center.x, &cylinder->center.y, &cylinder->center.z,
			&cylinder->axisnorm.x, &cylinder->axisnorm.y, &cylinder->axisnorm.z,
			&cylinder->diameter, &cylinder->height,
			&cylinder->color.r, &cylinder->color.g, &cylinder->color.b) != 11)
		exit_with_error("Error:cy\n");
	if (is_vec3_out_of_range(cylinder->axisnorm, -1.0, 1.0) == true)
		exit_with_error("Error:cy:vec3:out of range\n");
	if (is_rgb_out_of_range(cylinder->color) == true)
		exit_with_error("Error:cy:rgb:out of range\n");
}
