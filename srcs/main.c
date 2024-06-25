/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 16:33:38 by ktomoya           #+#    #+#             */
/*   Updated: 2024/06/25 16:36:21 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hittable.h"
#include "minirt.h"
#include "math_utils.h"
#include "metal.h"
#include "lambertian.h"
#include "dielectric.h"
#include "camera.h"
#include "rectangle.h"
#include "light.h"
#include "cylinder.h"
#include "ambient.h"
#include "plane.h"

int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc != 2)
		exit(1);
	init_data(&data);
	parse_file(argv[1], &data);
	render(&data);
	wait_input(&data);
	free(data.lights.lights);
	free_hittable_list(data.world);
	return (0);
}
