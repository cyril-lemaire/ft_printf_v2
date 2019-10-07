/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelnext.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clemaire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 11:23:17 by clemaire          #+#    #+#             */
/*   Updated: 2017/12/12 11:26:17 by clemaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

int			ft_lstdelnext(t_list *node, void (*del)(void *, size_t))
{
	t_list		*new_next;

	if (node == NULL || node->next == NULL)
		return (0);
	new_next = node->next->next;
	ft_lstdelone(&node->next, del);
	node->next = new_next;
	return (1);
}
