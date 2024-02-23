/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 15:59:38 by smizuoch          #+#    #+#             */
/*   Updated: 2023/05/25 14:31:25 by smizuoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	size_t	size;
	size_t	i;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	size = ft_strlen (s1) + ft_strlen (s2) + 1;
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

/* int	main(void)
{
	char *s1 = "Hello, ";
	char *s2 = "world!";
	char *sub = ft_strjoin(s1, s2);

	printf("%s\n", sub);
} */
