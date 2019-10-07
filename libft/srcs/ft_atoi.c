/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clemaire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 13:16:52 by clemaire          #+#    #+#             */
/*   Updated: 2017/11/28 13:08:29 by clemaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *str)
{
	int		res;
	int		i;
	int		is_negative;

	res = 0;
	i = 0;
	while (ft_isspace(str[i]))
		++i;
	if (str[i] == '-' || str[i] == '+')
	{
		is_negative = (str[i] == '-');
		++i;
	}
	else
		is_negative = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res *= 10;
		res += str[i] - '0';
		++i;
	}
	return (is_negative ? -res : res);
}
