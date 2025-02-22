/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkadir <aelkadir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:08:21 by aelkadir          #+#    #+#             */
/*   Updated: 2024/11/02 09:33:59 by aelkadir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!s)
		return (count);
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

static char	*copy(char const *start, char const *end)
{
	int		i;
	char	*copy;

	i = 0;
	copy = (char *)malloc(end - start + 1);
	if (!copy)
		return (NULL);
	while (start < end)
		copy[i++] = *start++;
	copy[i] = '\0';
	return (copy);
}

static char	**free_splitted(char **splitted, int i)
{
	while (i > 0)
		free(splitted[--i]);
	free(splitted);
	return (NULL);
}

static char	**allocate(char const *s, char c)
{
	char	**splitted;

	if (!s)
		return (NULL);
	splitted = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
	return (splitted);
}

char	**ft_split(char const *s, char c)
{
	char		**splitted;
	char const	*start;
	int			i;

	splitted = allocate(s, c);
	if (!splitted)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			start = s;
			while (*s && *s != c)
				s++;
			splitted[i++] = copy(start, s);
			if (!splitted[i - 1])
				return (free_splitted(splitted, i));
		}
	}
	splitted[i] = NULL;
	return (splitted);
}
