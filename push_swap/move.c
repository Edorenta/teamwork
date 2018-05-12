/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyildiz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 20:01:50 by jyildiz-          #+#    #+#             */
/*   Updated: 2018/05/12 15:03:48 by jyildiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		swap(long *pile, int size)
{
	int	i;
	int	tmp;

	i = 0;
	while (pile[i] == NONE && i < size)
		i++;
	if (i < size && pile[i] != NONE && pile[i + 1] != NONE)
	{
		tmp = pile[i];
		pile[i] = pile[i + 1];
		pile[i + 1] = tmp;
	}
}

t_env		*push(t_env *env)
{
	int		i;
	int		j;
	int		tmp;

	i = env->a1;
	j = env->b1;
	if (env->a[i] != NONE)
	{
		tmp = a[i];
		a[i] = b[j];
		b[j] = tmp;
	}
}

void		rotate(long *pile, int size, int felem)
{
	int	i;
	int tmp;

	i = felem;
	if (i < size)
	{
		tmp = pile[i];
		while (i < size - 1)
		{
			pile[i] = pile[i + 1];
			i++;
		}
		pile[i] = tmp;
	}
}

void		reverse_rotate(long *pile, int size)
{
	int i;
	int tmp;

	i = size - 1;
	tmp = pile[i];
	while (pile[i - 1] != NONE)
	{
		pile[i] = pile[i - 1];
		i--;
	}
	pile[i] = tmp;
}
