/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_object_type.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <twbtomoya2@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 23:51:26 by ktomoya           #+#    #+#             */
/*   Updated: 2024/06/22 00:02:18 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_type	get_object_type(const char *id)
{
	t_type	type;

	type = TYPE_UNKNOWN;
	if (ft_strncmp(id, "A", 1) == 0)
		type = TYPE_AMBIENT_LIGHT;
	else if (ft_strncmp(id, "C", 1) == 0)
		type = TYPE_CAMERA;
	else if (ft_strncmp(id, "L", 1) == 0)
		type = TYPE_LIGHT;
	else if (ft_strncmp(id, "sp", 2) == 0)
		type = TYPE_SPHERE;
	else if (ft_strncmp(id, "pl", 2) == 0)
		type = TYPE_PLANE;
	else if (ft_strncmp(id, "cy", 2) == 0)
		type = TYPE_CYLINDER;
	else if (ft_strncmp(id, "rc", 2) == 0)
		type = TYPE_RECTANGLE;
	return (type);
}
