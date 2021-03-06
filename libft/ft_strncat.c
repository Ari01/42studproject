/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 22:43:21 by denden            #+#    #+#             */
/*   Updated: 2020/10/13 14:33:34 by denden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	char *destcpy;

	destcpy = dest;
	while (*dest)
		dest++;
	while (*src && n--)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = 0;
	return (destcpy);
}
