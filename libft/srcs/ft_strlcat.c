/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clemaire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 10:43:37 by clemaire          #+#    #+#             */
/*   Updated: 2017/11/29 11:46:24 by clemaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t			i;
	const size_t	src_len = ft_strlen(src);

	i = 0;
	while (dst[i] != '\0' && i < size)
		++i;
	if (i < size)
		ft_strncat(dst, src, size - i - 1);
	return (i + src_len);
}
