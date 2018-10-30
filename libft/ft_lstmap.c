/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clemaire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 14:00:01 by clemaire          #+#    #+#             */
/*   Updated: 2017/12/12 11:44:02 by clemaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

static void		ft_del_content(void *content, size_t content_size)
{
	(void)content_size;
	free(content);
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*new_lst;
	t_list		*f_ret;
	t_list		*current_cell;

	if (lst == NULL || f == NULL)
		return (NULL);
	if ((f_ret = f(lst)) == NULL ||
		(new_lst = ft_lstnew(f_ret->content, f_ret->content_size)) == NULL)
		return (NULL);
	lst = lst->next;
	current_cell = new_lst;
	while (lst != NULL)
	{
		if ((f_ret = f(lst)) == NULL ||
			(current_cell->next = ft_lstnew(f_ret->content,
											f_ret->content_size)) == NULL)
		{
			ft_lstdel((void*)new_lst, ft_del_content);
			return (NULL);
		}
		current_cell = current_cell->next;
		lst = lst->next;
	}
	return (new_lst);
}
