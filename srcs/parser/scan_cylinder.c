/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_cylinder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 11:46:05 by ktomoya           #+#    #+#             */
/*   Updated: 2024/06/25 16:28:52 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "cylinder.h"

void	scan_cylinder(const char *line, t_cylinder *cylinder)
{
	char	extra;

	extra = 0;
	if (ft_sscanf(line, "%lf,%lf,%lf %lf,%lf,%lf %lf %lf %lf,%lf,%lf %d %c",
			&cylinder->center.x, &cylinder->center.y, &cylinder->center.z,
			&cylinder->axisnorm.x, &cylinder->axisnorm.y, &cylinder->axisnorm.z,
			&cylinder->diameter, &cylinder->height,
			&cylinder->color.r, &cylinder->color.g, &cylinder->color.b,
			&cylinder->material, &extra) != 13 || extra != '\0')
	{
		if (ft_sscanf(line, "%lf,%lf,%lf %lf,%lf,%lf %lf %lf %lf,%lf,%lf %c",
				&cylinder->center.x, &cylinder->center.y, &cylinder->center.z,
				&cylinder->axisnorm.x, &cylinder->axisnorm.y,
				&cylinder->axisnorm.z,
				&cylinder->diameter, &cylinder->height,
				&cylinder->color.r, &cylinder->color.g, &cylinder->color.b,
				&extra) != 12 || extra != '\0')
			exit_with_error("Error:cylinder\n");
	}
}
