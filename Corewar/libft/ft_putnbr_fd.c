/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 02:42:24 by jjourne           #+#    #+#             */
/*   Updated: 2017/01/19 02:54:16 by jjourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int			base;
	long int	ln;

	ln = n;
	base = 1;
	if (ln < 0)
	{
		ft_putchar_fd('-', fd);
		ln = -ln;
	}
	while ((ln / base) >= 10)
		base *= 10;
	while (base > 0)
	{
		ft_putchar_fd(((ln / base) % 10) + '0', fd);
		base /= 10;
	}
}
