/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   metal.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 16:14:13 by smizuoch          #+#    #+#             */
/*   Updated: 2024/06/09 16:14:31 by smizuoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef METAL_H
# define METAL_H

# include "minirt.h"
# include "hittable.h"

t_vec3		reflect(t_vec3 v, t_vec3 n);
t_hittable	new_metal(t_vec3 center, double radius, t_color color, double fuzz);

#endif
