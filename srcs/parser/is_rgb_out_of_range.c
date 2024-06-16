/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_rgb_out_of_range.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <twbtomoya2@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 05:53:18 by ktomoya           #+#    #+#             */
/*   Updated: 2024/06/16 06:00:01 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	is_rgb_out_of_range(t_color color)
{
    return (is_out_of_range(color.r, 0.0, 255.0)
		|| is_out_of_range(color.g, 0.0, 255.0)
		|| is_out_of_range(color.b, 0.0, 255.0));
}
