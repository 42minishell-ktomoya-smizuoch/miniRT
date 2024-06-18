/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 17:54:00 by smizuoch          #+#    #+#             */
/*   Updated: 2024/06/18 17:55:05 by smizuoch         ###   ########.fr       */
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

t_ray_color	init_ray_color(t_data *data)
{
	t_ray_color	r;

	r.world = data->world;
	r.lights = &data->lights;
	r.ambient = &data->ambient;
	r.depth = data->max_depth;
	return (r);
}

static t_vec3	calculate_color(t_data *data, int x, int y, int s)
{
	t_vec3	accumulated_color;
	double	u;
	double	v;
	t_ray	ray;
	t_color	sample_color;

	accumulated_color = (t_vec3){0, 0, 0};
	while (s < data->samples_per_pixel)
	{
		u = (x + random_double()) / (WINDOW_WIDTH - 1);
		v = ((WINDOW_HEIGHT - 1 - y) + random_double()) / (WINDOW_HEIGHT - 1);
		ray = get_ray(&data->camera, u, v);
		sample_color = ray_color(&ray, init_ray_color(data));
		accumulated_color = vec_add(accumulated_color,
				color_to_vec3(sample_color));
		s++;
	}
	accumulated_color.x /= data->samples_per_pixel;
	accumulated_color.y /= data->samples_per_pixel;
	accumulated_color.z /= data->samples_per_pixel;
	return (accumulated_color);
}

static void	put_pixel(t_data *data, int x, int y, t_vec3 accumulated_color)
{
	t_color	pixel_color;
	int		color;

	pixel_color = (t_color)
	{
		sqrt(accumulated_color.x),
		sqrt(accumulated_color.y),
		sqrt(accumulated_color.z)
	};
	color = vec_to_color(pixel_color);
	my_mlx_pixel_put(data, x, y, color);
}

void	render(t_data *data)
{
	int		x;
	int		y;
	t_vec3	accumulated_color;

	y = 0;
	while (y < WINDOW_HEIGHT)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			accumulated_color = calculate_color(data, x, y, 0);
			put_pixel(data, x, y, accumulated_color);
			x++;
		}
		print_progress(y + 1, WINDOW_HEIGHT);
		y++;
	}
	printf("Rendering complete!\n");
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
