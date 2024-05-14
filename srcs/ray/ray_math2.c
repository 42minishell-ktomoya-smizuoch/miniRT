/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_math2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:13:35 by smizuoch          #+#    #+#             */
/*   Updated: 2024/05/14 15:17:57 by smizuoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

// length of a vector
double	vec_length(t_vec3 a)
{
	return (sqrt(vec_dot(a, a)));
}

// normalize a vector
t_vec3	vec_normalize(t_vec3 a)
{
	return (vec_scalar(a, 1.0 / vec_length(a)));
}

// calculate the point at parameter t on a ray
t_vec3	ray_at(t_ray ray, double t)
{
	return (vec_add(ray.origin, vec_scalar(ray.direction, t)));
}

// calculate the unit vector of a vector
t_vec3	vec_uint(t_vec3 v)
{
	double	len;

	len = sqrt(vec_dot(v, v));
	return (vec_scalar(v, 1.0 / len));
}

// convert a vector to a color
int	vec_to_color(t_color col)
{
	int	r;
	int	g;
	int	b;

	r = (int)(255.999 * col.r);
	g = (int)(255.999 * col.g);
	b = (int)(255.999 * col.b);
	return ((r << 16) | (g << 8) | b);
}
