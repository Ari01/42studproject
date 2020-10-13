/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 16:26:56 by denden            #+#    #+#             */
/*   Updated: 2020/10/13 14:35:54 by denden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*srccpy;
	char	*destcpy;

	srccpy = (char *)src;
	destcpy = (char *)dest;
	if (dest + n < src || dest > src + n)
		ft_memcpy(dest, src, n);
	else
	{
		while (n)
		{
			*(destcpy + n - 1) = *(srccpy + n - 1);
			n--;
		}
	}
	return (dest);
}
