/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnlen.c                                        :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: clemaire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 13:43:17 by clemaire          #+#    #+#             */
/*   Updated: 2017/11/17 16:37:39 by clemaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t	ft_strnlen(const char *s, size_t n)
{
	size_t		i;

	i = 0;
	while (i < n && s[i] != '\0')
		++i;
	return (i);
}
