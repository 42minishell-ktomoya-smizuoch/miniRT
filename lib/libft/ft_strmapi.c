/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 09:29:54 by smizuoch          #+#    #+#             */
/*   Updated: 2023/06/01 13:30:37 by smizuoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t			len;
	unsigned int	i;
	char			*new_s;

	i = 0;
	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	new_s = malloc (len + 1);
	if (new_s == NULL)
		return (NULL);
	while (i < len)
	{
		new_s[i] = f(i, s[i]);
		i ++;
	}
	new_s[i] = '\0';
	return (new_s);
}
