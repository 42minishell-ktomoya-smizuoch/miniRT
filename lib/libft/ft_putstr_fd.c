/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 10:02:30 by smizuoch          #+#    #+#             */
/*   Updated: 2024/06/08 19:11:04 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_putstr_fd(const char *s, int fd)
{
	if (s == NULL)
		return ;
	write (fd, s, ft_strlen(s));
}

/* int main(void)
{
  ft_putstr_fd("hello world", 1);
  return 0;
} */
