/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 11:18:42 by smizuoch          #+#    #+#             */
/*   Updated: 2023/06/17 12:01:00 by smizuoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line_bonus.h"

size_t	ft_strlens(const char *s)
{
	size_t	c;

	c = 0;
	if (!s)
		return (0);
	while (s[c])
		c ++;
	return (c);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	size_t	size;
	size_t	i;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	size = ft_strlens (s1) + ft_strlens (s2) + 1;
	dest = malloc(size);
	if (dest == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		dest[i] = s1[i];
		i ++;
	}
	while (*s2 != '\0')
	{
		dest[i] = *s2;
		i ++;
		s2 ++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s != (char) c)
	{
		if (*s == '\0')
			return (NULL);
		s ++;
	}
	return ((char *)s);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	size;

	size = 0;
	if (s == NULL)
		return (NULL);
	if (ft_strlens(s) > len)
		dest = malloc(len + 1);
	else
		dest = malloc(ft_strlens(s) + 1);
	if (dest == NULL)
		return (NULL);
	if (ft_strlens(s) < start)
		len = 0;
	while (size < len && s[start + size])
	{
		dest[size] = s[start + size];
		size ++;
	}
	dest[size] = '\0';
	return (dest);
}
