/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listtest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 13:39:24 by denden            #+#    #+#             */
/*   Updated: 2020/10/21 12:39:37 by denden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

void	ft_memdelbis(void *content, size_t content_size)
{
	(void)content_size;
	ft_memdel(&content);
	if (!content)
		printf("test ok : content deleted\n");
	else
		printf("test ko\n");
}

void	ft_print_string_elem(t_list *elem)
{
	printf("%s\n", (char *)elem->content);
}

t_list	*ft_plusone(t_list *elem)
{
	*(char*)(elem->content) += 1;
	return (elem);
}

void	test_lstnew(void const *content, size_t content_size, int which)
{
	t_list *new = ft_lstnew(content, content_size);
	int res = 1;

	printf("content size = %ld, list content size = %ld\n", content_size, new->content_size);
	printf("new->next = %p\n", new->next);
	if (new->next)
		res = 0;
	else if (!content)
	{
		if (new->content || new->content_size)
			res = 0;
		printf("new->content = nil\n");
	}
	else
	{
		if (new->content_size != content_size)
			res = 0;
		else if (!which)
		{
			printf("new->content = %s\n", (char *)new->content);
			if (!ft_strequ((char *)new->content, (char *)content))
				res = 0;
		}
		else
		{
			printf("new->content = %d\n", *(int *)new->content);
			if (*(int *)new->content != *(int *)content)
				res = 0;
		}
	}
	if (res)
		printf("test ok\n");
	else
		printf("test ko\n");
	
	ft_lstdel(&new, &ft_memdelbis);
	if (!new)
		printf("test ok : element deleted\n\n");
	else
		printf("test ko\n\n");
}

void	test_lstadd(t_list **alst, t_list *new)
{
	printf("new content to add : %s\n", (char *)new->content);
	ft_lstadd(alst, new);
	if (ft_strequ((char *)((*alst)->content), (char *)new->content))
		printf("test ok : content added\n\n");
	else
		printf("test ko\n\n");
}

int		main()
{
	// tests lst new
	printf("TESTS LST NEW ------------------------------------------ \n");
	int a = 42;
	char *teststr = ft_strnew(100);
	ft_strcpy(teststr, "il etait une fois 42\n");

	test_lstnew(teststr, ft_strlen(teststr) + 1, 0);
	test_lstnew(NULL, ft_strlen(teststr) + 1, 0);
	test_lstnew((void *)"", ft_strlen(teststr) + 1, 0);

	test_lstnew((void*)&a, sizeof(a), 1);
	a = 2147483647;
	test_lstnew((void*)&a, sizeof(a), 1);

	// tests lst add
	printf("TESTS LST ADD ------------------------------------------ \n");
	t_list *list = ft_lstnew((void *)"il ", 4);
	t_list **tab = malloc(sizeof(*tab) * 6);
	int i = 0;

	tab[0] = ft_lstnew((void *)"etait ", 7);
	tab[1] = ft_lstnew((void *)"une ", 5);
	tab[2] = ft_lstnew((void *)"fois ", 6);
	tab[3] = ft_lstnew((void *)"4", 2);
	tab[4] = ft_lstnew((void *)"2\n", 3);
	tab[5] = 0;
	while (tab[i])
	{
		test_lstadd(&list, tab[i]);
		i++;
	}
	
	// tests lst iter
	printf("TESTS LST ITER ------------------------------------------ \n");
	ft_lstiter(list, &ft_print_string_elem);

	// tests lst map
	printf("TESTS LST MAP ------------------------------------------ \n");
	t_list *zerolist = ft_lstmap(list, &ft_plusone);
	ft_lstiter(zerolist, &ft_print_string_elem);

	ft_lstdel(&list, &ft_memdelbis);
	ft_lstdel(&zerolist, &ft_memdelbis);
	ft_memdel((void *)&tab);
	
	return (0);
}
