/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 14:01:43 by ktomoya           #+#    #+#             */
/*   Updated: 2024/06/23 14:28:11 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "hittable.h"
#include "light.h"

void	init_data(t_data *data)
{
	ft_memset(data, 0, sizeof(t_data));
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WINDOW_WIDTH, WINDOW_HEIGHT,
			"miniRT");
	data->img = mlx_new_image(data->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	data->samples_per_pixel = 1;
	data->max_depth = 50;
	data->world = new_hittable_list(OBJ_MAX_SIZE);
    data->lights = new_light_list(LIGHT_MAX_SIZE);
}
