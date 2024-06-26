/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rectangle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <twbtomoya2@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 08:56:32 by ktomoya           #+#    #+#             */
/*   Updated: 2024/06/26 12:42:47 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "rectangle.h"

void	parse_rectangle(const char *line, t_hittable_list *obj_list)
{
	t_rectangle	rectangle;

	ft_memset(&rectangle, 0, sizeof(t_rectangle));
	if (ft_sscanf(line, "%lf,%lf,%lf %lf,%lf,%lf %lf,%lf,%lf %lf,%lf,%lf"
			"%lf,%lf,%lf %lf,%lf,%lf %d",
			&rectangle.p0.x, &rectangle.p0.y, &rectangle.p0.z,
			&rectangle.p1.x, &rectangle.p1.y, &rectangle.p1.z,
			&rectangle.p2.x, &rectangle.p2.y, &rectangle.p2.z,
			&rectangle.p3.x, &rectangle.p3.y, &rectangle.p3.z,
			&rectangle.normal.x, &rectangle.normal.y, &rectangle.normal.z,
			&rectangle.color.r, &rectangle.color.g, &rectangle.color.b,
			&rectangle.material) != 19)
		exit_with_error("Error:rectangle:The format is incorrect\n");
	if (is_vec3_out_of_range(rectangle.normal, -1.0, 1.0) == true)
		exit_with_error("Error:rectangle:normal:out of range\n");
	if (is_rgb_out_of_range(rectangle.color) == true)
		exit_with_error("Error:rectangle:color:out of range\n");
	if (is_out_of_range_int(rectangle.material, 0, 3) == true)
		exit_with_error("Error:rectangle:material:out of range\n");
	rectangle.color = compress_rgb(rectangle.color);
	add_hittable(obj_list, new_rectangle(rectangle));
}
