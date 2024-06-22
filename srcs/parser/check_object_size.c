/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_object_size.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 19:02:14 by ktomoya           #+#    #+#             */
/*   Updated: 2024/06/22 19:20:54 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	check_object_size(int obj_cnt[8])
{
	int		sum;
	t_type	type;

	sum = 0;
	type = TYPE_AMBIENT_LIGHT;
	if (obj_cnt[TYPE_AMBIENT_LIGHT] > 1)
		exit_with_error("Error: The number of ambient light objects is limited to one\n");
	if (obj_cnt[TYPE_CAMERA] > 1)
		exit_with_error("Error: The number of camera objects is limited to one\n");
	while (type != TYPE_UNKNOWN)
	{
		sum += obj_cnt[type];
		type++;
	}
	if (sum > OBJ_MAX_SIZE)
		exit_with_error("Error: The number of objects has exceeded the maximum limit\n");
}
