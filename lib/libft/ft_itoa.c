/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 18:35:00 by smizuoch          #+#    #+#             */
/*   Updated: 2023/06/04 13:32:43 by smizuoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static char	*numfill(int n, int i, long int j, char *dest)
{
	dest[i] = '\0';
	j = n;
	if (j < 0)
		j *= -1;
	while (i)
	{
		dest[i - 1] = j % 10 + '0';
		j /= 10;
		i --;
	}
	if (n < 0)
		dest[0] = '-';
	return (dest);
}

char	*ft_itoa(int n)
{
	int			i;
	long int	j;
	char		*dest;

	j = n;
	i = 0;
	if (n <= 0)
	{
		i = 1;
		j *= -1;
	}
	while (j)
	{
		j /= 10;
		i ++;
	}
	dest = malloc(i + 1);
	if (dest == NULL)
		return (NULL);
	dest = numfill(n, i, j, dest);
	return (dest);
}

/* int	main(void)
{
	char *str;

	str = ft_itoa(-123);
	printf("%s\n", str);
} */