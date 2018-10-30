/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_nocp.c                                   :+:      :+:    :+:   */
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

t_list*			ft_lstnew_nocp(void *content, size_t size)
{
	t_list		*lst;

	if ((lst = (t_list*)malloc(sizeof(*lst))) == NULL)
		return (NULL);
	lst->content = content;
	lst->content_size = (content != NULL) ? size : 0;
	lst->next = NULL;
	return (lst);
}
