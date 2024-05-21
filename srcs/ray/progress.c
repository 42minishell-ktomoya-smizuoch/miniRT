/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   progress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 14:55:07 by smizuoch          #+#    #+#             */
/*   Updated: 2024/05/21 13:10:43 by smizuoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minirt.h"

// void	print_progress(int current, int total)
// {
// 	int		bar_width;
// 	float	progress;
// 	int		pos;
// 	int		i;

// 	bar_width = 70;
// 	progress = (float)current / total;
// 	pos = bar_width * progress;
// 	printf("[");
// 	i = 0;
// 	while (i < bar_width)
// 	{
// 		if (i < pos)
// 			printf("=");
// 		else if (i == pos)
// 			printf(">");
// 		else
// 			printf(" ");
// 		i++;
// 	}
// 	printf("] %d%%", (int)(progress * 100.0));
// 	if (current < total)
// 		printf("\r");
// 	else
// 		printf("\n");
// }

//test
void	print_progress(int current, int total)
{
	int		bar_width;
	float	progress;
	int		pos;
	int		i;

	bar_width = 70;
	progress = (float)current / total;
	pos = bar_width * progress;
	printf("[");
	i = 0;
	while (i < bar_width)
	{
		if (i < pos)
			printf("=");
		else if (i == pos)
			printf(">");
		else
			printf(" ");
		i++;
	}
	printf("] %d%%\r", (int)(progress * 100.0));
	fflush(stdout);
}
