/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ladder_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 17:59:42 by pde-rent          #+#    #+#             */
/*   Updated: 2018/05/25 12:53:17 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		pile_contains(long i, long *pile, int size)
{
	while (--size >= 0)
		if (i == pile[size])
			return (1);
	return (0);
}

void	pile_init(long *pile, int size)
{
	while (--size >= 0)
		pile[size] = NONE;
}

int		ra_or_rra(t_env *env, long max)
{
	int i;

	i = -1;
	while ((++i) < env->size)
	{
		if ((env->a1 + i) <= (env->size - 1) && env->a[env->a1 + i] < max)
			return (1);
		else if ((env->size - 1 - i) <= (env->a1) && env->a[env->size - 1 - i] < max)
			return (-1);
	}
	return (0);
}

int		rb_or_rrb(t_env *env, long higher, long lower)
{
	int i;

	i = -1;
	//dprintf(2, "next high: %ld next low: %ld\n", higher, lower);
	if (env->a1 != (env->size - 1) && A1 == (A4 + 1))
		return (0);
	while ((++i) < env->size)
	{

		if ((env->b1 + i) <= (env->size - 1) && env->b[env->b1 + i] == higher)
			return (1);
		else if ((env->b1 + i) <= (env->size - 1) && env->b[env->b1 + i] == lower)
			return (2);
		else if (env->b[env->size - 1 - i] == higher)
			return (-1);
		else if (env->b[env->size - 1 - i] == lower)
			return (-2);
	}
	return (0);
}

/*
int		rb_or_rrb(t_env *env, long n)
{
	int i;

	i = -1;
	while (++i < env->size)
		if (env->b[i] == n)
			return((i - env->b1 > env->size - 1 - i) ? -1 : 1);
	return (0);
}
*/