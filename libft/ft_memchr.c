/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 01:01:55 by denden            #+#    #+#             */
/*   Updated: 2020/10/13 14:34:33 by denden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*scpy;
	unsigned char	ccpy;

	scpy = (unsigned char *)s;
	ccpy = (unsigned char)c;
	while (n--)
	{
		if (*scpy == ccpy)
			return ((void *)scpy);
		scpy++;
	}
	return (NULL);
}
