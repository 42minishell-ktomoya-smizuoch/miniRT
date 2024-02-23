/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:10:38 by smizuoch          #+#    #+#             */
/*   Updated: 2023/05/19 13:59:47 by smizuoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_isalpha(int c)
{
	return (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z'));
}

/*int	main(void)
{
	printf("%d\n",ft_isalpha('u'));
	printf("%d",isalpha('a'));
	printf("%d",isalpha('A'));
	printf("%d",isalpha('1'));
	return 0;
}*/
