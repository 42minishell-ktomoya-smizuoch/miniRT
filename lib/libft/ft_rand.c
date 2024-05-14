/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rand.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 08:30:08 by smizuoch          #+#    #+#             */
/*   Updated: 2024/05/15 08:36:15 by smizuoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

unsigned long int	g_next = 1;

int	ft_rand(void)
{
	g_next = g_next * 1664525 + 1013904223;
	return ((unsigned int)(g_next >> 16) & 0x7FFF);
}

void	ft_srand(unsigned int seed)
{
	g_next = seed;
}

// int main() {
//     ft_srand(12345);  // シードを設定
//     for (int i = 0; i < 10; i++) {
//         printf("%d\n", ft_rand());
//     }
//     return 0;
// }
