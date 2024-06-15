/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ambient_light.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <twbtomoya2@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 16:50:34 by ktomoya           #+#    #+#             */
/*   Updated: 2024/06/15 16:34:27 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parse_ambient_light(const char *line, t_ambient *amb)
{
	if (ft_sscanf(line, "%lf %lf,%lf,%lf", &amb->ratio,
			&amb->color.r, &amb->color.g, &amb->color.b) != 4)
		exit_with_error("ErrorA\n");
}
