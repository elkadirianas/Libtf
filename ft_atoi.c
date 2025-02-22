/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkadir <aelkadir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 12:58:39 by aelkadir          #+#    #+#             */
/*   Updated: 2024/10/27 19:00:22 by aelkadir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nbr)
{
	int			sign;
	long long	res;

	sign = 1;
	res = 0;
	while (*nbr == ' ' || (*nbr >= 9 && *nbr <= 13))
		nbr++;
	if (*nbr == '-' || *nbr == '+')
	{
		if (*nbr == '-')
			sign = -1;
		nbr++;
	}
	while (ft_isdigit(*nbr))
	{
		if (res > (LLONG_MAX - (*nbr - '0')) / 10)
		{
			if (sign == -1)
				return (0);
			return (-1);
		}
		res = res * 10 + (*nbr - '0');
		nbr++;
	}
	return (res * sign);
}
