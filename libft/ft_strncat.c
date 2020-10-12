/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 22:43:21 by denden            #+#    #+#             */
/*   Updated: 2020/10/11 22:51:01 by denden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	char *_dest;

	_dest = dest;
	while (*dest)
		dest++;
	while (*src && n--)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = 0;
	return (_dest);
}
