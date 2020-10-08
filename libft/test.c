/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 17:16:02 by denden            #+#    #+#             */
/*   Updated: 2020/10/08 19:24:15 by denden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h>
int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
	/*
	** test strlen
	*/
/*	if (ac == 2)
		printf("%ld\n", ft_strlen(av[1]));
*/
	/*
	** test memalloc
	*/
	char *s = (char *)ft_memalloc(10);
	s[0] = 'a';
	s[1] = 0;
	printf("%s\n",s);

	return (0);
}
