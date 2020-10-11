/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 18:55:35 by denden            #+#    #+#             */
/*   Updated: 2020/10/11 15:03:58 by denden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*_dest;
	unsigned char	*_src;
	unsigned char	ccpy;

	_dest = (unsigned char *)dest;
	_src = (unsigned char *)src;
	ccpy = (unsigned char)c;
	while (n--)
	{
		*_dest = *_src;
		_dest++;
		if (*_src == ccpy)
			return (_dest);
		_src++;
	}
	return (NULL);
}
