/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 16:19:27 by denden            #+#    #+#             */
/*   Updated: 2020/10/13 14:19:28 by denden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char *destcpy;
	char *srccpy;

	destcpy = (char *)dest;
	srccpy = (char *)src;
	while (n--)
	{
		*destcpy = *srccpy;
		destcpy++;
		srccpy++;
	}
	return (dest);
}
