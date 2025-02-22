/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkadir <aelkadir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:03:26 by aelkadir          #+#    #+#             */
/*   Updated: 2024/10/21 14:44:57 by aelkadir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len(long n)
{
	int	i;

	i = 1;
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n / 10 > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char	*ft_itoa1(long n)
{
	int		l;
	char	*str;
	int		sign;

	l = len(n);
	str = (char *)malloc(l + 1);
	if (!str)
		return (str);
	sign = 1;
	if (n < 0)
	{
		sign = -1;
		n = -n;
	}
	str[l--] = '\0';
	if (n == 0)
		str[0] = '0';
	while (n > 0)
	{
		str[l--] = n % 10 + '0';
		n /= 10;
	}
	if (sign == -1)
		str[0] = '-';
	return (str);
}

char	*ft_itoa(int n)
{
	return (ft_itoa1(n));
}
