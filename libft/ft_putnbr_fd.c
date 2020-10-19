/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 11:10:22 by denden            #+#    #+#             */
/*   Updated: 2020/10/17 11:11:59 by denden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int ncpy;

	ncpy = n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ncpy = -n;
	}
	if (ncpy < 10)
		ft_putchar_fd(ncpy + '0', fd);
	else
	{
		ft_putnbr_fd(ncpy / 10, fd);
		ft_putchar_fd(ncpy % 10 + '0', fd);
	}
}
