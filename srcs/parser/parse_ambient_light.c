/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ambient_light.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <twbtomoya2@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 16:50:34 by ktomoya           #+#    #+#             */
/*   Updated: 2024/06/16 14:31:29 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parse_ambient_light(const char *line, t_ambient *amb)
{
	if (ft_sscanf(line, "%lf %lf,%lf,%lf", &amb->ratio,
			&amb->color.r, &amb->color.g, &amb->color.b) != 4)
		exit_with_error("Error:A\n");
	if (is_out_of_range_double(amb->ratio, 0.0, 1.0) == true)
		exit_with_error("Error:A:ratio:out of range\n");
	if (is_rgb_out_of_range(amb->color) == true)
		exit_with_error("Error:A:rgb:out of range\n");
}
