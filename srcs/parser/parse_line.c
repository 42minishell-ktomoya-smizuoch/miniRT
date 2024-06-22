/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 19:47:12 by ktomoya           #+#    #+#             */
/*   Updated: 2024/06/22 00:28:39 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parse_line(const char *line, t_data *data, int obj_cnt[10])
{
	t_type	type;

	while (ft_isspace(*line))
		line++;
	printf("%s", line);
	type = get_object_type(line);
	if (type == TYPE_AMBIENT_LIGHT)
		parse_ambient_light(line + 1, &data->ambient);
	else if (type == TYPE_CAMERA)
		parse_camera(line + 1, &data->camera);
	else if (type == TYPE_LIGHT)
		parse_light(line + 1, &data->light);
	else if (type == TYPE_SPHERE)
		parse_sphere(line + 2, &data->sphere);
	else if (type == TYPE_PLANE)
		parse_plane(line + 2, &data->plane);
	else if (type == TYPE_CYLINDER)
		parse_cylinder(line + 2, &data->cylinder);
	else if (type == TYPE_RECTANGLE)
		parse_rectangle(line + 2, &data->rectangle);
	else
		exit_with_error("Error:The object could not be identified\n");
	increment_object_count(obj_cnt, type);
}
