/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <twbtomoya2@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 16:18:57 by ktomoya           #+#    #+#             */
/*   Updated: 2024/06/15 16:38:35 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parse_plane(const char *line, t_plane *plane)
{
		if (ft_sscanf(line, "%lf,%lf,%lf %lf,%lf,%lf %lf,%lf,%lf", &plane->point.x, &plane->point.y, &plane->point.z, &plane->normal.x, &plane->normal.y, &plane->normal.z, &plane->color.r, &plane->color.g, &plane->color.b) != 9)
			exit_with_error("Errorpl\n");
}
