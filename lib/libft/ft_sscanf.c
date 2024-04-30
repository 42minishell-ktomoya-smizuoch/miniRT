/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sscanf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 12:32:44 by smizuoch          #+#    #+#             */
/*   Updated: 2024/04/30 13:34:30 by smizuoch         ###   ########.fr       */
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
	int		count;
	int		*ip;
	char	*s;
	char	*c;

	count = 0;
	(*p)++;
	if (**p == 'd')
	{
		ip = va_arg(args, int *);
		*ip = read_int(str, count++);
	}
	else if (**p == 's')
	{
		s = va_arg(args, char *);
		read_str(str, s, count++);
	}
	else if (**p == 'c')
	{
		c = va_arg(args, char *);
		read_char(str, c, count++);
	}
	(*p)++;
	return (count);
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
