/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_math.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 16:22:57 by smizuoch          #+#    #+#             */
/*   Updated: 2024/05/14 15:16:21 by smizuoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

// create a new vector
t_vec3	vec_new(double x, double y, double z)
{
	return ((t_vec3){x, y, z});
}

// add two vectors
t_vec3	vec_add(t_vec3 a, t_vec3 b)
{
	return ((t_vec3){a.x + b.x, a.y + b.y, a.z + b.z});
}

// subtract two vectors
t_vec3	vec_sub(t_vec3 a, t_vec3 b)
{
	return ((t_vec3){a.x - b.x, a.y - b.y, a.z - b.z});
}

// multiply a vector by a scalar
t_vec3	vec_scalar(t_vec3 a, double t)
{
	return ((t_vec3){a.x * t, a.y * t, a.z * t});
}

// dot product of two vectors
double	vec_dot(t_vec3 a, t_vec3 b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}
