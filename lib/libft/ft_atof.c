/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 14:38:24 by smizuoch          #+#    #+#             */
/*   Updated: 2024/04/30 15:27:55 by smizuoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static void	set(const char **str, double *num,
	double *dec, int *sign)
{
	*num = 0;
	*dec = 0;
	*sign = 1;
	while (ft_isspace(**str))
		(*str)++;
	if (**str == '+' || **str == '-')
	{
		if (**str == '-')
			*sign = -1;
		(*str)++;
	}
}

double	ft_atof(const char *str)
{
	double	num;
	double	dec;
	int		sign;
	int		dec_places;

	dec_places = 1;
	set(&str, &num, &dec, &sign);
	while (ft_isdigit(*str))
	{
		num = num * 10 + (*str - '0');
		str++;
	}
	if (*str == '.')
	{
		str++;
		while (ft_isdigit(*str))
		{
			dec = dec * 10 + (*str - '0');
			str++;
			dec_places *= 10;
		}
	}
	return ((num + dec / dec_places) * sign);
}

double	read_double(const char **str, int s)
{
	double	num;
	double	dec;
	int		sign;
	int		dec_places;

	(void)s;
	dec_places = 1;
	set(str, &num, &dec, &sign);
	while (ft_isdigit(**str))
	{
		num = num * 10 + (**str - '0');
		(*str)++;
	}
	if (**str == '.')
	{
		(*str)++;
		while (ft_isdigit(**str))
		{
			dec = dec * 10 + (**str - '0');
			(*str)++;
			dec_places *= 10;
		}
	}
	return ((num + dec / dec_places) * sign);
}
