/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 14:51:22 by smizuoch          #+#    #+#             */
/*   Updated: 2023/06/01 15:08:36 by smizuoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *) dest;
	s = (unsigned char *) src;
	if (d < s)
	{
		while (n)
		{
			*d ++ = *s ++;
			n --;
		}
	}
	else if (d > s)
	{
		d += n - 1;
		s += n - 1;
		while (n)
		{
			*d-- = *s--;
			n --;
		}
	}
	return (dest);
}

/* #include <string.h>
#define BUFSIZE 64
#define BEGIN 3
#define N 5

int main(void)
{
  char str[] = "00010203040506070800";
  char s[BUFSIZE], t[BUFSIZE];
  size_t len;
 
  len = strlen(str) + 1;
 
  ft_memmove(s, str, len);
  ft_memmove(t, str, len);
  printf("ft_memmove(): s = %s, t = %s\n", s, t);

  ft_memmove(t + BEGIN, t, N);
  printf("ft_memmove(): t = %s\n", t);
  ft_memmove(t, t + BEGIN, N);
  printf("ft_memmove(): t = %s\n", t);
 
  return 0;
} */
