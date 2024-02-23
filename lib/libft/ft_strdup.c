/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 13:35:28 by smizuoch          #+#    #+#             */
/*   Updated: 2023/05/30 16:17:57 by smizuoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static char	*mystrcpy(char *dest, const char *src)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(const char *s1)
{
	size_t	l;
	char	*t;

	l = ft_strlen(s1);
	t = malloc(l + 1);
	if (t == NULL)
		return (NULL);
	t = mystrcpy(t, s1);
	return (t);
}

/* int	main(void)
{
	char s1[] = "abcdefg";
	char *s2 = ft_strdup(s1);
	s1[2] = '3';
	printf("%s\n", s1);
	printf("%s\n", s2);
	free (s2);
} */