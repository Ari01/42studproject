/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 16:19:27 by denden            #+#    #+#             */
/*   Updated: 2020/10/10 21:01:31 by denden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char *_dest;
	char *_src;

	_dest = (char *)dest;
	_src = (char *)src;
	while (n--)
	{
		*_dest = *_src;
		_dest++;
		_src++;
	}
	return (dest);
}
