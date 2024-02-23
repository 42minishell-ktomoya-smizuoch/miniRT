/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 15:11:33 by smizuoch          #+#    #+#             */
/*   Updated: 2023/06/01 15:07:32 by smizuoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	size;

	size = 0;
	if (s == NULL)
		return (NULL);
	if (ft_strlen(s) > len)
		dest = malloc(len + 1);
	else
		dest = malloc(ft_strlen(s) + 1);
	if (dest == NULL)
		return (NULL);
	if (ft_strlen(s) < start)
		len = 0;
	while (size < len && s[start + size])
	{
		dest[size] = s[start + size];
		size ++;
	}
	dest[size] = '\0';
	return (dest);
}

/* int main(void)
{
char *s = "Hello,,world,g";
char *sub = ft_substr(s, 7, 5);

printf("%s\n", sub);
} */