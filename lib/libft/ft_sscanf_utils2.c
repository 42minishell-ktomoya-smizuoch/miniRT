/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sscanf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 17:28:31 by smizuoch          #+#    #+#             */
/*   Updated: 2024/06/12 17:32:35 by smizuoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdarg.h>
#include <limits.h>
#include <stdint.h>
#include <ctype.h>

void	process_signed_char(const char **str,
		va_list args, int base, char **next)
{
	signed char	*s;

	s = (signed char *)va_arg(args, signed char *);
	*s = (signed char)simple_strtol(*str, next, base);
}

void	process_unsigned_char(const char **str,
		va_list args, int base, char **next)
{
	unsigned char	*s;

	s = (unsigned char *)va_arg(args, unsigned char *);
	*s = (unsigned char)simple_strtoul(*str, next, base);
}

void	process_short(const char **str,
		va_list args, t_int_list i, char **next)
{
	short			*s;
	unsigned short	*t;

	if (i.is_sign)
	{
		s = (short *)va_arg(args, short *);
		*s = (short)simple_strtol(*str, next, i.base);
	}
	else
	{
		t = (unsigned short *)va_arg(args, unsigned short *);
		*t = (unsigned short)simple_strtoul(*str, next, i.base);
	}
}

void	process_long(const char **str,
		va_list args, t_int_list i, char **next)
{
	long			*l;
	unsigned long	*m;

	if (i.is_sign)
	{
		l = (long *)va_arg(args, long *);
		*l = simple_strtol(*str, next, i.base);
	}
	else
	{
		m = (unsigned long *)va_arg(args, unsigned long *);
		*m = simple_strtoul(*str, next, i.base);
	}
}

void	process_long_long(const char **str,
		va_list args, t_int_list i, char **next)
{
	long long			*l;
	unsigned long long	*m;

	if (i.is_sign)
	{
		l = (long long *)va_arg(args, long long *);
		*l = simple_strtoll(*str, next, i.base);
	}
	else
	{
		m = (unsigned long long *)va_arg(args, unsigned long long *);
		*m = simple_strtoull(*str, next, i.base);
	}
}
