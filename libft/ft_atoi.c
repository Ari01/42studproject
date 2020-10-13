/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 20:04:15 by denden            #+#    #+#             */
/*   Updated: 2020/10/13 14:17:52 by denden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	return (c == ' ' || c == '\f' || c == '\n'
		|| c == '\r' || c == '\t' || c == '\v');
}

static int	ft_getop(char c)
{
	if (c == '-')
		return (-1);
	if (c == '+')
		return (1);
	return (0);
}

static int	ft_get_int(const char *substring, size_t len, int minus)
{
	int res;
	int pow;

	res = 0;
	pow = 1;
	while (len)
	{
		res += (substring[--len] - '0') * pow;
		pow *= 10;
	}
	if (minus)
		res *= minus;
	return (res);
}

int			ft_atoi(const char *nptr)
{
	unsigned int	i;
	unsigned int	start;
	size_t			len;
	int				minus;
	char			*substring;

	i = 0;
	minus = 1;
	substring = NULL;
	while (nptr[i] && ft_isspace(nptr[i]))
		i++;
	if ((minus *= ft_getop(nptr[i])))
		i++;
	start = i;
	while (ft_isdigit(nptr[i]))
		i++;
	len = (size_t)(i - start);
	if (len > 0)
		substring = ft_strsub(nptr, start, len);
	if (substring)
		return (ft_get_int(substring, len, minus));
	return (0);
}
