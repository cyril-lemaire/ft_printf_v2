/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstgetindex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clemaire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 11:45:25 by clemaire          #+#    #+#             */
/*   Updated: 2017/12/12 11:45:29 by clemaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

t_list			*ft_lstgetindex(const t_list *lst, size_t index)
{
	t_list		*node;

	node = (t_list*)lst;
	while (index-- > 0 && node != NULL)
		node = node->next;
	return (node);
}
