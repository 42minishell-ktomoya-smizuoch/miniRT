/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 14:10:57 by smizuoch          #+#    #+#             */
/*   Updated: 2024/06/25 14:40:54 by smizuoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	error_pixselput(t_data *data)
{
	mlx_string_put(data->mlx, data->win, WINDOW_WIDTH / 2.5,
		WINDOW_HEIGHT / 2, 0xFF0000, "Error: No ambient light or camera");
	wait_input(data);
}
