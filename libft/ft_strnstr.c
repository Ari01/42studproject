/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 18:26:21 by denden            #+#    #+#             */
/*   Updated: 2020/10/13 14:36:48 by denden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char *res;

	res = NULL;
	if (!(*little))
		return ((char *)big);
	while (*big && *big != *little && len)
	{
		len--;
		big++;
	}
	res = (char *)big;
	while (*big && *little && *big == *little && len)
	{
		len--;
		big++;
		little++;
	}
	if (!(*little))
		return (res);
	return (NULL);
}
