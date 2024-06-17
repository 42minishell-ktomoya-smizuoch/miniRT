/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 19:47:12 by ktomoya           #+#    #+#             */
/*   Updated: 2024/06/17 09:44:23 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parse_line(const char *line, t_data *data)
{
	while (ft_isspace(*line))
		line++;
	printf("%s", line);
	if (ft_strncmp(line, "A", 1) == 0)
		parse_ambient_light(line + 1, &data->amb);
	else if (ft_strncmp(line, "C", 1) == 0)
		parse_camera(line + 1, &data->camera);
	else if (ft_strncmp(line, "L", 1) == 0)
		parse_light(line + 1, &data->light);
	else if (ft_strncmp(line, "sp", 2) == 0)
		parse_sphere(line + 2, &data->sphere);
	else if (ft_strncmp(line, "pl", 2) == 0)
		parse_plane(line + 2, &data->plane);
	else if (ft_strncmp(line, "cy", 2) == 0)
		parse_cylinder(line + 2, &data->cylinder);
	else if (ft_strncmp(line, "rc", 2) == 0)
		parse_rectangle(line + 2, &data->rectangle);
	else if (*line == '\n')
		;
	else
		exit(1);
	return ;
}
