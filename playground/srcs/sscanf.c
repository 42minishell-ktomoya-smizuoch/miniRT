/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sscanf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 17:50:44 by ktomoya           #+#    #+#             */
/*   Updated: 2024/05/17 18:49:20 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(void)
{
	char	*buf = "A 0.2 255,255,255 0.2";
	char	type[10] = {0};
	double	d = 0.0;
	int		n[3] = {0};
	int		ret_val = 0;

	printf("buf:%s\n", buf);
	ret_val = sscanf(buf, "%s %lf %d,%d,%d", type, &d, &n[0], &n[1], &n[2]);
	printf("type:%s\n", type);
	printf("d:%lf\n", d);
	printf("n[0]:%d\n", n[0]);
	printf("n[1]:%d\n", n[1]);
	printf("n[2]:%d\n", n[2]);
	printf("return value:%d\n", ret_val);
}
