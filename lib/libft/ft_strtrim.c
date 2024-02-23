/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 16:34:05 by smizuoch          #+#    #+#             */
/*   Updated: 2023/05/27 13:08:28 by smizuoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static size_t	ft_strtrim_left(char const *s1, char const *set)
{
	size_t	i;

	i = 0;
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	return (i);
}

static size_t	ft_strtrim_right(char const *s1, char const *set)
{
	size_t	i;

	i = ft_strlen(s1) - 1;
	while (i > 0 && ft_strchr(set, s1[i]))
		i--;
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	size_t	left;
	size_t	right;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	left = ft_strtrim_left(s1, set);
	right = ft_strtrim_right(s1, set);
	if (left > right)
		return (ft_strdup(""));
	len = right - left + 1;
	str = ft_substr(s1, left, len);
	if (!str)
		return (NULL);
	return (str);
}

/* int	main(void)
{
	char s1[] = "hello world";
	char *sub = ft_strtrim(s1, "");

	printf("%s\n", sub);
} */