/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 16:28:41 by smizuoch          #+#    #+#             */
/*   Updated: 2024/06/11 17:15:28 by smizuoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"
#include <stdlib.h>

t_light	new_light(t_vec3 position, t_color color, double intensity)
{
	t_light	light;

	light.position = position;
	light.color = color;
	light.intensity = intensity;
	return (light);
}

t_light_list	new_light_list(int count)
{
	t_light_list	list;

	list.lights = (t_light *)xmalloc(count * sizeof(t_light));
	list.count = 0;
	return (list);
}

void	add_light(t_light_list *list, t_light light)
{
	list->lights[list->count] = light;
	list->count++;
}
