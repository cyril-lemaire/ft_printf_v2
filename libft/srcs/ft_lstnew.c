/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clemaire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 12:40:39 by clemaire          #+#    #+#             */
/*   Updated: 2017/11/29 13:58:35 by clemaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*lst;

	lst = (t_list*)malloc(sizeof(*lst));
	if (lst == NULL)
		return (NULL);
	if (content == NULL)
	{
		lst->content = NULL;
		lst->content_size = 0;
	}
	else
	{
		lst->content = malloc(content_size);
		ft_memcpy(lst->content, content, content_size);
		if (lst->content == NULL)
		{
			free(lst);
			return (NULL);
		}
		lst->content_size = content_size;
	}
	lst->next = NULL;
	return (lst);
}
