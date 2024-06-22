/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 17:07:47 by ktomoya           #+#    #+#             */
/*   Updated: 2024/06/22 21:58:46 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	print_camera(t_camera camera)
{
	printf("----------------------------camera---------------------------------\n"
	"origin.x : %lf\n"
		"origin.y : %lf\n"
		"origin.z : %lf\n"
		"normal.x : %lf\n"
		"normal.y : %lf\n"
		"normal.z : %lf\n"
		"lower.x  : %lf\n"
		"lower.y  : %lf\n"
		"lower.z  : %lf\n"
		"horize.x : %lf\n"
		"horize.y : %lf\n"
		"horize.z : %lf\n"
		"vert.x   : %lf\n"
		"vert.y   : %lf\n"
		"vert.z   : %lf\n"
		"u.x      : %lf\n"
		"u.y      : %lf\n"
		"u.z      : %lf\n"
		"v.x      : %lf\n"
		"v.y      : %lf\n"
		"v.z      : %lf\n"
		"w.x      : %lf\n"
		"w.y      : %lf\n"
		"w.z      : %lf\n"
		"fov      : %lf\n"
		"radius   : %lf\n"
		"distance : %lf\n"
		"time0    : %lf\n"
		"time1    : %lf\n",
		camera.origin.x, camera.origin.y, camera.origin.z,
		camera.normal.x, camera.normal.y, camera.normal.z,
		camera.lower_left_corner.x, camera.lower_left_corner.y, camera.lower_left_corner.z,
		camera.horizontal.x, camera.horizontal.y, camera.horizontal.z,
		camera.vertical.x, camera.vertical.y, camera.vertical.z,
		camera.u.x, camera.u.y, camera.u.z,
		camera.v.x, camera.v.y, camera.v.z,
		camera.w.x, camera.w.y, camera.w.z,
		camera.fov, camera.lens_radius, camera.focus_distance,
		camera.time0, camera.time1);
}

void	print_struct(t_data data)
{
	printf("-----------------------------ambient-----------------------------------\n"
       "ratio     : %lf\n"
       "color.r   : %lf\n"
       "color.g   : %lf\n"
       "color.b   : %lf\n",
       data.ambient.ratio, data.ambient.color.r, data.ambient.color.g, data.ambient.color.b);

	print_camera(data.camera);

	printf("----------------------------light----------------------------------\n"
       "origin.x  : %lf\n"
       "origin.y  : %lf\n"
       "origin.z  : %lf\n"
       "intensity : %lf\n"
       "color.r   : %lf\n"
       "color.g   : %lf\n"
       "color.b   : %lf\n",
       data.light.position.x, data.light.position.y, data.light.position.z, 
       data.light.intensity, data.light.color.r, data.light.color.g, data.light.color.b);

	printf("----------------------------sphere---------------------------------\n"
       "center.x  : %lf\n"
       "center.y  : %lf\n"
       "center.z  : %lf\n"
       "diameter  : %lf\n"
       "color.r   : %lf\n"
       "color.g   : %lf\n"
       "color.b   : %lf\n"
       "material  : %d\n",
       data.sphere.center.x, data.sphere.center.y, data.sphere.center.z, 
       data.sphere.diameter, data.sphere.color.r, data.sphere.color.g, data.sphere.color.b,
	   data.sphere.material);

	printf("----------------------------plane----------------------------------\n"
       "point.x  : %lf\n"
       "point.y  : %lf\n"
       "point.z  : %lf\n"
       "normal.x  : %lf\n"
       "normal.y  : %lf\n"
       "normal.z  : %lf\n"
       "color.r   : %lf\n"
       "color.g   : %lf\n"
       "color.b   : %lf\n"
       "material  : %d\n",
       data.plane.point.x, data.plane.point.y, data.plane.point.z, 
       data.plane.normal.x, data.plane.normal.y, data.plane.normal.z, 
       data.plane.color.r, data.plane.color.g, data.plane.color.b,
	   data.plane.material);

	printf("----------------------------cylinder-------------------------------\n"
       "center.x   : %lf\n"
       "center.y   : %lf\n"
       "center.z   : %lf\n"
       "axisnorm.x : %lf\n"
       "axisnorm.y : %lf\n"
       "axisnorm.z : %lf\n"
       "diameter   : %lf\n"
       "height     : %lf\n"
       "color.r    : %lf\n"
       "color.g    : %lf\n"
       "color.b    : %lf\n"
       "material   : %d\n",
       data.cylinder.center.x, data.cylinder.center.y, data.cylinder.center.z, 
       data.cylinder.axisnorm.x, data.cylinder.axisnorm.y, data.cylinder.axisnorm.z, 
       data.cylinder.diameter, data.cylinder.height, 
       data.cylinder.color.r, data.cylinder.color.g, data.cylinder.color.b,
	   data.cylinder.material);
	printf("----------------------------rectangle------------------------------\n");
    printf("p0.x       : %f\n", data.rectangle.p0.x);
    printf("p0.y       : %f\n", data.rectangle.p0.y);
    printf("p0.z       : %f\n", data.rectangle.p0.z);
    printf("p1.x       : %f\n", data.rectangle.p1.x);
    printf("p1.y       : %f\n", data.rectangle.p1.y);
    printf("p1.z       : %f\n", data.rectangle.p1.z);
    printf("p2.x       : %f\n", data.rectangle.p2.x);
    printf("p2.y       : %f\n", data.rectangle.p2.y);
    printf("p2.z       : %f\n", data.rectangle.p2.z);
    printf("p3.x       : %f\n", data.rectangle.p3.x);
    printf("p3.y       : %f\n", data.rectangle.p3.y);
    printf("p3.z       : %f\n", data.rectangle.p3.z);
    printf("normal.x   : %f\n", data.rectangle.normal.x);
    printf("normal.y   : %f\n", data.rectangle.normal.y);
    printf("normal.z   : %f\n", data.rectangle.normal.z);
    printf("color.r    : %f\n", data.rectangle.color.r);
    printf("color.g    : %f\n", data.rectangle.color.g);
    printf("color.b    : %f\n", data.rectangle.color.b);
    printf("material   : %d\n", data.rectangle.material);
}
