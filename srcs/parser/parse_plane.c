/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <twbtomoya2@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 16:18:57 by ktomoya           #+#    #+#             */
/*   Updated: 2024/06/23 17:43:46 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "plane.h"

void	parse_plane(const char *line, t_hittable_list *obj_list)
{
	t_plane	plane;

	ft_memset(&plane, 0, sizeof(t_plane));
	if (ft_sscanf(line, "%lf,%lf,%lf %lf,%lf,%lf %lf,%lf,%lf %d",
			&plane.point.x, &plane.point.y, &plane.point.z,
			&plane.normal.x, &plane.normal.y, &plane.normal.z,
			&plane.color.r, &plane.color.g, &plane.color.b,
			&plane.material) != 10)
		exit_with_error("Error:plane\n");
	if (is_vec3_out_of_range(plane.normal, -1.0, 1.0) == true)
		exit_with_error("Error:plane:vec3:out of ragne\n");
	if (is_rgb_out_of_range(plane.color) == true)
		exit_with_error("Error:plane:rgb:out of range\n");
	if (is_out_of_range_int(plane.material, 0, 3) == true)
		exit_with_error("Error:plane:material:out of range\n");
	if (plane.material == LAMBERTIAN)
		add_hittable(obj_list, new_plane(plane.point, plane.normal, plane.color, 1));
	else if (plane.material == METAL)
		add_hittable(obj_list, new_plane(plane.point, plane.normal, plane.color, 2));
	else if (plane.material == DIELECTRIC)
		add_hittable(obj_list, new_plane(plane.point, plane.normal, plane.color, 3));
}
