/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyildiz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 20:01:50 by jyildiz-          #+#    #+#             */
/*   Updated: 2018/05/12 06:07:07 by jyildiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		swap(long *pile, int nb)
{
	int	i;
	int	tmp;

	i = 0;
	while (pile[i] == null && i < nb)
		i++;
	if (i < nb && pile[i] != null && pile[i + 1] != null)
	{
		tmp = pile[i];
		pile[i] = pile[i + 1];
		pile[i + 1] = tmp;
	}
}

void		push(long *a, long *b, int nb)
{
	int		i;
	int		j;
	int		tmp;

	i = first_elem(a, nb);
	j = first_elem(b, nb);
	if (a[i] != null)
	{
		tmp = a[i];
		a[i] = b[j];
		b[j] = tmp;
	}
}

void		rotate(long *pile, int nb)
{
	int	i;
	int tmp;

	i = first_elem(pile, nb);
	if (i < nb)
	{
		tmp = pile[i];
		while (i < nb - 1)
		{
			pile[i] = pile[i + 1];
			i++;
		}
		pile[i] = tmp;
	}
}

void		reverse_rotate(long *pile, int nb)
{
	int i;
	int tmp;

	i = nb - 1;
	tmp = pile[i];
	while (pile[i - 1] != null)
	{
		pile[i] = pile[i - 1];
		i--;
	}
	pile[i] = tmp;
}
