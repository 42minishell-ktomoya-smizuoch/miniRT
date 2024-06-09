/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 15:50:53 by smizuoch          #+#    #+#             */
/*   Updated: 2024/06/09 15:50:54 by smizuoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "minirt.h"

t_camera	camera_new(t_vec3 lookfrom, t_vec3 lookat, t_vec3 vup, double vfov, double aspect_ratio, double aperture, double focus_dist, double time0, double time1);
t_ray		get_ray(t_camera *cam, double s, double t);

#endif
