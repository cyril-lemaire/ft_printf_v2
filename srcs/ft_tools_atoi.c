/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_atoi.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clemaire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 13:16:52 by clemaire          #+#    #+#             */
/*   Updated: 2018/01/09 18:55:43 by clemaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_tools_atoi(const char *str, int *ans)
{
	int		i;

	*ans = 0;
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		*ans *= 10;
		*ans += str[i++] - '0';
	}
	return (i);
}
