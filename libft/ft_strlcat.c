/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 23:01:00 by denden            #+#    #+#             */
/*   Updated: 2020/10/12 19:16:07 by denden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t dstlen;
	size_t srclen;
	size_t nbytes_to_copy;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	nbytes_to_copy = size - dstlen - 1;
	if (dstlen + srclen > size)
		return (dstlen + size);
	while (*dst)
		dst++;
	while (*src && nbytes_to_copy--)
		*dst++ = *src++;
	*dst = 0;
	return (dstlen + srclen);
}
