/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_light.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 11:17:59 by ktomoya           #+#    #+#             */
/*   Updated: 2024/06/26 12:43:45 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "light.h"

void	scan_light(const char *line, t_light *light)
{
	char	extra;

	extra = 0;
	if (ft_sscanf(line, "%lf,%lf,%lf %lf %lf,%lf,%lf %c",
			&light->position.x, &light->position.y, &light->position.z,
			&light->intensity,
			&light->color.r, &light->color.g, &light->color.b,
			&extra) != 8 || extra != '\0')
		exit_with_error("Error:light:The format is incorrect\n");
}
