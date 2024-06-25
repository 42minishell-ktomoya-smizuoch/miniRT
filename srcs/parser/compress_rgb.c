/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compress_rgb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 15:45:50 by smizuoch          #+#    #+#             */
/*   Updated: 2024/06/25 17:35:15 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color	compress_rgb(t_color color)
{
	t_color	new_color;

	new_color.r = color.r / 255.0;
	new_color.g = color.g / 255.0;
	new_color.b = color.b / 255.0;
	return (new_color);
}
