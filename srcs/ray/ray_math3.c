/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_math3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 11:39:09 by smizuoch          #+#    #+#             */
/*   Updated: 2024/06/11 17:10:38 by smizuoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3	vec_mul(t_vec3 a, t_vec3 b)
{
	return ((t_vec3){a.x * b.x, a.y * b.y, a.z * b.z});
}

t_vec3	vec_cross(t_vec3 a, t_vec3 b)
{
	return ((t_vec3){a.y * b.z - a.z * b.y,
		a.z * b.x - a.x * b.z,
		a.x * b.y - a.y * b.x});
}

t_color	vec3_to_color(t_vec3 v)
{
	double	r;
	double	g;
	double	b;

	r = fmax(0.0, fmin(1.0, v.x));
	g = fmax(0.0, fmin(1.0, v.y));
	b = fmax(0.0, fmin(1.0, v.z));
	return ((t_color){r, g, b});
}

t_vec3	color_to_vec3(t_color c)
{
	return ((t_vec3){c.r, c.g, c.b});
}

t_color	scale_color(t_color color, int samples_per_pixel)
{
	double	scale;

	scale = 1.0 / samples_per_pixel;
	color.r = sqrt(fmax(0.0, color.r * scale));
	color.g = sqrt(fmax(0.0, color.g * scale));
	color.b = sqrt(fmax(0.0, color.b * scale));
	return (color);
}
