/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   advancedstringtest.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 21:56:34 by denden            #+#    #+#             */
/*   Updated: 2020/10/14 16:45:03 by denden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

void	ft_toupperbis(char *s)
{
	*s = ft_toupper(*s);
}

char	ft_toupperbisbis(char c)
{
	return (ft_toupper(c));
}

void	ft_odd_toupper(unsigned int i, char *s)
{
	if (!(i % 2))
		*s = ft_toupper(*s);
}

void	test_strsub(char const *src, char start, char end, char *expectedsub)
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
			printf("test ok : invalid subtring\n\n");
		else
		{
			len = endptr - startptr;
			testsub = ft_strsub(src, startptr - src, len);
			printf("subsrc = %s, len = %ld\n", testsub, ft_strlen(testsub));
			printf("expected sub = %s, len = %ld\n", expectedsub, ft_strlen(expectedsub));
			if (ft_strcmp(testsub, expectedsub))
				printf("test ko\n\n");
			else
				printf("test ok\n\n");
		}
	}
	else
		printf("test ok : invalid substring\n\n");
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

void	test_striter(char *s)
{
	int res = 1;

	printf("before toupper :\ns = %s\n", s);
	ft_striter(s, &ft_toupperbis);
	printf("after toupper :\ns = %s\n", s);
	while (*s)
	{
		if (*s >= 'a' && *s <= 'z')
		{
			res = 0;
			break;
		}
		s++;
	}
	if (res)
		printf("test ok\n\n");
	else
		printf("test ko\n\n");
}

void	test_striteri(char *s)
{
	int res = 1;

	printf("before odd_toupper : \ns = %s\n", s);
	ft_striteri(s, &ft_odd_toupper);
	printf("after odd_toupper : \ns = %s\n", s);
	while (*s)
	{
		if (*s >= 'a' && *s <= 'z')
		{
			res = 0;
			break;
		}
		if (*(s + 1))
			s += 2;
		else
			s++;
	}
	if (res)
		printf("test ok\n");
	else
		printf("test ko\n");
}

void	test_strmap(char const *s)
{
	char *new = NULL;
	int res = 1;

	printf("before map\ns = %s\n", s);
	new = ft_strmap(s, &ft_toupperbisbis);
	printf("after map\ns = %s, new = %s\n", s, new);

	while (*new && *s)
	{
		if (*new != *s && *new != *s - 32)
		{
			res = 0;
			break;
		}
		new++;
		s++;
	}
	if (*new || *s)
		res = 0;
	if (res)
		printf("test ok\n\n");
	else
		printf("test ko\n\n");
}

int	main(void)
{
	printf("TEST STRSUB -------------------------------------------------\n");
	char src[1000];
	ft_strcpy(src, "il etait une fois 42");
	test_strsub(src, 'e', 0, ft_strchr(src, 'e'));
	test_strsub(src, 'i', 0, ft_strchr(src, 'i'));
	test_strsub(src, '2', 0, ft_strchr(src, '2'));
	test_strsub(src, '0', 0, ft_strchr(src, '0'));
	test_strsub(src, 0, 0, ft_strchr(src, 0));
	test_strsub(" ", ' ', 0, " ");
	test_strsub("", 'a', 0, "");
	test_strsub(src, 'i', 'l', "i");
	test_strsub(src, 'e', 'u', "etait ");
	test_strsub(src, 'u', 's', "une foi");

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
	test_atoi("");

	printf("TEST FT_STRITER ---------------------------------------------------\n");
	char s[100] = "iL eTAIt unE+fOIS\t42mots++-test   ";
	test_striter(s);
	ft_strcpy(s, "il etait une fois 42");
	test_striter(s);

	printf("TEST FT_STRITERI --------------------------------------------------\n");
	ft_strcpy(s, "il etait une fois 42+\t-- ");
	test_striteri(s);

	printf("TEST STRMAP -------------------------------------------------------\n");
	ft_strcpy(s, "il etait une fois 42");
	test_strmap(s);
	ft_strcpy(s, "IL ETAIT UNE FOIS 42");
	test_strmap(s);
	ft_strcpy(s, "");
	test_strmap(s);

	return (0);
}
