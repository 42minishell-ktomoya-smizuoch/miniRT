/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 13:59:14 by smizuoch          #+#    #+#             */
/*   Updated: 2023/05/30 14:19:07 by smizuoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static long int	check_overflow(long long n, int sign, const char *str)
{
	if (n * sign > LONG_MAX / 10)
		return (LONG_MAX);
	else if (n * sign < LONG_MIN / 10)
		return (LONG_MIN);
	if (n * sign == LONG_MAX / 10 && *str >= '7')
		return (LONG_MAX);
	else if (n * sign == LONG_MIN / 10 && *str >= '8')
		return (LONG_MIN);
	return (1);
}

int	ft_atoi(const char *str)
{
	long long int	n;
	int				sign;
	int				ret;

	n = 0;
	ret = 0;
	sign = 1;
	while ((9 <= *str && *str <= 13) || *str == 32)
		str ++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str ++;
	}
	while ('0' <= *str && *str <= '9')
	{
		ret = check_overflow(n, sign, str);
		if (ret != 1)
			return (ret);
		n = n * 10 + (*str - '0');
		str ++;
	}
	return ((int)n * sign);
}

/* #include <stdlib.h>
int	main(void)
{
	printf ("%d\n", ft_atoi("-100"));
	printf ("%d\n", atoi("-100"));
	printf ("%d\n", ft_atoi("206"));
	printf ("%d\n", atoi("206"));
} */
