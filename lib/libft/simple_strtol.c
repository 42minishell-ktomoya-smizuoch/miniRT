/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_strtol.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:30:39 by smizuoch          #+#    #+#             */
/*   Updated: 2024/06/12 15:50:38 by smizuoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long	parse_base(const char **cp)
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

unsigned long	convert_to_ulong(const char *cp,
				unsigned int base, char **endp)
{
	unsigned long	result;
	unsigned long	value;

	result = 0;
	while (ft_isxdigit(*cp))
	{
		if (ft_isdigit(*cp))
			value = *cp - '0';
		else
			value = ft_toupper(*cp) - 'A' + 10;
		if (value >= base)
			break ;
		result = result * base + value;
		cp++;
	}
	if (endp)
		*endp = (char *)cp;
	return (result);
}

unsigned long	simple_strtoul(const char *cp,
				char **endp, unsigned int base)
{
	if (!base)
		base = parse_base(&cp);
	return (convert_to_ulong(cp, base, endp));
}

long	simple_strtol(const char *cp, char **endp, unsigned int base)
{
	if (*cp == '-')
		return (-simple_strtoul(cp + 1, endp, base));
	return (simple_strtoul(cp, endp, base));
}
