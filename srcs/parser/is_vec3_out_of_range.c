/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_vec3_out_of_range.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <twbtomoya2@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 06:41:48 by ktomoya           #+#    #+#             */
/*   Updated: 2024/06/16 14:29:21 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	is_vec3_out_of_range(t_vec3 vec3, double lower, double upper)
{
	return (is_out_of_range_double(vec3.x, lower, upper)
		|| is_out_of_range_double(vec3.y, lower, upper)
		|| is_out_of_range_double(vec3.z, lower, upper));
}
