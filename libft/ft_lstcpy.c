/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clemaire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 14:01:56 by clemaire          #+#    #+#             */
/*   Updated: 2017/12/01 13:12:40 by clemaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

static void		del(void *elt, size_t elt_size)
{
	(void)elt_size;
	free(elt);
}

/*
**	Returns a SHALLOW copy of lst
*/

t_list			*ft_lstcpy(const t_list *lst)
{
	t_list			*cpy;
	t_list			*cpy_cell;

	if (lst == NULL)
		return (NULL);
	if ((cpy = ft_lstnew(lst->content, lst->content_size)) == NULL)
		return (NULL);
	cpy_cell = cpy;
	while ((lst = lst->next) != NULL)
	{
		cpy_cell->next = ft_lstnew(lst->content, lst->content_size);
		if (cpy_cell == NULL)
		{
			ft_lstdel(&cpy, del);
			return (NULL);
		}
	}
	return (cpy);
}
