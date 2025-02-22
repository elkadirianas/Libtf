/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkadir <aelkadir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:08:12 by aelkadir          #+#    #+#             */
/*   Updated: 2024/11/06 09:56:13 by aelkadir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr_fd_1(long n, int fd)
{
	char	c;

	if (n < 0)
	{
		n = -n;
		write(fd, "-", 1);
	}
	if (n > 9)
		ft_putnbr_fd_1(n / 10, fd);
	c = n % 10 + '0';
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (fd < 0)
		return ;
	ft_putnbr_fd_1(n, fd);
}
