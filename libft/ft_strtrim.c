/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 18:29:52 by denden            #+#    #+#             */
/*   Updated: 2020/10/14 19:01:54 by denden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_ws(char c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

char		*ft_strtrim(char const *s)
{
	unsigned int	start;
	unsigned int	end;
	char			*trim;

	start = 0;
	end = ft_strlen(s);
	while (is_ws(s[start]))
		start++;
	if (start == end)
	{
		trim = ft_strnew(sizeof(*trim));
		return (trim);
	}
	while (is_ws(s[end - 1]))
		end--;
	return (ft_strsub(s, start, (size_t)(end - start)));
}
