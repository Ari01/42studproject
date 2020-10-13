/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memtest.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 17:16:02 by denden            #+#    #+#             */
/*   Updated: 2020/10/13 21:05:53 by denden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// MEMALLOC -------------------------------------------------
void	test_memalloc(size_t size)
{
	printf("size = %ld\n", size);
	// test char*
	char *s = (char *)ft_memalloc(sizeof(*s) * size);
	int *d = (int *)ft_memalloc(sizeof(*d) * size);
	
	int res = 1;
	if (!s || !d)
		printf("malloc returned null\n");
	else
	{
		for(size_t i = 0; i < size; i++)
		{
			printf("%c %d\n", s[i], d[i]);
			if (s[i] || d[i])
				res = 0;
		}

		if (res)
			printf("test ok\n\n");
		else
			printf("test ko\n\n");

		ft_memdel((void*)&s);
		ft_memdel((void*)&d);
	}
}

// MEMSET -----------------------------------------------------
void	test_memset(int init_value, size_t size)
{
	printf("init value = %d, size = %ld\n", init_value, size);

	int *t1 = ft_memalloc(sizeof(*t1) * size);
	int *t2 = ft_memalloc(sizeof(*t2) * size);
	char *s1 = ft_memalloc(sizeof(*s1) * size + 1);
	char *s2 = ft_memalloc(sizeof(*s2) * size + 1);
	int res = 1;

	if (!t1 || !t2)
		printf("malloc returned null\n");
	else
	{
		// tests str
		memset(s1, init_value, sizeof(*s1) * size);
		ft_memset(s2, init_value, sizeof(*s2) * size);
		printf("string memset = %s, string ft_memeset = %s\n", s1, s2);
		if (ft_strcmp(s1,s2))
			printf("test ko\n");
		else
			printf("test ok\n");

		// tests int
		memset(t1, init_value, sizeof(*t1) * size);
		ft_memset(t2, init_value, sizeof(*t2) * size);
		for (size_t i = 0; i < size; i++)
		{
			printf("memres[%ld] = %d, ft_memres[%ld] = %d\n", i, t1[i], i, t2[i]);
			if (t1[i] != t2[i])
				res = 0;
		}

		if (res)
			printf("test ok\n\n");
		else
			printf("test ko\n\n");

		ft_memdel((void*)&s1);
		ft_memdel((void*)&s2);
		ft_memdel((void*)&t1);
		ft_memdel((void*)&t2);
	}
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
	else
	{
		ft_memcpy(dest1, src, sizeof(*dest1) * n);
		memcpy(dest2, src, sizeof(*dest2) * n);
		printf("memcpy = %s ft_memcpy = %s\n", dest2, dest1);

		if (ft_strcmp(dest1, dest2))
			printf("test ko\n");
		else
			printf("test ok\n");

		ft_memdel((void *)&dest1);
		ft_memdel((void *)&dest2);
	}
}

void	test_memcpy_int(int init_value, size_t n)
{
	printf("init value = %d, nbytes to copy = %ld\n", init_value, n);

	int *t1 = (int *)ft_memalloc(sizeof(*t1) * 10);
	int *t2 = (int *)ft_memalloc(sizeof(*t2) * 10);
	int *t3 = (int *)ft_memalloc(sizeof(*t3) * 10);
	int res = 1;

	if (!t1 || !t2 || !t3)
		printf("malloc returned null\n");
	else
	{
		ft_memset(t1, init_value, sizeof(*t1) * 10);
		ft_memcpy(t2, t1, sizeof(*t1) * n);
		memcpy(t3, t1, sizeof(*t1) * n);

		for(size_t i = 0; i < 10; i++)
		{
			printf("ftmemcpy[%ld] = %d, memcpy[%ld] = %d\n", i, t2[i], i, t3[i]);
			if (t2[i] != t3[i])
				res = 0;
		}

		if (res)
			printf("test ok\n");
		else
			printf("test ko\n");

		printf("\n");
		ft_memdel((void*)&t1);
		ft_memdel((void*)&t2);
		ft_memdel((void*)&t3);
	}
}

// MEMCCPY -------------------------------------------------------
void	test_memccpy_int(int init_value, int tofind, size_t n)
{
	printf("init value = %d, tofind = %d, nbytes to search = %ld\n", init_value, tofind, n);
	int *t1 = ft_memalloc(sizeof(*t1) * 10);
	int *t2 = ft_memalloc(sizeof(*t2) * 10);
	int *t3 = ft_memalloc(sizeof(*t3) * 10);
	int *res1 = ft_memalloc(sizeof(*res1));
	int *res2 = ft_memalloc(sizeof(*res2));
	void *freer1 = (void *)res1;
	void *freer2 = (void *)res2;
	int testres = 1;

	if (!res1 || !res2 || !t1 || !t2 || !t3)
		printf("malloc returned null\n");
	else
	{
		ft_memset(t1, init_value, 10);
		res1 = memccpy(t2, t1, tofind, n * sizeof(*res1));
		res2 = ft_memccpy(t3, t1, tofind, n * sizeof(*res2));

		// tofind found ?
		if (res1 && !res2)
			printf("test ko : res ft memccpy null\n");
		else if (!res1 && res2)
			printf("test ko : res ft memccpy not null\n");
		else if (res1 && res2)
		{
			printf("%d found : res1 = %d, res2 = %d\n", tofind, *res1, *res2);
			if (*res1 != *res2)
				testres = 0;
		}

		// test result comparison
		for (int i = 0; i < 10; i++)
		{
			printf("t2[%d] = %d, t3[%d] = %d\n", i, t2[i], i, t3[i]);
			if (t2[i] != t3[i])
				testres = 0;
		}
		if (testres)
			printf("test ok\n\n");
		else
			printf("test ko\n\n");

		ft_memdel(&freer1);
		ft_memdel(&freer2);
		ft_memdel((void *)&t1);
		ft_memdel((void *)&t2);
		ft_memdel((void *)&t3);
	}
}

void	test_memccpy_str(char *src, int tofind, size_t n)
{
	printf("src = %s, tofind = %c, nbytes to search = %ld\n", src, tofind, n);
	size_t srclen = ft_strlen(src);

	char *dest1 = ft_memalloc(sizeof(*dest1) * (srclen + 2));
	char *dest2 = ft_memalloc(sizeof(*dest2) * (srclen + 2));
	char *res1 = ft_memalloc(sizeof(*res1));
	char *res2 = ft_memalloc(sizeof(*res2));
	void *freer1 = (void *)res1;
	void *freer2 = (void *)res2;
	int res = 1;

	if (!dest1 || !dest2 || !res1 || !res2)
		printf("malloc returned null\n");
	else
	{
		res1 = memccpy(dest1, src, tofind, n);
		res2 = ft_memccpy(dest2, src, tofind, n);

		// tofind found ?
		if (res1 && !res2)
			printf("test ko : %c found in memccpy but not in ftmemccpy\n", tofind);
		else if (!res1 && res2)
			printf("test ko : %c found in ftmemccpy but not in memccpy\n", tofind);
		else if (res1 && res2)
		{
			printf("%c found\n", tofind);
			printf("memccpy res = %s, ft_memccpy res = %s\n", res1, res2);
			if (*res1 != *res2)
				res = 0;
		}
		else
			printf("%c not found\n", tofind);

		// test result comparison
		printf("memccpy dest = %s, ft_memccpy dest = %s\n", dest1, dest2);
		if (ft_strcmp(dest1, dest2))
			res = 0;
		if (res)
			printf("test ok\n\n");
		else
			printf("test ko\n\n");

		ft_memdel((void*)&dest1);
		ft_memdel((void*)&dest2);
		ft_memdel(&freer1);
		ft_memdel(&freer2);
	}
}

// MEMMOVE -------------------------------------------------------
void	test_memmove(size_t n)
{
	// string tests
	printf("n bytes to move = %ld\n", n);

	char *src1 = ft_memalloc(100 * sizeof(*src1));
	char *src2 = ft_memalloc(100 * sizeof(*src2));
	char *dest1;
	char *dest2;

	if (!src1 || !src2)
		printf("malloc returned null\n");
	else
	{
		for (int i = 0; i < 5; i++)
		{
			src1[i] = i + 'a';
			src2[i] = i + 'a';
		}
		dest1 = src1 + n;
		dest2 = src2 + n;

		memmove(dest1, src1, n);
		ft_memmove(dest2, src2, n);

		printf("dest memmove = %s, dest ft_memove = %s\n", dest1, dest2);
		printf("src memmove = %s, src ft_memmove = %s\n", src1, src2);
		if (ft_strcmp(dest1, dest2) || ft_strcmp(src1, src2))
			printf("test ko\n\n");
		else
			printf("test ok\n\n");

		ft_memdel((void*)&src1);
		ft_memdel((void*)&src2);
	}

	// int tests
	printf("n bytes to move = %ld\n", n);

	int *t1 = ft_memalloc(100 * sizeof(*t1));
	int *t2 = t1 + n;
	int *t3 = ft_memalloc(100 * sizeof(*t3));
	int *t4 = t3 + n;
	int res = 1;

	if (!t1 || !t2)
		printf("malloc returned null\n");
	else
	{
		t2 = t1 + n;
		t4 = t3 + n;
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
		{
			printf("dests : memmove[%ld] = %d, ftmemmove[%ld] = %d\n", i, t2[i], i, t4[i]);
			if (t2[i] != t4[i])
				res = 0;
		}
		for (size_t i = 0; i < 10 + n; i++)
		{
			printf("srcs : memove[%ld] = %d, ftmemmove[%ld] = %d\n", i, t1[i], i, t3[i]);
			if (t1[i] != t3[i])
				res = 0;
		}
		
		if (res)
			printf("test ok\n\n");
		else
			printf("test ko\n\n");


		ft_memdel((void*)&t1);
		ft_memdel((void*)&t3);
	}
}

// MEMCHR -----------------------------------------------------------
void	test_memchr_str(char *str, int tofind, size_t n)
{
	printf("tofind = %d, nbytes to search = %ld\n", tofind, n);

	void *test = ft_memchr(str, tofind, n);
	void *test2 = memchr(str, tofind, n);

	if (!test && !test2)
		printf("test ok : not found in %s\n", str);
	else
	{
		if (test == test2)
			printf("test ok\n");
		else
			printf("test ko\n");
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
		printf("test ok : not found in ");
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
			printf("test ok\n");
		else
			printf("test ko\n");
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
		printf("test ko\n");
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
		printf("test ko\n");
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
