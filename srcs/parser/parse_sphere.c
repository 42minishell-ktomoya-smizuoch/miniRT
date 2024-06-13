/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 17:35:13 by ktomoya           #+#    #+#             */
/*   Updated: 2024/06/13 17:41:39 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parse_sphere(const char *line, t_sphere *sphere)
{
	if (sscanf(line, "%lf,%lf,%lf %lf %lf,%lf,%lf",
		&sphere->center.x, &sphere->center.y, &sphere->center.z,
		&sphere->diameter, &sphere->color.r, &sphere->color.g,
		&sphere->color.b) != 7)
		exit_with_error("Errorsp\n");
}
