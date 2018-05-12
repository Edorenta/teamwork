/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_table.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyildiz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 19:08:22 by jyildiz-          #+#    #+#             */
/*   Updated: 2018/05/12 08:43:09 by jyildiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		first_elem(long *pile, int nb)
{
	int i;

	i = 0;
	while (i < nb && pile[i] == null)
		i++;
	return (i);
}

void	free_pile(long *pile1, long *pile2);
{
	free(pile1);
	free(pile2);
}

long	*create_table(int ac)
{
	long		*tab;
	int			i;
	
	if ((tab = (long*)malloc(sizeof(long) * ac)) == NULL)
		exit(1);
	while (i < ac)
	{
		tab[i] = null;
		i++;
	}
	return (tab);
}

long	*stock_table(int ac, char **av)
{
	long	*tab;
	int		i;

	i = 0;
	tab = create_table(ac);
	check_nb(ac, av);
	check_same(ac, av);
	check_int(ac, av);
	while (i < ac)
	{
		tab[i] = ft_atoi(av[i + 1]);
		i++;
	}
	return (tab);
}
