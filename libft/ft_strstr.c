/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 17:30:00 by denden            #+#    #+#             */
/*   Updated: 2020/10/12 18:24:48 by denden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strstr(const char *haystack, const char *needle)
{
	char *res;
	
	res = NULL;
	if (!(*needle))
		return ((char *)haystack);
	while (*haystack && *haystack != *needle)
		haystack++;
	res = (char *)haystack;
	while (*haystack && *needle && *haystack == *needle)
	{
		haystack++;
		needle++;
	}
	if (!(*needle))
		return (res);
	return (NULL);
}
