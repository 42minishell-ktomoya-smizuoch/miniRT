/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 15:51:22 by smizuoch          #+#    #+#             */
/*   Updated: 2024/06/21 13:59:25 by smizuoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CYLINDER_H
# define CYLINDER_H

# include "hittable.h"
# include "minirt.h"

typedef struct s_side
{
	t_vec3	oc;
	t_vec3	axis;
	double	a;
	double	half_b;
	double	c;
	double	discriminant;
	double	sqrt_d;
	double	root;
	t_vec3	point;
	t_vec3	relative_point;
	double	height_along_axis;
}	t_side;

t_hittable	new_cylinder(t_cylinder c);
int			hit_cylinder_side(t_cylinder *cyl,
				t_ray *ray, t_limits l, t_hit_record *rec);

#endif
