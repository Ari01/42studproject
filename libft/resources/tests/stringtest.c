/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 20:42:28 by denden            #+#    #+#             */
/*   Updated: 2020/10/12 20:02:38 by denden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// STRLCAT AND STRNSTR PROTOTYPES TO REMOVE ------------------------------------------------
size_t strlcat(char * restrict dst, const char * restrict src, size_t maxlen) {
    const size_t srclen = strlen(src);
    const size_t dstlen = strnlen(dst, maxlen);
    if (dstlen == maxlen) return maxlen+srclen;
    if (srclen < maxlen-dstlen) {
        memcpy(dst+dstlen, src, srclen+1);
    } else {
        memcpy(dst+dstlen, src, maxlen-dstlen-1);
        dst[maxlen-1] = '\0';
    }
    return dstlen + srclen;
}

char *strnstr(const char *s, const char *find, size_t slen)
{
	char c, sc;
	size_t len;

	if ((c = *find++) != '\0') {
		len = strlen(find);
		do {
			do {
				if ((sc = *s++) == '\0' || slen-- < 1)
					return (NULL);
			} while (sc != c);
			if (len > slen)
				return (NULL);
		} while (strncmp(s, find, len) != 0);
		s--;
	}
	return ((char *)s);
}

// STRNEW ----------------------------------------------------------------------
void	test_strnew(size_t size)
{
	printf("size = %ld\n", size);
	char *test = ft_strnew(size);
	int testres = 1;

	for (size_t i = 0; i < size; i++)
	{
		printf("str[%ld] = %c\n", i, test[i]);
		if (test[i])
			testres = 0;
	}
	if (testres)
		printf("test ok\n\n");
	else
		printf("test ko\n\n");
	ft_memdel((void*)&test);
}

// STRDEL ------------------------------------------------------------------------
void	test_strdel(void)
{
	char *test = ft_strnew(10);
	ft_memset(test, 'a', 10);
	ft_strdel(&test);
	if (!test)
		printf("test ok\n");
	else
		printf("test ko\n");
	ft_memdel((void*)&test);
}

// STRCLR ------------------------------------------------------------------------
void	test_strclr(void)
{
	char *test = ft_strnew(10);
	int testres = 1;
	ft_memset(test, 'a', 10);
	
	printf("str before clear : %s\n", test);
	ft_strclr(test);
	printf("str after clear :");
	for (int i = 0; i < 10; i++)
	{
		printf("test[%d] = %c\n", i, test[i]);
		if (test[i])
			testres = 0;
	}
	if (testres)
		printf("test ok\n");
	else
		printf("test ko\n");
	ft_memdel((void*)&test);
}

// STRCMP -----------------------------------------------------------------------
void	test_strcmp(const char *s1, const char *s2)
{
	printf("s1 = %s, s2 = %s\n", s1, s2);

	int res1 = strcmp(s1, s2);
	int res2 = ft_strcmp(s1, s2);

	printf("strcmp = %d, ft_strcmp = %d\n", res1, res2);
	if (res1 != res2)
		printf("test ko\n\n");
	else
		printf("test ok\n\n");
}

// STRCMP -----------------------------------------------------------------------
void	test_strncmp(const char *s1, const char *s2, size_t n)
{
	printf("s1 = %s, s2 = %s, size = %ld\n", s1, s2, n);

	int res1 = strncmp(s1, s2, n);
	int res2 = ft_strncmp(s1, s2, n);

	printf("strncmp = %d, ft_strncmp = %d\n", res1, res2);
	if (res1 != res2)
		printf("test ko\n\n");
	else
		printf("test ok\n\n");
}

// STRDUP ------------------------------------------------------------------------
void	test_strdup(const char *test)
{
	printf("test = %s\n", test);

	char *src = ft_strnew(ft_strlen(test) + 1);
	src = ft_strcpy(src, test);

	char *cpy = src;
	int testres = 1;
	char *dup1 = ft_strdup(src);
	char *dup2 = strdup(src);

	if (ft_strcmp(dup1, dup2))
		testres = 0;
	printf("after dup : src = %s, dup = %s\n", src, dup1);
	src = ft_strcpy(src, "42");
	printf("after src change : src = %s, cpy = %s, dup = %s\n", src, cpy, dup1);
	if (ft_strcmp(dup1, dup2))
		testres = 0;
	
	if (testres)
		printf("test ok\n\n");
	else
		printf("test ko\n\n");
	ft_memdel((void *)&src);
	ft_memdel((void *)&dup1);
	ft_memdel((void *)&dup2);
}

// STRNCPY ----------------------------------------------------------------------
void	test_strncpy(const char *src, size_t n)
{
	printf("src = %s, nbytes to copy = %ld\n", src, n);
	size_t	i;
	int		testres = 1;
	char	*dest1 = malloc(sizeof(*dest1) * n);
	char	*dest2 = malloc(sizeof(*dest2) * n);

	if (!dest1 || !dest2)
		printf("malloc returned null\n");
	else
	{
		*dest1 = 0;
		*dest2 = 0;
		dest1 = strncpy(dest1, src, n);
		dest2 = ft_strncpy(dest2, src, n);
		for (i = 0; i < n; i++)
		{
			printf("dest[%ld] = %c\n", i, dest1[i]);
			if (dest1[i] != dest2[i] && ft_strlen(src) + 1)
				testres = 0;
		}
	}
	printf("strncpy = %s, ft_strncpy = %s\n", dest1, dest2);
	if (ft_strcmp(dest1, dest2) && n >= ft_strlen(src) + 1)
		testres = 0;
	
	if (testres)
		printf("test ok\n\n");
	else
		printf("test ko\n\n");
	ft_memdel((void *)&dest1);
	ft_memdel((void *)&dest2);
}

// STRCAT ------------------------------------------------------------------------
void	test_strcat(const char* init_dest, const char *src)
{
	size_t	srclen = ft_strlen(src);
	size_t	destlen = ft_strlen(init_dest);
	char	*dest1 = malloc(sizeof(*dest1) * (srclen + destlen + 1));
	char	*dest2 = malloc(sizeof(*dest2) * (srclen + destlen + 1));
	int		diff = 0;

	dest1 = ft_strcpy(dest1, init_dest);
	dest2 = ft_strcpy(dest2, init_dest);
	printf("before cat : src = %s, dest = %s\n", src, dest1);
	dest1 = strcat(dest1, src);
	dest2 = ft_strcat(dest2, src);
	printf("after cat : dest = %s\n", dest2);

	diff = ft_strcmp(dest1, dest2);
	if (diff)
		printf("test ko\n\n");
	else
		printf("test ok\n\n");
	ft_memdel((void *)&dest1);
	ft_memdel((void *)&dest2);
}

// STRNCAT ---------------------------------------------------------------------------
void	test_strncat(const char* init_dest, const char *src, size_t n)
{
	size_t	destlen = ft_strlen(init_dest);
	char	*dest1 = malloc(sizeof(*dest1) * (destlen + n + 1));
	char	*dest2 = malloc(sizeof(*dest2) * (destlen + n + 1));
	int		diff = 0;
	
	dest1 = ft_strcpy(dest1, init_dest);
	dest2 = ft_strcpy(dest2, init_dest);

	printf("before cat : src = %s, dest = %s, nbytes to cat = %ld\n", src, dest1, n);

	dest1 = strncat(dest1, src, n);
	dest2 = ft_strncat(dest2, src, n);

	printf("after cat : dest = %s\n", dest2);

	diff = ft_strcmp(dest1, dest2);
	if (diff)
		printf("test ko\n\n");
	else
		printf("test ok\n\n");
	ft_memdel((void *)&dest1);
	ft_memdel((void *)&dest2);
}

// STRLCAT -------------------------------------------------------------------------------
void	test_strlcat(const char *init_dest, const char *src, size_t buffsize)
{
	size_t	destsize = ft_strlen(init_dest) + ft_strlen(src) + 1;
	char	*dest1 = malloc(sizeof(*dest1) * destsize);
	char	*dest2 = malloc(sizeof(*dest2) * destsize);
	size_t	cat_res;
	size_t	ft_cat_res;
	int		stringcmp = 0;

	if (!dest1 || !dest2)
		printf("malloc returned null\n");
	dest1 = ft_strcpy(dest1, init_dest);
	dest2 = ft_strcpy(dest2, init_dest);

	printf("before cat : dest = %s, src = %s, buffsize = %ld\n", dest1, src, buffsize);

	ft_cat_res = strlcat(dest1, src, buffsize);
	cat_res = ft_strlcat(dest2, src, buffsize);

	printf("after cat : ftcat = %s, cat = %s\n", dest2, dest1);
	stringcmp = ft_strcmp(dest2, dest1);
	printf("stringcmp = %d, sizecmp = %ld\n", stringcmp, ft_cat_res - cat_res);
	if (!stringcmp && ft_cat_res == cat_res)
		printf("test ok\n\n");
	else
		printf("test ko\n\n");
}

// STRCHR ----------------------------------------------------------------------------------
void	test_strchr(const char *s, int c,
					char *(*man_func)(const char *, int), 
					char *(*ft_func)(const char *, int))
{
	printf("str = %s, tofind = %c\n", s, c);
	char *test1 = ft_strnew(ft_strlen(s) + 1);
	char *test2 = ft_strnew(ft_strlen(s) + 1);
	void *deletet1 = (void *)test1;
	void *deletet2 = (void *)test2;
	int testres = 1;

	test1 = man_func(s, c);
	test2 = ft_func(s, c);

	if ((!test1 && test2) || (test1 && !test2))
		testres = 0;
	else if (test1 && test2)
	{
		if (test1 != test2)
			testres = 0;
	}
	printf("manstring = %s, ftstring = %s\n", test1, test2);

	if (testres)
		printf("test ok\n");
	else
		printf("test ko\n");

	ft_memdel(&deletet1);
	ft_memdel(&deletet2);
	printf("\n");
}

// STRSTR --------------------------------------------------------------------------------------
void	test_strstr(const char *haystack, const char *needle)
{
	printf("haystack = %s, needle = %s\n", haystack, needle);
	char *test1 = ft_strnew(ft_strlen(haystack) + 1);
	char *test2 = ft_strnew(ft_strlen(haystack) + 1);
	void *deletet1 = (void *)test1;
	void *deletet2 = (void *)test2;

	int testres = 1;

	test1 = strstr(haystack, needle);
	test2 = ft_strstr(haystack, needle);

	if ((!test1 && test2) || (test1 && !test2))
		testres = 0;
	else if (test1 && test2)
	{
		if (test1 != test2)
			testres = 0;
	}
	printf("manstring = %s, ftstring = %s\n", test1, test2);

	if (testres)
		printf("test ok\n\n");
	else
		printf("test ko\n\n");

	ft_memdel(&deletet1);
	ft_memdel(&deletet2);
}

// STRNSTR -------------------------------------------------------------------------------------
void	test_strnstr(const char *haystack, const char *needle, size_t len)
{
	printf("haystack = %s, needle = %s\n", haystack, needle);
	char *test1 = ft_strnew(ft_strlen(haystack) + 1);
	char *test2 = ft_strnew(ft_strlen(haystack) + 1);
	void *deletet1 = (void *)test1;
	void *deletet2 = (void *)test2;

	int testres = 1;

	test1 = strnstr(haystack, needle, len);
	test2 = ft_strnstr(haystack, needle, len);

	if ((!test1 && test2) || (test1 && !test2))
		testres = 0;
	else if (test1 && test2)
	{
		if (test1 != test2)
			testres = 0;
	}
	printf("manstring = %s, ftstring = %s\n", test1, test2);

	if (testres)
		printf("test ok\n\n");
	else
		printf("test ko\n\n");

	ft_memdel(&deletet1);
	ft_memdel(&deletet2);
}

int	main(void){
	printf("TEST STRNEW ----------------------------------\n");
	test_strnew(0);
	test_strnew(10);

	printf("\nTEST STRDEL --------------------------------\n");
	test_strdel();

	printf("\nTEST STRCLR --------------------------------\n");
	test_strclr();

	printf("\nTEST STRCMP --------------------------------\n");
	test_strcmp("abc", "abc");
	test_strcmp("0123456789", "0123456789");
	test_strcmp("", "");
	test_strcmp("", "abc");
	test_strcmp("abc", "");
	test_strcmp("abd", "abz");
	test_strcmp("abz", "abd");
	test_strcmp(" ", "");
	test_strcmp("", " ");

	printf("\nTEST STRNCMP --------------------------------\n");
	test_strncmp("abc", "abc", 3);
	test_strncmp("0123456789", "0123456789", 10);
	test_strncmp("", "", 1);
	test_strncmp("", "abc", 3);
	test_strncmp("abc", "", 3);
	test_strncmp("abd", "abz", 3);
	test_strncmp("abz", "abd", 3);
	test_strncmp(" ", "", 1);
	test_strncmp("", " ", 1);
	test_strncmp("abc", "abd", 2);
	test_strncmp("abc", "abcde", 2);
	test_strncmp("abcde", "abc", 2);
	test_strncmp("abd", "abc", 2);
	test_strncmp("azq", "aqz", 1);


	printf("\nTEST STRDUP --------------------------------\n");
	test_strdup("");
	test_strdup("abcde");

	printf("\nTEST STRNCPY -------------------------------\n");
	test_strncpy("", 5);
	test_strncpy("", 1);
	test_strncpy("abcde", 0);
	test_strncpy("abcde", 5);
	test_strncpy("abcde", 1);
	test_strncpy("abcde", 6);


	printf("\nTEST STRCAT --------------------------------\n");
	test_strcat("abc", "def");
	test_strcat("", "def");
	test_strcat("abc", "");
	test_strcat("", "");

	printf("\nTEST STRNCAT -------------------------------\n");
	test_strncat("abc", "def", 3);
	test_strncat("", "def", 5);
	test_strncat("abc", "", 4);
	test_strncat("", "", 10);
	test_strncat("abc", "def", 2);
	test_strncat("abcdef", "ghi", 10);
	test_strncat("abc", "defghi", 10);


	printf("\nTEST STRLCAT !! DEPRECATED !! --------------\n");
	// success tests
	test_strlcat("abc","def", 7);
	test_strlcat("abc","def", 10);
	test_strlcat("abc","", 4);
	test_strlcat("","def", 4);
	test_strlcat("","", 1);
	// fail tests
	test_strlcat("abc","def", 6);
	test_strlcat("abc","def", 1);
	test_strlcat("abc","def", 0);


	printf("\nTEST STRCHR --------------------------------\n");
	test_strchr("abc", 'a', &strchr, &ft_strchr);
	test_strchr("abc", 'c', &strchr, &ft_strchr);
	test_strchr("", 0, &strchr, &ft_strchr);
	test_strchr("abc", 0, &strchr, &ft_strchr);
	test_strchr("abc", '1', &strchr, &ft_strchr);
	test_strchr("", 'a', &strchr, &ft_strchr);

	printf("\nTEST STRRCHR --------------------------------\n");
	test_strchr("aba", 'a', &strrchr, &ft_strrchr);
	test_strchr("cabc", 'c', &strrchr, &ft_strrchr);
	test_strchr("", 0, &strrchr, &ft_strrchr);
	test_strchr("abc", 0, &strrchr, &ft_strrchr);
	test_strchr("abc", '1', &strrchr, &ft_strrchr);
	test_strchr("", 'a', &strrchr, &ft_strrchr);

	printf("\nTEST STRSTR ---------------------------------\n");
	test_strstr("abc", "ab");
	test_strstr("abc", "abc");
	test_strstr("", "");
	test_strstr("abc", "");
	test_strstr("", "abc");
	test_strstr("abc", "c");

	printf("\nTEST STRNSTR !! DEPRECATED !!----------------\n");
	test_strnstr("abc", "ab", 3);
	test_strnstr("abc", "abc", 3);
	test_strnstr("", "", 1);
	test_strnstr("abc", "", 4);
	test_strnstr("", "abc", 4);
	test_strnstr("abc", "c", 3);
	test_strnstr("abcde", "cde", 2);
	test_strnstr("abcde", "cde", 3);
	test_strnstr("abcde", "cde", 4);

	return (0);
}
