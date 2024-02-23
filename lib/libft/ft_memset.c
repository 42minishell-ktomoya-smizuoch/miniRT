/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:05:50 by smizuoch          #+#    #+#             */
/*   Updated: 2023/06/01 19:26:56 by smizuoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			count;

	str = (unsigned char *) s;
	count = 0;
	while (n)
	{
		str[count] = c;
		count ++;
		n --;
	}
	return (s);
}

/* int	main(void)
{
	char s[7] = "123456";
	int n;
	int c;
    char a;

    n = 5;
    a = 'a';
    c = 0;
    ft_memset(s, a, n);
    n ++;
    while(n)
    {
        write (1, &s[c], 1);
        n --;
        c ++;
    }
} */
