/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 16:59:44 by smizuoch          #+#    #+#             */
/*   Updated: 2023/06/01 19:34:42 by smizuoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	destlen;
	size_t	srclen;
	size_t	s;
	size_t	n;

	if (dst == NULL)
		destlen = 0;
	else
		destlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (dstsize <= destlen)
		return (dstsize + srclen);
	s = dstsize - destlen - 1;
	n = 0;
	while (n < s)
	{
		if (src[n] == '\0')
			break ;
		dst[destlen + n] = src[n];
		n ++;
	}
	dst[n + destlen] = '\0';
	return (srclen + destlen);
}

/*#include<stdio.h>
int main(void)
{
    char src[] = "Hello, world!";
    char dst[20] = "Goodbye";
    size_t n = 10;

    printf("Before ft_strlcat: %s\n", dst);
    size_t result = ft_strlcat(dst, src, n);
    printf("After ft_strlcat: %s\n", dst);
    printf("Result: %lu\n", (unsigned long)result);

    return 0;
}*/