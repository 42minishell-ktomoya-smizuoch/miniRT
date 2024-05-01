/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 14:16:10 by ktomoya           #+#    #+#             */
/*   Updated: 2024/05/01 14:34:29 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	wait_input(t_data *data)
{
	mlx_key_hook(data->win, esc_close, data);
	mlx_hook(data->win, 17, 0, exit_on_close, data);
	mlx_loop(data->mlx);
}
