/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 21:56:34 by denden            #+#    #+#             */
/*   Updated: 2020/10/13 14:12:54 by denden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

void	test_strsub(char const *src, char start, char end)
{
	char *startptr;
	char *endptr;
	char *testsub;
	size_t len;

	testsub = NULL;
	startptr = strchr(src, start);
	endptr = strchr(src, end);
	len = 0;

	printf("src = %s, start = %c, end = %c\n", src, start, end);
	if (startptr && endptr)
	{
		if (endptr <= startptr)
			printf("invalid subtring\n\n");
		else
		{
			len = endptr - startptr;
			testsub = ft_strsub(src, startptr - src, len);
			printf("subsrc = %s, len = %ld\n\n", testsub, ft_strlen(testsub));
		}
	}
	else
		printf("invalid substring\n\n");
}

void	test_atoi(const char *nptr)
{
	printf("nptr = %s\n", nptr);

	int test1, test2;
	test1 = atoi(nptr);
	test2 = ft_atoi(nptr);

	printf("atoi = %d, ft_atoi = %d\n", test1, test2);
	if (test1 == test2)
		printf("test ok\n\n");
	else
		printf("test ko\n\n");
}

int	main(void)
{
	printf("TEST STRSUB -------------------------------------------------\n");
	char src[1000];
	ft_strcpy(src, "il etait une fois 42");
	test_strsub(src, 'e', 0);
	test_strsub(src, 'i', 0);
	test_strsub(src, '2', 0);
	test_strsub(src, '0', 0);
	test_strsub(src, 0, 0);
	test_strsub(src, 'i', 'l');
	test_strsub(src, 'e', 'u');
	test_strsub(src, 'u', 's');
	test_strsub(" ", ' ', 0);

	printf("TEST ATOI ---------------------------------------------------\n");
	// valid strings
	test_atoi("    \t\v\f\r\n+2147483647");
	test_atoi("    \t\v\f\r\n-2147483648");
	test_atoi("    \t\v\f\r\n2147483647");
	test_atoi("    \t\v\f\r\n000000147");
	test_atoi("    \t\v\f\r\n-000000147");
	test_atoi("    \t\v\f\r\n02147483647");
	test_atoi("    \t\v\f\r\n-02147483648");
	test_atoi("    \t\v\f\r\n0000002147483647");
	test_atoi("    \t\v\f\r\n-0000002147483648");
	test_atoi("    \t\v\f\r\n-2147483648+42");
	test_atoi("    \t\v\f\r\n-2147483648-42");
	test_atoi("    \t\v\f\r\n-2147483648a42");
	test_atoi("    \t\v\f\r\n-2147483648z42");
	test_atoi("    \t\v\f\r\n-2147483648A42");
	test_atoi("    \t\v\f\r\n-2147483648Z42");
	test_atoi("    \t\v\f\r\n-2147483648~42");
	test_atoi("    \t\v\f\r\n-2147483648 42");
	test_atoi("0");
	test_atoi("1");
	test_atoi("2147483647");
	test_atoi("-2147483648");
	test_atoi("+2147483647");
	// int overflow
	test_atoi("+2147483648");
	test_atoi("-2147483649");
	test_atoi("2131546514894651");
	test_atoi("-15165131516511651");
	// invalid char after spaces or after operators
	test_atoi("    \t\v\f\r\n 123");
	test_atoi("    \t\v\f\r\n +123");
	test_atoi("    \t\v\f\r\n -123");
	test_atoi("    \t\v\f\r\n+-123");
	test_atoi("    \t\v\f\r\n-A123");
	test_atoi("    \t\v\f\r\n-a123");
	test_atoi("    \t\v\f\r\n-Z123");
	test_atoi("    \t\v\f\r\n-Z123");
	// invalid char at start
	test_atoi("a0");
	test_atoi("z1");
	test_atoi("Z2147483647");
	test_atoi("A-2147483648");
	test_atoi("abcd");

	return (0);
}
