/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 01:01:55 by denden            #+#    #+#             */
/*   Updated: 2020/10/11 01:39:45 by denden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*_s;
	unsigned char	_c;

	_s = (unsigned char *)s;
	_c = (unsigned char)c;
	while (n--)
	{
		if (*_s == _c)
			return ((void *)_s);
		_s++;
	}
	return (NULL);
}
