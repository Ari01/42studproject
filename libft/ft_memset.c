/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 20:51:29 by denden            #+#    #+#             */
/*   Updated: 2020/10/09 16:39:41 by denden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	ccpy;
	unsigned char	*str;

	ccpy = (unsigned char)c;
	str = (unsigned char *)s;
	while (n--)
		*str++ = ccpy;
	return (s);
}
