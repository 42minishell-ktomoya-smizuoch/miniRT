/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rectangle.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 16:15:14 by smizuoch          #+#    #+#             */
/*   Updated: 2024/06/15 16:43:43 by smizuoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RECTANGLE_H
# define RECTANGLE_H

# include "minirt.h"
# include "hittable.h"

typedef struct s_rectangle
{
	t_vec3			p0;
	t_vec3			p1;
	t_vec3			p2;
	t_vec3			p3;
	t_vec3			normal;
	t_material_type	material;
	t_color			color;
}	t_rectangle;

t_hittable	new_rectangle(t_vec3 p0, t_vec3 p1, t_vec3 p2, t_vec3 p3, t_vec3 normal, t_color color, t_material_type material);

#endif
