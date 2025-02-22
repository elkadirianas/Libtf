/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkadir <aelkadir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:09:44 by aelkadir          #+#    #+#             */
/*   Updated: 2024/11/02 09:38:56 by aelkadir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	in_set(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;

	if (!s1)
		return (NULL);
	if (!set)
		return ((char *)s1);
	while (in_set(*s1, set) && *s1)
		s1++;
	len = ft_strlen(s1);
	while (len > 0 && in_set(s1[len - 1], set))
		len--;
	return (ft_substr(s1, 0, len));
}
