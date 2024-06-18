/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 17:07:47 by ktomoya           #+#    #+#             */
/*   Updated: 2024/06/17 09:43:47 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	print_struct(t_data data)
{
	printf("-----------------------------amb-----------------------------------\n"
       "ratio     : %lf\n"
       "color.r   : %lf\n"
       "color.g   : %lf\n"
       "color.b   : %lf\n",
       data.amb.ratio, data.amb.color.r, data.amb.color.g, data.amb.color.b);

	printf("----------------------------camera---------------------------------\n"
       "origin.x  : %lf\n"
       "origin.y  : %lf\n"
       "origin.z  : %lf\n"
       "normal.x  : %lf\n"
       "normal.y  : %lf\n"
       "normal.z  : %lf\n"
       "fov       : %lf\n"
       "lower.x   : %lf\n"
       "lower.y   : %lf\n"
       "lower.z   : %lf\n"
       "aperture  : %lf\n"
       "distance  : %lf\n",
       data.camera.origin.x, data.camera.origin.y, data.camera.origin.z, 
       data.camera.normal.x, data.camera.normal.y, data.camera.normal.z, 
       data.camera.fov,
	   data.camera.lower_left_corner.x, data.camera.lower_left_corner.y,
	   data.camera.lower_left_corner.z,
	   data.camera.lens_radius, data.camera.focus_distance);

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
