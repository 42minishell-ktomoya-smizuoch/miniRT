/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ambient_light.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <twbtomoya2@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 16:50:34 by ktomoya           #+#    #+#             */
/*   Updated: 2024/06/25 16:22:47 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parse_ambient_light(const char *line, t_ambient *amb)
{
	char	extra;

	extra = 0;
	if (ft_sscanf(line, "%lf %lf,%lf,%lf %c", &amb->ratio,
			&amb->color.r, &amb->color.g, &amb->color.b, &extra) != 5
		|| extra != '\0')
		exit_with_error("Error:A\n");
	if (is_out_of_range_double(amb->ratio, 0.0, 1.0) == true)
		exit_with_error("Error:A:ratio:out of range\n");
	if (is_rgb_out_of_range(amb->color) == true)
		exit_with_error("Error:A:rgb:out of range\n");
}
