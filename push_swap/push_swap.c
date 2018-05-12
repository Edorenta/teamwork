/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyildiz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 18:26:08 by jyildiz-          #+#    #+#             */
/*   Updated: 2018/05/12 04:38:55 by jyildiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(long *pile1, long *pile2, int nb)
{

}

int		main(int ac, char **av)
{
	long	*pile1;
	long	*pile2;

	if (ac > 1)
	{
		pile1 = stock_table(ac, av);
		pile2 = create_table(ac);
		push_swap(pile1, pile2, ac - 1);
	}
	free_pile(pile1, pile2);
	return (1);
}
