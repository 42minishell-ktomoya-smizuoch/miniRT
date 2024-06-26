/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 17:35:13 by ktomoya           #+#    #+#             */
/*   Updated: 2024/06/26 12:48:38 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "hittable.h"
#include "lambertian.h"
#include "metal.h"
#include "dielectric.h"

void	parse_sphere(const char *line, t_hittable_list *obj_list)
{
	t_sphere	sphere;

	ft_memset(&sphere, 0, sizeof(t_sphere));
	scan_sphere(line, &sphere);
	if (is_rgb_out_of_range(sphere.color) == true)
		exit_with_error("Error:sphere:color:out of range\n");
	if (is_out_of_range_int(sphere.material, 0, 3) == true)
		exit_with_error("Error:sphere:material:out of range\n");
	sphere.color = compress_rgb(sphere.color);
	if (sphere.material == LAMBERTIAN || sphere.material == 0)
		add_hittable(obj_list,
			new_lambertian(sphere.center, sphere.diameter, sphere.color));
	else if (sphere.material == METAL)
		add_hittable(obj_list,
			new_metal(sphere.center, sphere.diameter, sphere.color, 0.0));
	else if (sphere.material == DIELECTRIC)
		add_hittable(obj_list,
			new_dielectric(sphere.center, sphere.diameter, 1.5));
}
