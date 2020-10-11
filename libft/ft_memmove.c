/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 16:26:56 by denden            #+#    #+#             */
/*   Updated: 2020/10/11 00:45:35 by denden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*_src;
	char	*_dest;

	_src = (char *)src;
	_dest = (char *)dest;
	if (dest + n < src || dest > src + n)
		ft_memcpy(dest, src, n);
	else
	{
		while (n)
		{
			*(_dest + n - 1) = *(_src + n - 1);
			n--;
		}
	}
	return (dest);
}
