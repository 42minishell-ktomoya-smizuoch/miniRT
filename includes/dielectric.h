/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dielectric.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 15:51:40 by smizuoch          #+#    #+#             */
/*   Updated: 2024/06/09 15:51:55 by smizuoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIELECTRIC_H
# define DIELECTRIC_H

# include "minirt.h"
# include "hittable.h"

t_vec3		refract(t_vec3 uv, t_vec3 n, double etai_over_etat);
double		schlick(double cosine, double ref_idx);
t_hittable	new_dielectric(t_vec3 center, double radius, double ref_idx);

#endif
