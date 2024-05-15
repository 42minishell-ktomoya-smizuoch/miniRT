/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 14:30:15 by smizuoch          #+#    #+#             */
/*   Updated: 2024/05/15 14:47:29 by smizuoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double random_double()
{
    return (rand() / (RAND_MAX + 1.0));
}

double random_double_range(double min, double max)
{
    return (min + (max - min) * random_double());
}