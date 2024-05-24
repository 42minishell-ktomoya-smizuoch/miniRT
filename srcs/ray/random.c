/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 14:30:15 by smizuoch          #+#    #+#             */
/*   Updated: 2024/05/24 12:02:07 by smizuoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// not use rand() function
double	random_double(void)
{
	static unsigned long int next = 1;

	next = next * 1103515245 + 12345;
	return ((unsigned)(next / 65536) % 32768) / 32768.0;
}

// double	random_double(void)
// {
// 	return (rand() / (RAND_MAX + 1.0));
// }

double	random_double_range(double min, double max)
{
	return (min + (max - min) * random_double());
}

t_vec3	random_in_unit_sphere(void)
{
	t_vec3	p;

	while (1)
	{
		p = vec_new(random_double_range(-1, 1), random_double_range(-1, 1),
				random_double_range(-1, 1));
		if (vec_length(p) >= 1)
			continue ;
		return (p);
	}
}

t_vec3	random_unit_vector(void)
{
	return (vec_normalize(random_in_unit_sphere()));
}

t_vec3	random_in_hemisphere(const t_vec3 *normal)
{
	t_vec3	in_unit_sphere;

	in_unit_sphere = random_in_unit_sphere();
	if (vec_dot(in_unit_sphere, *normal) > 0.0)
		return (in_unit_sphere);
	else
		return (vec_scalar(in_unit_sphere, -1));
}
