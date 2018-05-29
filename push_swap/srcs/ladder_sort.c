/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ladder_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 17:59:42 by pde-rent          #+#    #+#             */
/*   Updated: 2018/05/29 18:34:03 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		insert_b_if(t_env *env, long nx_mv, long nx_l, long nx_h)
{
	if (!nx_mv)
	{
		B1 == (A1 - 1) ? PA : 0;
		while (A4 == (A1 - 1))
			RRA;
	}
	else if ((nx_mv == 1 || nx_mv == -1) && A4 != nx_h)
		while (B1 != NONE && B1 != MAX_B)
			nx_mv == 1 ? RB : RRB;
	else if ((nx_mv == 2 || nx_mv == -2) && A1 != nx_l)
		while (B1 != NONE && B1 != (nx_l) && nx_h >= nx_l)
			nx_mv == 2 ? RB : RRB;
	(nx_mv) ? PA : 0;
	(nx_mv == 2 || nx_mv == -2) ? RA : 0;
}

void			insert_b(t_env *env, int step, double fract)
{
	long	next_high;
	long	next_low;
	int		next_mv;

	while (B1 != NONE)
	{
		next_high = MAX_B;
		next_low = A1 > A4 ? (MIN_A + 1) : (MIN_A - ((env->size / step) / fract));
		next_low = next_low < 0 ? 0 : next_low;
		next_mv = rb_or_rrb(env, next_high, next_low);
		insert_b_if(env, next_mv, next_low, next_high);
		//next_mv && ? PA : 0;
		//(next_mv == 2 || next_mv == -2) ? RA : 0;
	}
	while (A4 == (A1 - 1))
		RRA;
}

static int		ladder_split_action(t_env *env, int min, int max)
{
	if (A1 != NONE && A1 < min)
		PB;
	else if (A1 != NONE && A1 < max)
	{
		PB;
		RB;
	}
	else
		ra_or_rra(env, max) == 1 ? RA : RRA;
	return (1);
}

void			ladder_split(t_env *env, int steps)
{
	int		i;
	int		j;
	long	max;
	long	min;
	long	passed[env->size];

	if (steps > 1)
	{
		i = -1;
		while ((i += 2) < steps)
		{
			j = -1;
			max = (env->size / steps) * (i + 1);
			min = (env->size / steps) * i;
			pile_init(passed, env->size);
			while (A1 != NONE && !pile_contains(A1, passed, env->size))
			{
				passed[++j] = A1;
				ladder_split_action(env, min, max);
			}
		}
		while (A1 != NONE)
			PB;
	}
}
