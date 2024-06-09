/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 15:51:22 by smizuoch          #+#    #+#             */
/*   Updated: 2024/06/09 15:51:23 by smizuoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CYLINDER_H
# define CYLINDER_H

# include "hittable.h"
# include "minirt.h"

t_hittable	new_cylinder(t_vec3 center, t_vec3 axisnorm, double diameter, double height, t_color color, t_material_type material);

#endif
