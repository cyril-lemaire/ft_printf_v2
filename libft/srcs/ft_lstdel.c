/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clemaire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 13:28:45 by clemaire          #+#    #+#             */
/*   Updated: 2017/11/29 15:25:40 by clemaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void		ft_lstdel(t_list **alst, void (*del)(void *content, size_t size))
{
	t_list	*current_cell;
	t_list	*next_cell;

	if (alst != NULL)
	{
		current_cell = *alst;
		while (current_cell != NULL)
		{
			next_cell = current_cell->next;
			ft_lstdelone(&current_cell, del);
			current_cell = next_cell;
		}
		*alst = NULL;
	}
}
