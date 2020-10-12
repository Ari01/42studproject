/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 21:41:16 by denden            #+#    #+#             */
/*   Updated: 2020/10/12 13:49:47 by denden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, const char *src)
{
	char *_dest;

	_dest = dest;
	while (*src)
	{
		*dest = *src;
		src++;
		dest++;
	}
	*dest = 0;
	return (_dest);
}