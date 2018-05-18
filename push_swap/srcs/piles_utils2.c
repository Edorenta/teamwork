/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piles_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyildiz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 18:25:31 by jyildiz-          #+#    #+#             */
/*   Updated: 2018/05/18 10:58:04 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_sort(long *pile, int start, int end)
{
	int		i;

	i = start - 1;
	while (++i < end)
		if (pile[i] >= pile[i + 1])
			return (0);
	return (1);
}

int		all_sort(t_env *env)
{
	if (!is_sort(env->a, 0, env->size - 1) || env->b[env->size - 1] != NONE)
		return (0);
	return (1);
}

double	mean_value(long *pile, int start, int end)
{
	int		i;
	int		sum;

	i = start - 1;
	sum = 0;
	if (end - start > 2)
	{
		while (++i <= end)
			sum += pile[i];
	}
	return ((end - start > 2) ? (double)sum / (double)(i - start) : 0);
}

int		mass_push(t_env *env, char to, int start, int end)
{
	int		i;

	i = to == 'b' ? env->a1 : env->b1;
	while (++i <= start)
		rotate(env, (to == 'b' ? 'a' : 'b'));
	i = to == 'b' ? env->a1 : env->b1;
	while (++i <= (end - start + 1))
		push(env, to);
	return (1);
}

int		swap_last(t_env *env, char which)
{
	if (which == 'a')
	{
		RRA;
		RRA;
		SA;
		RA;
		RA;
	}
	else
	{
		RRB;
		RRB;
		SB;
		RB;
		RB;
	}
	return (1);
}
