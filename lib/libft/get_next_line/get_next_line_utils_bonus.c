/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <ktomoya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 13:48:24 by ktomoya           #+#    #+#             */
/*   Updated: 2023/06/26 15:35:46 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(const char *s, int c)
{
	if (s == NULL)
		return (NULL);
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == '\0' && (char)c == '\0')
		return ((char *)s);
	return (NULL);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*memory;
	size_t	i;

	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	if (count > SIZE_MAX / size)
		return (NULL);
	memory = (void *)malloc(size * count);
	if (memory == NULL)
	{
		errno = ENOMEM;
		return (NULL);
	}
	i = 0;
	while (i < count * size)
	{
		memory[i] = '\0';
		i++;
	}
	return (memory);
}

size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (s[count] != '\0')
		count++;
	return (count);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dst_ptr;
	unsigned char	*src_ptr;
	size_t			i;

	dst_ptr = (unsigned char *)dst;
	src_ptr = (unsigned char *)src;
	i = 0;
	if (dst <= src)
	{
		while (i < len)
		{
			dst_ptr[i] = src_ptr[i];
			i++;
		}
	}
	else
	{
		while (len-- > 0)
			dst_ptr[len] = src_ptr[len];
	}
	return (dst);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	char	*newstr;

	newstr = NULL;
	if (s2 == NULL)
		return (NULL);
	if (s1 == NULL)
	{
		s1 = (char *)ft_calloc(1, sizeof(char));
		if (s1 == NULL)
			return (NULL);
	}
	newstr = (char *)ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (newstr == NULL)
	{
		free(s1);
		return (NULL);
	}
	ft_memmove(newstr, s1, ft_strlen(s1));
	ft_memmove(&newstr[ft_strlen(s1)], s2, ft_strlen(s2));
	free(s1);
	return (newstr);
}
