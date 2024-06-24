/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_sphere.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 11:30:49 by ktomoya           #+#    #+#             */
/*   Updated: 2024/06/24 15:21:19 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	scan_sphere(const char *line, t_sphere *sphere)
{
	char	extra;

	extra = 0;
	if (ft_sscanf(line, "%lf,%lf,%lf %lf %lf,%lf,%lf %d %c",
			&sphere->center.x, &sphere->center.y, &sphere->center.z,
			&sphere->diameter, &sphere->color.r, &sphere->color.g,
			&sphere->color.b, &sphere->material, &extra) != 9
			|| extra != '\0')
	{
		if (ft_sscanf(line, "%lf,%lf,%lf %lf %lf,%lf,%lf %c",
				&sphere->center.x, &sphere->center.y, &sphere->center.z,
				&sphere->diameter, &sphere->color.r, &sphere->color.g,
				&sphere->color.b, &extra) != 8
				|| extra != '\0')
			exit_with_error("Error:sphere\n");
		print_sphere(*sphere);
	}
}
