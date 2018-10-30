/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clemaire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 15:49:35 by clemaire          #+#    #+#             */
/*   Updated: 2017/11/24 18:26:02 by clemaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	const unsigned char	*s = (const unsigned char*)src;
	unsigned char		*d;
	const unsigned char	chr = (unsigned char)c;

	d = (unsigned char*)dst;
	while (n > 0)
	{
		if ((*(d++) = *(s++)) == chr)
			return (void *)(d);
		--n;
	}
	return (NULL);
}
