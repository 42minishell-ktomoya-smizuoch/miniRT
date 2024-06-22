/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 11:37:15 by smizuoch          #+#    #+#             */
/*   Updated: 2024/06/18 14:34:58 by smizuoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include <math.h>

t_vec3	random_in_unit_disk(void);

t_camera	camera_new(t_init_cam c)
{
	t_camera	cam;
	double		theta;
	double		h;
	double		viewport_height;
	double		viewport_width;

	theta = c.vfov * M_PI / 180.0;
	h = tan(theta / 2);
	viewport_height = 2.0 * h;
	viewport_width = c.aspect_ratio * viewport_height;
	cam.w = vec_normalize(vec_sub(c.lookfrom, c.lookat));
	cam.u = vec_normalize(vec_cross(c.vup, cam.w));
	cam.v = vec_cross(cam.w, cam.u);
	cam.origin = c.lookfrom;
	cam.horizontal = vec_scalar(cam.u, viewport_width * c.focus_dist);
	cam.vertical = vec_scalar(cam.v, viewport_height * c.focus_dist);
	cam.lower_left_corner = vec_sub(vec_sub(vec_sub(cam.origin,
					vec_scalar(cam.horizontal, 0.5)),
				vec_scalar(cam.vertical, 0.5)),
			vec_scalar(cam.w, c.focus_dist));
	cam.lens_radius = c.aperture / 2;
	cam.time0 = c.time0;
	cam.time1 = c.time1;
	return (cam);
}

t_ray	get_ray(t_camera *cam, double s, double t)
{
	t_ray	ray;
	t_vec3	rd;
	t_vec3	offset;
	double	time;

	rd = vec_scalar(random_in_unit_disk(), cam->lens_radius);
	offset = vec_add(vec_scalar(cam->u, rd.x), vec_scalar(cam->v, rd.y));
	time = cam->time0 + random_double() * (cam->time1 - cam->time0);
	ray.origin = vec_add(cam->origin, offset);
	ray.direction = vec_sub(vec_add(vec_add(cam->lower_left_corner,
					vec_scalar(cam->horizontal, s)),
				vec_scalar(cam->vertical, t)),
			cam->origin);
	ray.direction = vec_sub(ray.direction, offset);
	ray.time = time;
	return (ray);
}

t_vec3	random_in_unit_disk(void)
{
	t_vec3	p;
	double	length_squared;

	length_squared = 1.0;
	while (length_squared >= 1.0)
	{
		p = vec_new(random_double(), random_double(), 0);
		p = vec_scalar(p, 2.0);
		p = vec_sub(p, vec_new(1, 1, 0));
		length_squared = vec_dot(p, p);
	}
	return (p);
}
