/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkadir <aelkadir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:08:43 by aelkadir          #+#    #+#             */
/*   Updated: 2024/11/05 11:36:37 by aelkadir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	s_len;
	size_t	d_len;
	size_t	i;

	s_len = ft_strlen(src);
	if (size == 0)
		return (s_len);
	d_len = ft_strlen(dst);
	i = d_len;
	if (size <= d_len)
		return (size + s_len);
	while (i < size - 1 && *src)
		dst[i++] = *(src++);
	dst[i] = '\0';
	return (s_len + d_len);
}
