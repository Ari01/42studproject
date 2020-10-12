/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 20:20:44 by denden            #+#    #+#             */
/*   Updated: 2020/10/12 21:54:32 by denden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <ctype.h>

void	test_ascii(int *t, int (*man_func)(int), int (*ft_func)(int))
{
	int res1, res2;

	for (int i = 0; i<20; i++)
	{
		if (ft_isprint(t[i]))
			printf("c = %c\n", t[i]);
		else
			printf("c = %d\n", t[i]);

		res1 = man_func(t[i]);
		res2 = ft_func(t[i]);

		if (ft_isprint(t[i]))
			printf("man func = %c, ft func = %c\n", res1, res2);
		else
			printf("man func = %d, ft func = %d\n", res1, res2);

		if ((res1 && res2) || (!res1 && !res2))
			printf("test ok\n\n");
		else
			printf("test ko\n\n");
	}
}

int	main(void)
{
	int t[20] = {-260, -255, -10, 0, '\n', '\t', ' ', '.', '0', '9','a', 'z', 'A', 'Z', 10, 127, 128, 254, 255, 260};
	printf("TEST ISALPHA -----------------------------------------\n");
	test_ascii(t, &isalpha, &ft_isalpha);

	printf("TEST ISDIGIT -----------------------------------------\n");
	test_ascii(t, &isdigit, &ft_isdigit);

	printf("TEST ISALNUM -----------------------------------------\n");
	test_ascii(t, &isalnum, &ft_isalnum);

	printf("TEST ISASCII -----------------------------------------\n");
	test_ascii(t, &isascii, &ft_isascii);

	printf("TEST ISPRINT -----------------------------------------\n");
	test_ascii(t, &isprint, &ft_isprint);

	printf("TEST TOLOWER -----------------------------------------\n");
	test_ascii(t, &tolower, &ft_tolower);

	printf("TEST TOUPPER -----------------------------------------\n");
	test_ascii(t, &toupper, &ft_toupper);
}
