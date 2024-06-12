/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sscanf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 16:08:20 by smizuoch          #+#    #+#             */
/*   Updated: 2024/06/12 16:59:25 by smizuoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdarg.h>
#include <limits.h>
#include <stdint.h>
#include <ctype.h>

int	skip_atoi(const char **s)
{
	int	i;

	i = 0;
	while (ft_isdigit(**s))
		i = i * 10 + *((*s)++) - '0';
	return (i);
}

void	handle_char(const char **str, va_list args, int field_width, int *num)
{
	char	*s;

	s = (char *)va_arg(args, char *);
	if (field_width == -1)
		field_width = 1;
	while (field_width > 0 && **str)
	{
		*s++ = **str;
		(*str)++;
		field_width--;
	}
	(*num)++;
}

void	handle_string(const char **str, va_list args, int field_width, int *num)
{
	char	*s;

	s = (char *)va_arg(args, char *);
	if (field_width == -1)
		field_width = INT_MAX;
	while (ft_isspace(**str))
		(*str)++;
	while (**str && !ft_isspace(**str) && field_width--)
	{
		*s++ = **str;
		(*str)++;
	}
	*s = '\0';
	(*num)++;
}

void	handle_percent(const char **str, int *num)
{
	if (**str == '%')
	{
		(*str)++;
		(*num)++;
	}
}

void	handle_n(const char *buf, const char **str, va_list args)
{
	int	*i;

	i = (int *)va_arg(args, int *);
	*i = *str - buf;
}
