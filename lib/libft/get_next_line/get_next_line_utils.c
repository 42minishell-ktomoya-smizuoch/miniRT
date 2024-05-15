/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <ktomoya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 13:48:24 by ktomoya           #+#    #+#             */
/*   Updated: 2024/05/15 13:58:59 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
