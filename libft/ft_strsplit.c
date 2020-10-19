/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 19:55:41 by denden            #+#    #+#             */
/*   Updated: 2020/10/14 21:45:55 by denden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t		ft_get_nwords(char const *s, char c)
{
	unsigned int start;
	unsigned int end;
	unsigned int nwords;

	start = 0;
	end = 0;
	nwords = 0;
	while (s[end])
	{
		while (s[end] && s[end] == c)
			end++;
		start = end;
		while (s[end] && s[end] != c)
			end++;
		if (end != start)
			nwords++;
	}
	return (nwords);
}


char				**ft_strsplit(char const *s, char c)
{
	unsigned int	start;
	unsigned int	end;
	unsigned int	i;
	size_t			nwords;
	char			**split;

	start = 0;
	end = 0;
	i = 0;
	nwords = ft_get_nwords(s, c);
	split = malloc(sizeof(*split) * (nwords + 1));
	if (!split)
		return (NULL);
	while (s[end])
	{
		while (s[end] && s[end] == c)
			end++;
		start = end;
		while (s[end] && s[end] != c)
			end++;
		if (end > start)
			split[i++] = ft_strsub(s, start, (size_t)(end - start));
	}
	split[i] = 0;
	return (split);
}
