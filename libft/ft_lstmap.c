/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 17:50:52 by denden            #+#    #+#             */
/*   Updated: 2020/10/20 19:00:01 by denden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;
	t_list *tmp;

	if (!lst)
		return (NULL);
	lst = f(lst);
	tmp = ft_lstnew(lst->content, lst->content_size);
	new = tmp;
	while (lst->next)
	{
		lst->next = f(lst->next);
		tmp->next = ft_lstnew(lst->next->content, lst->next->content_size);
		tmp = tmp->next;
		lst = lst->next;
	}
	return (new);
}
