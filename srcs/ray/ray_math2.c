/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_math2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:13:35 by smizuoch          #+#    #+#             */
/*   Updated: 2024/05/31 13:09:07 by smizuoch         ###   ########.fr       */
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
t_vec3 ray_at(const t_ray *ray, double t)
{
    return vec_add(ray->origin, vec_scalar(ray->direction, t));
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

t_vec3 vec_mul(t_vec3 a, t_vec3 b)
{
	return ((t_vec3){a.x * b.x, a.y * b.y, a.z * b.z});
}

t_vec3 vec_cross(t_vec3 a, t_vec3 b)
{
	return ((t_vec3){a.y * b.z - a.z * b.y,
					a.z * b.x - a.x * b.z,
					a.x * b.y - a.y * b.x});
}

