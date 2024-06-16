/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dielectric.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 16:19:59 by smizuoch          #+#    #+#             */
/*   Updated: 2024/06/15 17:48:06 by smizuoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dielectric.h"
#include <stdlib.h>
#include <math.h>

typedef struct s_dielectric
{
	t_vec3	center;
	double	radius;
	double	ref_idx;
}	t_dielectric;

typedef struct s_hit_dielectric
{
	double	a;
	double	half_b;
	double	c;
	double	discriminant;
	double	sqrt_d;
	double	root;
}	t_hit_dielectric;

t_vec3	refract(t_vec3 uv, t_vec3 n, double etai_over_etat)
{
	double	cos_theta;
	t_vec3	r_out_perp;
	t_vec3	r_out_parallel;

	cos_theta = fmin(vec_dot(vec_scalar(uv, -1), n), 1.0);
	r_out_perp = vec_scalar(vec_add(uv, vec_scalar(n, cos_theta)), etai_over_etat);
	r_out_parallel = vec_scalar(n, -sqrt(fabs(1.0 - vec_dot(r_out_perp, r_out_perp))));
	return (vec_add(r_out_perp, r_out_parallel));
}

double	schlick(double cosine, double ref_idx)
{
	double	r0;

	r0 = (1 - ref_idx) / (1 + ref_idx);
	r0 = r0 * r0;
	return (r0 + (1 - r0) * pow((1 - cosine), 5));
}

int	hit_dielectric(t_hittable *self, t_ray *ray, t_limits l, t_hit_record *rec)
{
	t_dielectric	*dielectric;
	t_vec3			oc;
	t_hit_dielectric	d;
	t_vec3			outward_normal;

	dielectric = (t_dielectric *)self->data;
	oc = vec_sub(ray->origin, dielectric->center);
	d.a = vec_dot(ray->direction, ray->direction);
	d.half_b = vec_dot(oc, ray->direction);
	d.c = vec_dot(oc, oc) - dielectric->radius * dielectric->radius;
	d.discriminant = d.half_b * d.half_b - d.a * d.c;
	if (d.discriminant < 0)
		return (0);
	d.sqrt_d = sqrt(d.discriminant);
	d.root = (-d.half_b - d.sqrt_d) / d.a;
	if (d.root < l.min || d.root > l.max)
	{
		d.root = (-d.half_b + d.sqrt_d) / d.a;
		if (d.root < l.min || d.root > l.max)
			return (0);
	}
	rec->t = d.root;
	rec->point = ray_at(*ray, rec->t);
	outward_normal = vec_normalize(vec_sub(rec->point, dielectric->center));
	set_face_normal_with_radius(rec, ray, outward_normal, dielectric->radius);
	rec->color = (t_color){1.0, 1.0, 1.0};
	rec->fuzz = 0;
	rec->ref_idx = dielectric->ref_idx;
	rec->material = DIELECTRIC;
	return (1);
}

t_hittable	new_dielectric(t_vec3 center, double radius, double ref_idx)
{
	t_dielectric	*dielectric_data;
	t_hittable		hittable_dielectric;

	dielectric_data = xmalloc(sizeof(t_dielectric));
	dielectric_data->center = center;
	dielectric_data->radius = radius;
	dielectric_data->ref_idx = ref_idx;
	hittable_dielectric.data = dielectric_data;
	hittable_dielectric.hit = hit_dielectric;
	return (hittable_dielectric);
}
