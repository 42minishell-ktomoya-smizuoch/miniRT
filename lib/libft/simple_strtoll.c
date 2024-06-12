/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_strtoll.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:36:34 by smizuoch          #+#    #+#             */
/*   Updated: 2024/06/12 15:49:40 by smizuoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	determine_base(const char **cp)
{
	unsigned int	base;

	base = 10;
	if (**cp == '0')
	{
		base = 8;
		(*cp)++;
		if ((**cp == 'x') && ft_isxdigit((*cp)[1]))
		{
			(*cp)++;
			base = 16;
		}
	}
	return (base);
}

unsigned long long	convert_to_ullong(const char *cp,
						unsigned int base, char **endp)
{
	unsigned long long	result;
	unsigned long long	value;

	result = 0;
	while (ft_isxdigit(*cp))
	{
		if (ft_isdigit(*cp))
			value = *cp - '0';
		else if (ft_islower(*cp))
			value = ft_toupper(*cp) - 'A' + 10;
		else
			value = *cp - 'A' + 10;
		if (value >= base)
			break ;
		result = result * base + value;
		cp++;
	}
	if (endp)
		*endp = (char *)cp;
	return (result);
}

unsigned long long	simple_strtoull(const char *cp,
					char **endp, unsigned int base)
{
	if (!base)
		base = determine_base(&cp);
	return (convert_to_ullong(cp, base, endp));
}

long long	simple_strtoll(const char *cp, char **endp, unsigned int base)
{
	if (*cp == '-')
		return (-simple_strtoull(cp + 1, endp, base));
	return (simple_strtoull(cp, endp, base));
}
