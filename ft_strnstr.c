/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkadir <aelkadir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 11:11:10 by aelkadir          #+#    #+#             */
/*   Updated: 2024/11/16 10:26:03 by aelkadir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	min(size_t i, size_t j)
{
	if (i < j)
		return (i);
	return (j);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	l_len;
	size_t	b_len;
	size_t	size;

	l_len = ft_strlen(needle);
	if (*needle == '\0')
		return ((char *)haystack);
	if (len == 0)
		return (NULL);
	b_len = ft_strlen(haystack);
	if (b_len < l_len || len < l_len)
		return (0);
	size = min(len, b_len);
	while (size-- >= l_len)
	{
		if (ft_strncmp(haystack, needle, l_len) == 0)
			return ((char *)haystack);
		haystack++;
	}
	return (0);
}
