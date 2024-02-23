/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 10:46:06 by smizuoch          #+#    #+#             */
/*   Updated: 2023/05/19 14:00:51 by smizuoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_tolower(int c)
{
	if (65 <= c && c <= 90)
		return (c + 32);
	return (c);
}

/* #include<stdio.h>
int	main(void)
{
	printf ("%d\n", ft_tolower('A'));
	printf ("%d\n", ft_tolower('a'));
	printf ("%d\n", ft_tolower('Z'));
	printf ("%d\n", ft_tolower('z'));
	printf ("%d\n", ft_tolower('1'));
} */