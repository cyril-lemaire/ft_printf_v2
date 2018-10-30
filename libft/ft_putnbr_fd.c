/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clemaire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 17:23:23 by clemaire          #+#    #+#             */
/*   Updated: 2017/11/29 16:33:57 by clemaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char			repr[16];
	char			*cptr;

	if (n < 0)
		ft_putchar_fd('-', fd);
	repr[15] = '\0';
	cptr = &repr[14];
	*cptr = '0' + ft_abs(n % 10);
	n = ft_abs(n / 10);
	while (n > 0)
	{
		*(--cptr) = '0' + ft_abs(n % 10);
		n /= 10;
	}
	ft_putstr_fd(cptr, fd);
}
