/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clemaire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 12:14:34 by clemaire          #+#    #+#             */
/*   Updated: 2017/11/29 16:02:08 by clemaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*res;
	unsigned int	i;

	if (s == NULL)
		return (NULL);
	res = (char*)malloc((ft_strlen(s) + 1) * sizeof(*s));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		res[i] = f(i, s[i]);
		++i;
	}
	res[i] = '\0';
	return (res);
}
