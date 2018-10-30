/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clemaire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 12:34:50 by clemaire          #+#    #+#             */
/*   Updated: 2017/11/29 16:06:03 by clemaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*res;

	if (s == NULL)
		return (NULL);
	res = (char*)malloc((len + 1) * sizeof(*s));
	if (res == NULL)
		return (NULL);
	ft_strncpy(res, &s[start], len);
	res[len] = '\0';
	return (res);
}
