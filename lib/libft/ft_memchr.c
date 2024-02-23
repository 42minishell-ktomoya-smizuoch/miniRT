/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:05:38 by smizuoch          #+#    #+#             */
/*   Updated: 2023/06/07 14:15:54 by smizuoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;

	c = (unsigned char)c;
	str = (unsigned char *)s;
	while (n --)
	{
		if (*str == c)
			return (str);
		str ++;
	}
	return (NULL);
}

/* int	main(void)
{
	printf ("%s\n", memchr("Hello", 'l', 5));
	printf ("%s\n", ft_memchr("Hello", 'l', 5));
	printf ("%s\n", memchr("Hello", '\0', 5));
	printf ("%s\n", ft_memchr("Hello", '\0', 5));
	printf ("%s\n", memchr("", 'l', 5));
	printf ("%s\n", ft_memchr("", 'l', 5));
	printf ("%s\n", memchr("Helloabc", -159, 10));
	printf ("%s\n", ft_memchr("Helloabc", -159, 10));
} */
