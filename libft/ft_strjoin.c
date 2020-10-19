/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 18:03:29 by denden            #+#    #+#             */
/*   Updated: 2020/10/14 18:19:01 by denden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *join;

	join = ft_strnew(sizeof(*join) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	join = ft_strcat(join, s1);
	join = ft_strcat(join, s2);
	return (join);
}
