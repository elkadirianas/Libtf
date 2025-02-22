/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkadir <aelkadir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:07:48 by aelkadir          #+#    #+#             */
/*   Updated: 2024/11/15 21:09:24 by aelkadir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (*((unsigned char *)str1 + i) != *((unsigned char *)str2 + i))
			return ((*((unsigned char *)str1 + i) - *((unsigned char *)str2
						+ i)));
		i++;
	}
	return (0);
}
