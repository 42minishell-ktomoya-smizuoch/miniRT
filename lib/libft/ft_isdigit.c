/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:43:25 by smizuoch          #+#    #+#             */
/*   Updated: 2024/06/12 14:56:33 by smizuoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_isdigit(int c)
{
	return ('0' <= c && c <= '9');
}

int	ft_isxdigit(int c)
{
	return (('0' <= c && c <= '9')
		|| ('A' <= c && c <= 'F') || ('a' <= c && c <= 'f'));
}

/*int	main(void)
{
	printf("%d\n",ft_isdigit(9));
	printf("%d\n",isdigit(9));
}*/