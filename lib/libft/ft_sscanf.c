/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sscanf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <ktomoya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 18:45:30 by ktomoya           #+#    #+#             */
/*   Updated: 2024/06/25 18:45:40 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>

static int	read_int(const char **str, int s)
{
	int	num;
	int	sign;

	(void)s;
	num = 0;
	sign = 1;
	while (ft_isspace(**str))
		(*str)++;
	if (**str == '+' || **str == '-')
	{
		if (**str == '-')
			sign = -1;
		else
			sign = 1;
		(*str)++;
	}
	while (ft_isdigit(**str))
	{
		num = num * 10 + (**str - '0');
		(*str)++;
	}
	return (num * sign);
}

static void	read_str(const char **str, char *buf, int s)
{
	(void)s;
	while (ft_isspace(**str))
		(*str)++;
	while (**str && !ft_isspace(**str))
		*buf++ = *(*str)++;
	*buf = '\0';
}

static void	read_char(const char **str, char *c, int s)
{
	(void)s;
	while (ft_isspace(**str))
		(*str)++;
	*c = **str;
	if (**str)
		(*str)++;
}

int	parse_format(const char **str, const char **p, va_list args)
{
	t_sscanf	ss;

	ss.count = 0;
	(*p)++;
	if (**p == 'd')
	{
		ss.ip = va_arg(args, int *);
		*ss.ip = read_int(str, ss.count++);
	}
	else if (**p == 's')
	{
		ss.s = va_arg(args, char *);
		read_str(str, ss.s, ss.count++);
	}
	else if (**p == 'c')
	{
		ss.c = va_arg(args, char *);
		read_char(str, ss.c, ss.count++);
	}
	else if (**p == 'l' && *(*p + 1) == 'f' && (*p)++)
	{
		ss.dp = va_arg(args, double *);
		*ss.dp = read_double(str, ss.count++);
	}
	return ((*p)++, ss.count);
}

int	ft_sscanf(const char *str, const char *format, ...)
{
	int			count;
	va_list		args;
	const char	*p;

	va_start(args, format);
	count = 0;
	p = format;
	while (*p)
	{
		if (*p == '%')
			count += parse_format(&str, &p, args);
		else
		{
			if (ft_isspace(*p))
				while (ft_isspace(*str))
					str++;
			else if (*str != *p)
				break ;
			else
				str++;
			p++;
		}
	}
	va_end(args);
	return (count);
}
//Do not enter NULL or you will crash.