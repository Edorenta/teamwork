/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 09:35:39 by jjourne           #+#    #+#             */
/*   Updated: 2017/01/19 02:42:20 by jjourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	int			base;
	long int	ln;

	base = 1;
	ln = n;
	if (ln < 0)
	{
		ft_putchar('-');
		ln = -ln;
	}
	while ((ln / base) >= 10)
		base *= 10;
	while (base > 0)
	{
		ft_putchar(((ln / base) % 10) + '0');
		base /= 10;
	}
}
