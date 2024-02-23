/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 10:34:24 by smizuoch          #+#    #+#             */
/*   Updated: 2023/05/19 14:00:57 by smizuoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_toupper(int c)
{
	if (97 <= c && c <= 122)
		return (c - 32);
	return (c);
}

/*#include<stdio.h>
int	main(void)
{
	printf ("%d\n", ft_toupper('A'));
	printf ("%d\n", ft_toupper('a'));
	printf ("%d\n", ft_toupper('Z'));
	printf ("%d\n", ft_toupper('z'));
	printf ("%d\n", ft_toupper('1'));
}*/