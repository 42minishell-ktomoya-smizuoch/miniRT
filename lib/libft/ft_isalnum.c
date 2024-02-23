/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:55:24 by smizuoch          #+#    #+#             */
/*   Updated: 2023/06/07 11:18:12 by smizuoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_isalnum(int c)
{
	return (ft_isdigit(c) || ft_isalpha(c));
}

/*int	main(void)
{
	printf("%d\n",ft_isalnum('a'));
	printf("%d\n",isalnum('a'));
	printf("%d\n",ft_isalnum('9'));
	printf("%d\n",isalnum('9'));
	printf("%d\n",ft_isalnum('*'));
	printf("%d\n",isalnum('*'));
}*/
