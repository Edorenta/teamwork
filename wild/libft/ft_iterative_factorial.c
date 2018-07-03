/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 16:37:11 by msicot            #+#    #+#             */
/*   Updated: 2017/11/15 20:38:09 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_iterative_factorial(int nb)
{
	int i;

	i = 1;
	if (nb == 0 || nb == 1)
		return (1);
	if (nb > 12)
		return (0);
	if (nb > 1 && nb <= 12)
	{
		while (nb > 1)
		{
			i = i * nb;
			nb--;
		}
		return (i);
	}
	return (0);
}
