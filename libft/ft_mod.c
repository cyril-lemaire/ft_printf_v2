/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mod.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clemaire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 16:33:12 by clemaire          #+#    #+#             */
/*   Updated: 2017/11/28 17:01:44 by clemaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_mod(int n, int b)
{
	return (((n % b) + b) % b);
}
