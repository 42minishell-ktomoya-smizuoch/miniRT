/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 11:33:37 by smizuoch          #+#    #+#             */
/*   Updated: 2023/06/01 19:35:37 by smizuoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*save;

	save = NULL;
	while (*s != '\0')
	{
		if (*s == (char) c)
			save = (char *)s;
		s ++;
	}
	if (*s == (char) c)
		save = (char *)s;
	return (save);
}

/* #include <stdio.h>
#include <string.h>

int main(void)
{
    char *s = "Hello World";
    int c = 'l';
    char *result;

    result = ft_strrchr(s, c);
    if (result != 0)
        printf("'%c' found at position %ld in '%s'\n", c, result - s, s);
    else
        printf("'%c' not found in '%s'\n", c, s);

    result = strrchr(s, c);
    if (result != 0)
        printf("'%c' found at position %ld in '%s'\n", c, result - s, s);
    else
        printf("'%c' not found in '%s'\n", c, s);

    return 0;
} */