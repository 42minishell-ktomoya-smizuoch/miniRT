/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 16:18:38 by smizuoch          #+#    #+#             */
/*   Updated: 2024/06/09 16:18:39 by smizuoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ambient.h"

t_ambient	new_ambient(t_color color, double ratio)
{
	t_ambient	ambient;

	ambient.color = color;
	ambient.ratio = ratio;
	return (ambient);
}
