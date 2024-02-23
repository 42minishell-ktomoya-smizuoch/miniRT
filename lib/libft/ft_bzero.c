/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:47:19 by smizuoch          #+#    #+#             */
/*   Updated: 2023/05/30 16:23:36 by smizuoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	c;
	char	*str;

	c = 0;
	str = (char *)s;
	while (n)
	{
		str[c] = 0;
		c ++;
		n --;
	}
}

/*#include<unistd.h>
#include<strings.h>
int main(void)
{
    char s[7] = "123456";
    int n;

    n = 5;
    ft_bzero(s, n);
    while(n)
    {
        write (1, &s[n], 1);
        n --;
    }
}*/
