/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 11:09:09 by smizuoch          #+#    #+#             */
/*   Updated: 2023/06/01 19:25:19 by smizuoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*str1;
	const unsigned char	*str2;

	str1 = (const unsigned char *)s1;
	str2 = (const unsigned char *)s2;
	while (n --)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		str1 ++;
		str2 ++;
	}
	return (0);
}

/* int	main(void)
{
	if (memcmp("Hello", "Heala", 5) == 0)
		printf ("same\n");
	else
		printf ("different\n");
	if (ft_memcmp("Hello", "Heala", 5) == 0)
		printf ("same\n");
	else
		printf ("different\n");
} */