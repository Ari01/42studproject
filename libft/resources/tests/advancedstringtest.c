/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   advancedstringtest.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 21:56:34 by denden            #+#    #+#             */
/*   Updated: 2020/10/14 23:06:28 by denden           ###   ########.fr       */
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

char	ft_odd_toupperbis(unsigned int i, char c)
{
	if (!(i % 2))
		return (ft_toupper(c));
	return (c);
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
		printf("test ok\n\n");
	else
		printf("test ko\n\n");
}

void	test_strmap(char const *s, int which_func)
{
	char *new = NULL;
	int res = 1;

	printf("before map\ns = %s\n", s);
	if (!which_func)
		new = ft_strmap(s, &ft_toupperbisbis);
	else
		new = ft_strmapi(s, &ft_odd_toupperbis);
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

void	test_strequ(char const *s1, char const *s2)
{
	int res1 = ft_strcmp(s1, s2);
	int res2 = ft_strequ(s1, s2);

	printf("s1 = %s\n", s1);
	printf("s2 = %s\n", s2);
	printf("cmp = %d, equ = %d\n", res1, res2);

	if ((!res1 && res2) || (res1 && !res2))
		printf("test ok\n\n");
	else
		printf("test ko\n\n");
}

void	test_strnequ(char const *s1, char const *s2, size_t n)
{
	int res1 = ft_strncmp(s1, s2, n);
	int res2 = ft_strnequ(s1, s2, n);

	printf("s1 = %s, size = %ld\n", s1, n);
	printf("s2 = %s, size = %ld\n" , s2, n);

	printf("res strncmp = %d\n", res1);
	printf("res strnequ = %d\n", res2);

	if ((!res1 && res2) || (res1 && !res2))
		printf("test ok\n\n");
	else
		printf("test ko\n\n");
}

void	test_strjoin(char const *s1, char const *s2)
{
	char *join = ft_strjoin(s1, s2);
	char *cpy = ft_strdup(s1);
	char *cat = ft_strcat(cpy, s2);

	printf("s1 = %s, s2 = %s\n", s1, s2);
	printf("cat = %s\n", cat);
	printf("join = %s\n", join);

	if (!ft_strcmp(cat, join))
		printf("test ok\n\n");
	else
		printf("test ko\n\n");
}

void	test_strtrim(char const *s, char const *expected)
{
	char *trim = ft_strtrim(s);

	printf("s = %s\n", s);
	printf("expected after trim = %s\n", expected);
	printf("trim = %s\n", trim);

	if (ft_strequ(trim, expected))
		printf("test ok\n\n");
	else
		printf("test ko\n\n");
}

void	test_split(const char *s, char c, char *expected, int nwords)
{
	char **split = ft_strsplit(s, c);
	char *join = 0;
	int i = 0;
	int len = 0;

	printf("s = %s, sep = %c\n", s, c);
	while (split[i])
	{
		printf("split[%d] = %s\n", i, split[i]);
		len += ft_strlen(split[i]);
		i++;
	}

	join = ft_strnew(sizeof(*join) * (len + 1));
	i = 0;
	while (split[i])
	{
		join = ft_strcat(join, split[i]);
		i++;
	}

	if (ft_strequ(join, expected) && i == nwords)
		printf("test ok\n\n");
	else
		printf("test ko\n\n");
}

void	test_itoa(int n, char *expected)
{
	char *itoa = ft_itoa(n);

	printf("n = %d\n", n);
	printf("itoa = %s\n", itoa);

	if (ft_strequ(itoa, expected))
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
	test_strmap(s, 0);
	ft_strcpy(s, "IL ETAIT UNE FOIS 42");
	test_strmap(s, 0);
	ft_strcpy(s, "");
	test_strmap(s, 0);

	printf("TEST STRMAP -------------------------------------------------------\n");
	ft_strcpy(s, "il etait une fois 42");
	test_strmap(s, 1);
	ft_strcpy(s, "IL ETAIT UNE FOIS 42");
	test_strmap(s, 1);
	ft_strcpy(s, "");
	test_strmap(s, 1);

	printf("TEST STREQU ------------------------------------------------------\n");
	test_strequ("abc", "abc");
	test_strequ("0123456789", "0123456789");
	test_strequ("", "");
	test_strequ("", "abc");
	test_strequ("abc", "");
	test_strequ("abd", "abz");
	test_strequ("abz", "abd");
	test_strequ(" ", "");
	test_strequ("", " ");

	printf("TEST STRNEQU -----------------------------------------------------\n");
	test_strnequ("abc", "abc", 3);
	test_strnequ("0123456789", "0123456789", 10);
	test_strnequ("", "", 1);
	test_strnequ("", "abc", 3);
	test_strnequ("abc", "", 3);
	test_strnequ("abd", "abz", 3);
	test_strnequ("abz", "abd", 3);
	test_strnequ(" ", "", 1);
	test_strnequ("", " ", 1);
	test_strnequ("abc", "abd", 2);
	test_strnequ("abc", "abcde", 2);
	test_strnequ("abcde", "abc", 2);
	test_strnequ("abd", "abc", 2);
	test_strnequ("azq", "aqz", 1);

	printf("TEST STRJOIN -----------------------------------------------------\n");
	test_strjoin("abc", "def");
	test_strjoin("", "def");
	test_strjoin("abc", "");
	test_strjoin("", "");

	printf("TEST STRTRIM -----------------------------------------------------\n");
	strcpy(s, "il etait une fois 42");
	test_strtrim("\n  \t\t   \t \t  \n", "");
	test_strtrim("", "");
	test_strtrim(" \n   \t \t \t  il etait une fois 42  \t \t \t  \n ", s);
	test_strtrim(" il etait une fois 42 ", s);
	test_strtrim(" il etait une fois 42", s);
	test_strtrim("il etait une fois 42 ", s);
	test_strtrim("il etait une fois 42\n", s);
	test_strtrim("\nil etait une fois 42\n", s);
	test_strtrim("\nil etait une fois 42\t ", s);

	printf("TEST SPLIT --------------------------------------------------------\n");
	test_split(" abc def ghi ", ' ', "abcdefghi", 3);
	test_split("abc def", ' ', "abcdef", 2);
	test_split("abc def", 0, "abc def", 1);
	test_split("a ", ' ', "a", 1);
	test_split(" a", ' ', "a", 1);
	test_split("", ' ', "", 0);
	test_split("", 0, "", 0);

	printf("TEST ITOA ---------------------------------------------------------\n");
	test_itoa(2147483647, "2147483647");
	test_itoa(-2147483648, "-2147483648");
	test_itoa(0, "");

	return (0);
}
