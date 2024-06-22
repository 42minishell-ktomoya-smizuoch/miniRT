/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xmalloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 14:00:38 by smizuoch          #+#    #+#             */
/*   Updated: 2024/06/12 15:47:12 by smizuoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*xmalloc(size_t size)
{
	void	*ptr;

	errno = 0;
	ptr = malloc(size);
	if (!ptr || errno != 0)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	return (ptr);
}
