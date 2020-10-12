/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 18:54:43 by denden            #+#    #+#             */
/*   Updated: 2020/10/12 13:37:30 by denden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dup;
	size_t	len;

	len = ft_strlen(s);
	dup = ft_strnew(sizeof(*dup) * (len + 1));
	if (!dup)
		return (NULL);
	dup = ft_strcpy(dup, s);
	return (dup);
}
