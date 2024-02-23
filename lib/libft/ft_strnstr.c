/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 11:47:56 by smizuoch          #+#    #+#             */
/*   Updated: 2023/06/01 15:12:49 by smizuoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*p;
	size_t	l;

	if (haystack == NULL && needle != NULL && len != 0)
		p = (char *) haystack;
	else if (haystack == NULL)
		return (NULL);
	if (!*needle)
		return ((char *) haystack);
	p = (char *) haystack;
	l = ft_strlen (needle);
	while (*p && len >= l)
	{
		if (ft_strncmp (p, needle, l) == 0)
			return (p);
		p ++;
		len --;
	}
	return (NULL);
}

/* int main(void) {
  char *big = "Hello, world!";
  char *little = "world";

  char *pos = ft_strnstr(big, little, 13);

  if (pos != NULL) {
    printf("Found `world` at %p\n", pos);
  } else {
    printf("Did not find `world`\n");
  }

  return 0;
} */