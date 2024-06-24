/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_plane.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 11:37:55 by ktomoya           #+#    #+#             */
/*   Updated: 2024/06/24 11:41:13 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "plane.h"

void	scan_plane(const char *line, t_plane *plane)
{
	char	extra;

	extra = 0;
	if (ft_sscanf(line, "%lf,%lf,%lf %lf,%lf,%lf %lf,%lf,%lf %d %c",
			&plane->point.x, &plane->point.y, &plane->point.z,
			&plane->normal.x, &plane->normal.y, &plane->normal.z,
			&plane->color.r, &plane->color.g, &plane->color.b,
			&plane->material, &extra) != 11
			|| extra != '\0')
		exit_with_error("Error:plane\n");
}
