/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 17:16:02 by denden            #+#    #+#             */
/*   Updated: 2020/10/11 20:32:05 by denden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// MEMALLOC -------------------------------------------------
void	test_memalloc(size_t size)
{
	// test char*
	char *s = (char *)ft_memalloc(sizeof(*s) * size);
	if (!s)
		printf("malloc returned null\n");
	else
	{
		for(size_t i = 0; i < size; i++)
			printf("%c\n", s[i]);
	}

	// test int
	int *d = (int *)ft_memalloc(sizeof(*d) * size);
	if (!d)
		printf("malloc returned null\n");
	else
	{
		for (size_t i = 0; i < size; i++)
			printf("%d\n", d[i]);
	}
	ft_memdel((void*)&s);
	ft_memdel((void*)&d);
}

// MEMSET -----------------------------------------------------
void	test_memset(int init_value, size_t size)
{
	int *t1 = ft_memalloc(sizeof(*t1) * size);
	int *t2 = ft_memalloc(sizeof(*t2) * size);
	char *s1 = ft_memalloc(sizeof(*s1) * size + 1);
	char *s2 = ft_memalloc(sizeof(*s2) * size + 1);

	if (!t1 || !t2)
		printf("malloc returned null\n");
	else
	{
		// tests str
		memset(s1, init_value, sizeof(*s1) * size);
		ft_memset(s2, init_value, sizeof(*s2) * size);
		printf("str memres - str ft_memres = %d\n", ft_strcmp(s1, s2));

		// tests int
		memset(t1, init_value, sizeof(*t1) * size);
		ft_memset(t2, init_value, sizeof(*t2) * size);
		for (size_t i = 0; i < size; i++)
			printf("memres[%ld] - ft_memres[%ld] = %d\n", i, i, t1[i] - t2[i]);
	}
	printf("\n");
	ft_memdel((void*)&s1);
	ft_memdel((void*)&s2);
	ft_memdel((void*)&t1);
	ft_memdel((void*)&t2);
}

// MEMCPY ------------------------------------------------------
void	test_memcpy_string(char *src, size_t n)
{
	printf("src = %s, nbytes to copy = %ld\n", src, n);
	size_t len = ft_strlen(src);
	char *dest1 = (char *)ft_memalloc(sizeof(*dest1) * (len + 1));
	char *dest2 = (char *)ft_memalloc(sizeof(*dest2) * (len + 1));
	
	if (!dest1 || !dest2)
		printf("malloc returned null\n");
	
	printf("memcpy - ft_memcpy = %d\n", ft_strcmp(
		ft_memcpy(dest1, src, sizeof(*dest1) * n)
		, memcpy(dest2, src, sizeof(*dest2) * n)));

	ft_memdel((void *)&dest1);
	ft_memdel((void *)&dest2);
}

void	test_memcpy_int(int init_value, size_t n)
{
	printf("init value = %d, nbytes to copy = %ld\n", init_value, n);
	int *t1 = (int *)ft_memalloc(sizeof(*t1) * 10);
	int *t2 = (int *)ft_memalloc(sizeof(*t2) * 10);
	int *t3 = (int *)ft_memalloc(sizeof(*t3) * 10);

	if (!t1 || !t2 || !t3)
		printf("malloc returned null\n");
	else
	{
		for(size_t i = 0; i < 10; i++)
			t1[i] = init_value;

		ft_memcpy(t2, t1, sizeof(*t1) * n);
		memcpy(t3, t1, sizeof(*t1) * n);

		for(size_t i = 0; i < 10; i++)
		{
			printf("t2[%ld] - t3[%ld] = %d\n", i, i, t2[i] - t3[i]);
		}
	}
	printf("\n");
	ft_memdel((void*)&t1);
	ft_memdel((void*)&t2);
	ft_memdel((void*)&t3);
}

// MEMCCPY -------------------------------------------------------
void	test_memccpy_int(int init_value, int tofind, size_t n)
{
	printf("init value = %d, tofind = %d, nbytes to search = %ld\n", init_value, tofind, n);
	int t1[10];
	int t2[10];
	int t3[10];
	int i;
	int *res1 = ft_memalloc(sizeof(*res1));
	int *res2 = ft_memalloc(sizeof(*res2));
	void *freer1 = (void *)res1;
	void *freer2 = (void *)res2;

	if (!res1 || !res2)
		printf("malloc returned null\n");
	else
	{
		for (i = 0; i < 10; i++)
		{
			t1[i] = init_value;
			t2[i] = 0;
			t3[i] = 0;
		}
		res1 = memccpy(t2, t1, tofind, n * sizeof(*res1));
		res2 = ft_memccpy(t3, t1, tofind, n * sizeof(*res2));
		if (res1 && !res2)
			printf("error : res ft memccpy null\n");
		else if (!res1 && res2)
			printf("error : res ft memccpy not null\n");
		else if (res1 && res2){
			printf("res1 - res2 = %d\n", *res1 - *res2);
		}
		for (i = 0; i < 10; i++)
			printf("t2[%d] - t3[%d] = %d\n", i, i, t2[i] - t3[i]);
	}
	ft_memdel(&freer1);
	ft_memdel(&freer2);
	printf("\n");
}

void	test_memccpy_str(char *src, int tofind, size_t n)
{
	printf("src = %s, tofind = %d, nbytes to search = %ld\n", src, tofind, n);
	size_t srclen = ft_strlen(src);

	char *dest1 = ft_memalloc(sizeof(*dest1) * (srclen + 2));
	char *dest2 = ft_memalloc(sizeof(*dest2) * (srclen + 2));
	char *res1 = ft_memalloc(sizeof(*res1));
	char *res2 = ft_memalloc(sizeof(*res2));
	void *freer1 = (void *)res1;
	void *freer2 = (void *)res2;

	if (!dest1 || !dest2 || !res1 || !res2)
		printf("malloc returned null\n");
	else
	{
		res1 = memccpy(dest1, src, tofind, n);
		res2 = ft_memccpy(dest2, src, tofind, n);
		if (res1 && !res2)
			printf("error : res ft memccpy null\n");
		else if (!res1 && res2)
			printf("error : res ft memccpy not null\n");
		else if (res1 && res2){
			printf("found\ncmp dest from memccpy and ft_memccpy : %d\n", ft_strcmp(dest1, dest2) + ft_strcmp(res1, res2));
		}
		else
			printf("not found\ncmp dest from memccpy and ft_memccpy : %d\n", ft_strcmp(dest1, dest2));

		ft_memdel((void*)&dest1);
		ft_memdel((void*)&dest2);
		ft_memdel(&freer1);
		ft_memdel(&freer2);
	}
	printf("\n");
}

// MEMMOVE -------------------------------------------------------
void	test_memmove(size_t n)
{
	// string tests
	char *src1 = ft_memalloc(100 * sizeof(*src1));
	char *src2 = ft_memalloc(100 * sizeof(*src2));
	for (int i = 0; i < 5; i++)
	{
		src1[i] = i + 'a';
		src2[i] = i + 'a';
	}
	char *dest1 = src1 + n;
	char *dest2 = src2 + n;

	memmove(dest1, src1, n);
	ft_memmove(dest2, src2, n);
	printf("string dest cmp = %d\n", ft_strcmp(dest1, dest2));
	printf("string src cmp = %d\n", ft_strcmp(src1, src2));

	// int tests
	int *t1 = ft_memalloc(100 * sizeof(*t1));
	int *t2 = t1 + n;
	int *t3 = ft_memalloc(100 * sizeof(*t3));
	int *t4 = t3 + n;

	for (int i = 0; i < 9; i++)
	{
		t1[i] = i;
		t3[i] = i;
	}
	t1[10] = -2147483648;
	t3[10] = -2147483648;

	memmove(t2, t1, n * sizeof(t1));
	ft_memmove(t4, t3, n * sizeof(t1));
	for (size_t i = 0; i < 10 + n; i++)
		printf("dests : t2[%ld] - t4[%ld] = %d\n", i, i, t2[i] - t4[i]);
	for (size_t i = 0; i < 10 + n; i++)
		printf("srcs : t1[%ld] - t3[%ld] = %d\n", i, i, t1[i] - t3[i]);
	printf("\n");

	ft_memdel((void*)&src1);
	ft_memdel((void*)&src2);
	ft_memdel((void*)&t1);
	ft_memdel((void*)&t3);
}

// MEMCHR -----------------------------------------------------------
void	test_memchr_str(char *str, int tofind, size_t n)
{
	printf("tofind = %d, nbytes to search = %ld\n", tofind, n);
	void *test = ft_memchr(str, tofind, n);
	void *test2 = memchr(str, tofind, n);

	if (!test && !test2)
		printf("test str : not found in %s\n", str);
	else
	{
		if (test == test2)
			printf("test str ok\n");
		else
			printf("ko\n");
	}
	printf("\n");
}

void	test_memchr_int(int tofind, size_t n)
{
	printf("tofind = %d, nbytes to search = %ld\n", tofind, n);
	int t[10] = {0,1,2,3,4,5,6,7,8,-2147483648};
	void *test = ft_memchr(t, tofind, n * sizeof(int));
	void *test2 = memchr(t, tofind, n * sizeof(int));

	if (!test && !test2)
	{
		printf("test int : not found in ");
		for (int i = 0; i < 10; i++)
		{
			printf("%d", t[i]);
			if (i < 9)
				printf(", ");
			else
				printf("\n");
		}
	}
	else
	{
		if (test == test2)
			printf("test int ok\n");
		else
			printf("ko\n");
	}
	printf("\n");
}

// MEMCMP ---------------------------------------------------
void	test_memcmp_str(char *s1, char *s2, size_t n)
{
	printf("s1 = %s\ns2 = %s\n", s1, s2);
	int rs1, rs2;

	rs1 = memcmp(s1, s2, n);
	rs2 = ft_memcmp(s1, s2, n);
	if ((rs1 > 0 && rs2 > 0) 
		|| (rs1 < 0 && rs2 < 0)
		|| (!rs1 && !rs2))
		printf("test ok\n");
	else
		printf("ko\n");
	printf("\n");
}

void	test_memcmp_int(int *d1, int *d2, size_t n)
{
	printf("d1 = %d\nd2 = %d\n", *d1, *d2);
	int rd1, rd2;

	rd1 = memcmp(d1, d2, n);
	rd2 = ft_memcmp(d1, d2, n);
	if ((rd1 > 0 && rd2 > 0) 
		|| (rd1 < 0 && rd2 < 0)
		|| (!rd1 && !rd2))
		printf("test ok\n");
	else
		printf("ko\n");
	printf("\n");
}


int	main()
{
	printf("TEST MEMALLOC ------------------------------\n");
	test_memalloc(0);
	test_memalloc(100);

	printf("\nTEST MEMSET ------------------------------\n");
	test_memset(0, 10);
	test_memset(2147483647, 10);
	test_memset(-2147483648, 10);

	printf("\nTEST MEMCPY ------------------------------\n");
	char *src = "abc";
	test_memcpy_string(src, ft_strlen(src));
	src = "\t abc \t";
	test_memcpy_string(src, ft_strlen(src));
	test_memcpy_string(src, 0);
	test_memcpy_string("", 1);
	printf("\n");
	test_memcpy_int(2147483647, 10);
	test_memcpy_int(-2147483648, 10);
	test_memcpy_int(0, 10);
	test_memcpy_int(1, 0);

	printf("\nTEST MEMCCPY -----------------------------\n");
	char *str = "Voici ma 1ere phrase. Voici ma 2e phrase.";
	test_memccpy_str(str, '.', ft_strlen(str));
	test_memccpy_str(str, 0, ft_strlen(str));
	test_memccpy_str(str, 0, ft_strlen(str) + 1);
	test_memccpy_str(str, '1', ft_strlen(str));
	test_memccpy_str(str, '.', 0);
	test_memccpy_str("", 'a', 1);
	test_memccpy_str("", 0, 1);
	str = "    \t";
	test_memccpy_str(str, '\t', ft_strlen(str));
	str = "abcdef";
	test_memccpy_str(str, '\t', ft_strlen(str));
	printf("\n");
	test_memccpy_int(2147483647, 2147483647, 10);
	test_memccpy_int(-2147483648, -2147483648, 10);
	test_memccpy_int(0, 1, 10);
	test_memccpy_int(0, 0, 10);
	test_memccpy_int(2147483647, 255, 10);
	test_memccpy_int(-2147483648, 255, 10);
	test_memccpy_int(2147483647, 2147483647, 0);

	printf("\nTEST MEMMOVE ----------------------------- \n");
	test_memmove(5);
	test_memmove(10);
	test_memmove(0);
	test_memmove(1);

	printf("\nTEST MEMCHR ------------------------------ \n");
	test_memchr_str("abcde", 0, 5);
	test_memchr_str("abcde", 0, 6);
	test_memchr_str("ab0", '0', 3);
	test_memchr_str("", 'a', 1);
	test_memchr_str("abcde", 'e', 4);
	test_memchr_str("a", 'a', 0);

	test_memchr_int(-2147483648, 10);
	test_memchr_int(2147483647, 10);
	test_memchr_int(-2147483648, 1);
	test_memchr_int(0, 0);
	test_memchr_int(0, 10);

	printf("\nTEST MEMCMP -------------------------------\n");
	test_memcmp_str("abc", "dbc", 3);
	test_memcmp_str("dbc", "abc", 3);
	test_memcmp_str("", "a", 1);
	test_memcmp_str("a", "", 1);
	test_memcmp_str("", "", 1);
	test_memcmp_str(".", "", 1);
	test_memcmp_str("abc", "abcd", 4);
	test_memcmp_str("abcd", "abc", 4);
	test_memcmp_str("abc", "abd", 3);
	test_memcmp_str("abd", "abc", 3);
	test_memcmp_str("abd", "abc", 0);
	printf("\n");
	int a, b;
	a = 2147483647;
	b = 2147483647;
	test_memcmp_int(&b, &a, sizeof(a));
	test_memcmp_int(&b, &a, 0);
	b = 0;
	test_memcmp_int(&b, &a, sizeof(a));
	a = -2147483648;
	b = -2147483648;
	test_memcmp_int(&b, &a, sizeof(a));
	b = 0;
	test_memcmp_int(&b, &a, sizeof(a));
	a = 0;
	test_memcmp_int(&b, &a, sizeof(a));

	return (0);
}
