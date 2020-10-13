/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 18:55:35 by denden            #+#    #+#             */
/*   Updated: 2020/10/13 14:28:44 by denden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*destcpy;
	unsigned char	*srccpy;
	unsigned char	ccpy;

	destcpy = (unsigned char *)dest;
	srccpy = (unsigned char *)src;
	ccpy = (unsigned char)c;
	while (n--)
	{
		*destcpy = *srccpy;
		destcpy++;
		if (*srccpy == ccpy)
			return (destcpy);
		srccpy++;
	}
	return (NULL);
}
