/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 13:33:50 by denden            #+#    #+#             */
/*   Updated: 2020/10/14 16:08:43 by denden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*new;
	int		i;

	new = ft_strnew(sizeof(*new) * (ft_strlen(s) + 1));
	i = 0;
	while (s[i])
	{
		new[i] = f(s[i]);
		i++;
	}
	return (new);
}
