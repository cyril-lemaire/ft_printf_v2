/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clemaire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 15:30:49 by clemaire          #+#    #+#             */
/*   Updated: 2017/11/28 18:43:02 by clemaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

static unsigned int		ft_chr_count(int c)
{
	unsigned int	res;

	res = (c < 0) ? 2 : 1;
	c = ft_abs(c / 10);
	while (c > 0)
	{
		++res;
		c /= 10;
	}
	return (res);
}

char					*ft_itoa(int n)
{
	char			*res;
	unsigned int	len;

	len = ft_chr_count(n);
	res = (char*)malloc((len + 1) * sizeof(*res));
	if (res == NULL)
		return (NULL);
	res[len] = '\0';
	if (n < 0)
		res[0] = '-';
	res[--len] = '0' + ft_abs(n % 10);
	n = ft_abs(n / 10);
	while (n > 0)
	{
		res[--len] = '0' + (n % 10);
		n /= 10;
	}
	return (res);
}
