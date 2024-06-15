/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <twbtomoya2@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 16:26:22 by ktomoya           #+#    #+#             */
/*   Updated: 2024/06/15 16:55:05 by ktomoya          ###   ########.fr       */
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
		exit_with_error("Errorcy\n");
}
