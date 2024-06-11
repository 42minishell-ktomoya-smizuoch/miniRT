/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 16:15:01 by smizuoch          #+#    #+#             */
/*   Updated: 2024/06/09 16:15:55 by smizuoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLANE_H
# define PLANE_H

# include "minirt.h"
# include "hittable.h"

t_hittable	new_plane(t_vec3 point, t_vec3 normal,
				t_color color, t_material_type material);

#endif
