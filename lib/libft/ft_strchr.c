/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 10:57:58 by smizuoch          #+#    #+#             */
/*   Updated: 2023/06/01 15:12:33 by smizuoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != (char) c)
	{
		if (*s == '\0')
			return (NULL);
		s ++;
	}
	return ((char *)s);
}

/* #include <stdio.h>
#include <string.h>

char *ft_strchr(const char *s, int c);

int main(void)
{
    char *s = "Hello World";
    int c = '\0';
    char *result;

    result = ft_strchr(s, c);
    if (result != 0)
        printf("'%c' found at position %ld in '%s'\n", c, result - s, s);
    else
        printf("'%c' not found in '%s'\n", c, s);

    result = strchr(s, c);
    if (result != 0)
        printf("'%c' found at position %ld in '%s'\n", c, result - s, s);
    else
        printf("'%c' not found in '%s'\n", c, s);

    return 0;
} */