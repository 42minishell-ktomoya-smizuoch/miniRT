/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 11:08:03 by smizuoch          #+#    #+#             */
/*   Updated: 2023/05/23 11:51:14 by smizuoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	num;
	char		c;

	num = n;
	if (num < 0)
	{
		num *= -1;
		write (fd, "-", 1);
	}
	if (num / 10 > 0)
	{
		ft_putnbr_fd(num / 10, fd);
		c = num % 10 + 48;
		write (fd, &c, 1);
	}
	else
	{
		c = num % 10 + 48;
		write (fd, &c, 1);
	}
}

/* int main() {
  int n = -1234;

  ft_putnbr_fd(n, 1);

  return 0;
} */