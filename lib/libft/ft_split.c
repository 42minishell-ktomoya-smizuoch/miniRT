/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 14:42:44 by smizuoch          #+#    #+#             */
/*   Updated: 2023/06/04 13:31:26 by smizuoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static char	**ft_free(char **dest, size_t n)
{
	n --;
	while (n)
	{
		free (dest[n - 1]);
		n --;
	}
	free(dest);
	return (NULL);
}

static size_t	ft_count_words(char const *s, char c)
{
	int		flag;
	size_t	count;

	count = 0;
	flag = 0;
	while (*s)
	{
		if (*s != c && !flag)
		{
			count ++;
			flag = 1;
		}
		else if (*s == c)
			flag = 0;
		s ++;
	}
	return (count);
}

static char	*ft_search(char const *s, char c, size_t i)
{
	size_t	len;
	size_t	start;
	char	*dest;

	len = 0;
	start = i;
	while (s[i] != c && s[i] != '\0')
	{
		len ++;
		i ++;
	}
	dest = ft_substr(s, start, len);
	if (dest == NULL)
		return (NULL);
	return (dest);
}

static size_t	ft_wc(char const *s, char c, size_t i)
{
	while (s[i] == c && s[i] != '\0')
			i ++;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	n;
	char	**dest;

	i = 0;
	n = 0;
	if (s == NULL)
		return (NULL);
	dest = malloc (sizeof(char *) *(ft_count_words(s, c) + 1));
	if (dest == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		i = ft_wc(s, c, i);
		if (i < ft_strlen(s))
		{
			dest[n] = ft_search(s, c, i);
			if (dest[n ++] == NULL)
				return (ft_free(dest, n));
			while (s[i] != c && s[i] != '\0')
				i ++;
		}
	}
	dest[n] = NULL;
	return (dest);
}
