/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sscanf_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 17:34:31 by smizuoch          #+#    #+#             */
/*   Updated: 2024/06/12 17:38:08 by smizuoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdarg.h>
#include <limits.h>
#include <stdint.h>
#include <ctype.h>

void	process_size_t(const char **str,
		va_list args, int base, char **next)
{
	size_t	*s;

	s = (size_t *)va_arg(args, size_t *);
	*s = (size_t)simple_strtoul(*str, next, base);
}

