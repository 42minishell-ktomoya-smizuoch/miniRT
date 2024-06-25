/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_object_size.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 19:02:14 by ktomoya           #+#    #+#             */
/*   Updated: 2024/06/25 16:10:55 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	check_object_size(int obj_cnt[8], int obj_size)
{
	t_type	type;

	type = TYPE_AMBIENT_LIGHT;
	if (obj_cnt[TYPE_AMBIENT_LIGHT] > 1)
		exit_with_error("Error: The number of ambient light objects "
			"is limited to one\n");
	if (obj_cnt[TYPE_CAMERA] > 1)
		exit_with_error("Error: The number of camera objects "
			"is limited to one\n");
	if (obj_size > OBJ_MAX_SIZE)
		exit_with_error("Error: The number of objects "
			"has exceeded the maximum limit\n");
}
