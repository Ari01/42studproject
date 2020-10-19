/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 21:51:49 by denden            #+#    #+#             */
/*   Updated: 2020/10/17 11:12:13 by denden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	unsigned int ncpy;

	ncpy = n;
	if (n < 0)
	{
		ft_putchar('-');
		ncpy = -n;
	}
	if (ncpy < 10)
		ft_putchar(ncpy + '0');
	else
	{
		ft_putnbr(ncpy / 10);
		ft_putchar(ncpy % 10 + '0');
	}
}
