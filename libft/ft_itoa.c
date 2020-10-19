/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 21:49:33 by denden            #+#    #+#             */
/*   Updated: 2020/10/14 22:58:44 by denden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_nbr_len(int n)
{
	size_t size;

	size = 1;
	while ((n = n / 10))
		size++;
	return (size);
}

char			*ft_itoa(int n)
{
	unsigned int	unbr;
	size_t			len;
	int				neg;
	char			*itoa;

	unbr = n;
	len = 0;
	neg = 0;
	if (n < 0)
	{
		len++;
		unbr = -n;
		neg = 1;
	}
	len += get_nbr_len(unbr);
	itoa = ft_strnew(sizeof(*itoa) * (len + 1));
	if (neg)
		itoa[0] = '-';
	while (unbr)
	{
		itoa[--len] = unbr % 10 + '0';
		unbr = unbr / 10;
	}
	return (itoa);
}
