/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_out_of_range_int.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <twbtomoya2@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 14:23:45 by ktomoya           #+#    #+#             */
/*   Updated: 2024/06/16 14:24:48 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	is_out_of_range_int(int num, int lower, int upper)
{
	return (num < lower || upper < num);
}
