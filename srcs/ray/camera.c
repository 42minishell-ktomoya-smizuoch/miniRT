/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 11:37:15 by smizuoch          #+#    #+#             */
/*   Updated: 2024/06/04 11:37:16 by smizuoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include <math.h>

t_vec3	random_in_unit_disk(void);

t_camera	camera_new(t_vec3 lookfrom, t_vec3 lookat, t_vec3 vup, double vfov,
		double aspect_ratio, double aperture, double focus_dist, double time0,
		double time1)
{
	t_camera	cam;
	double		theta;
	double		h;
	double		viewport_height;
	double		viewport_width;

	theta = vfov * M_PI / 180.0;
	h = tan(theta / 2);
	viewport_height = 2.0 * h;
	viewport_width = aspect_ratio * viewport_height;
	cam.w = vec_normalize(vec_sub(lookfrom, lookat));
	cam.u = vec_normalize(vec_cross(vup, cam.w));
	cam.v = vec_cross(cam.w, cam.u);
	cam.origin = lookfrom;
	cam.horizontal = vec_scalar(cam.u, viewport_width * focus_dist);
	cam.vertical = vec_scalar(cam.v, viewport_height * focus_dist);
	cam.lower_left_corner = vec_sub(vec_sub(vec_sub(cam.origin,
				vec_scalar(cam.horizontal, 0.5)), vec_scalar(cam.vertical, 0.5)),
			vec_scalar(cam.w, focus_dist));
	cam.lens_radius = aperture / 2;
	cam.time0 = time0;
	cam.time1 = time1;
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
				vec_scalar(cam->horizontal, s)), vec_scalar(cam->vertical, t)),
			cam->origin);
	ray.direction = vec_sub(ray.direction, offset);
	ray.time = time;
	return (ray);
}

t_vec3	random_in_unit_disk(void)
{
	t_vec3	p;

	do {
		p = vec_new(random_double(), random_double(), 0);
		p = vec_scalar(p, 2.0);
		p = vec_sub(p, vec_new(1, 1, 0));
	} while (vec_dot(p, p) >= 1.0);
	return (p);
}