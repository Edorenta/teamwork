/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyildiz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 20:01:50 by jyildiz-          #+#    #+#             */
/*   Updated: 2018/05/12 15:18:29 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	*swap(long *pile, int size, int feleim)
{
	int		tmp;
	int		i;

	i = felem;
	if (i < size && pile[i] != NONE && pile[i + 1] != NONE)
	{
		tmp = pile[i];
		pile[i] = pile[i + 1];
		pile[i + 1] = tmp;
	}
	return (pile);
}

t_env	*push(t_env *env)
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
	return (env);
}

long	*rotate(long *pile, int size, int felem)
{
	int		i;
	int		tmp;

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
	return (pile);
}

long	*reverse_rotate(long *pile, int size)
{
	int		i;
	int		tmp;

	i = size - 1;
	tmp = pile[i];
	while (pile[i - 1] != NONE)
	{
		pile[i] = pile[i - 1];
		i--;
	}
	pile[i] = tmp;
	return (pile);
}
