/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ladder_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 17:59:42 by pde-rent          #+#    #+#             */
/*   Updated: 2018/05/25 12:53:17 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		insert_b(t_env *env, int step)
{
	long	next_high;
	long	next_low;
	int		next_mv;

	next_high = (long)(env->size - 1);
	next_low = (long)(env->size - 1) - (env->size / step);
	//while (next_high >= (long)env->min)
	while (B1 != NONE)
	{
		//put_piles(env);
		//dprintf(2, "A1: %ld B1: %ld env->b1: %d env->size: %d\n", A1, B1, env->b1, env->size);
		next_high = A1 == NONE ? (env->size - 1) : MAX_B;
		next_low = A1 > A4 ? (MIN_A + 1) : (MIN_A - ((env->size / step) / 3));
		next_low = next_low < 0 ? 0 : next_low;
		next_mv = rb_or_rrb(env, next_high, next_low);
		//dprintf(2, "next_mv: %d, next high: %ld next low: %ld\n", next_mv, next_high, next_low);
		if (!next_mv)
		{
			//dprintf(2, "check for end of stack a to be pushed\n");
			//put_piles(env);
			B1 == (A1 - 1) ? PA : 0;
			while (A4 == (A1 - 1))
				RRA;
		}
		else if (next_mv == 1 && A4 != next_high){//dprintf(2, "target high\n");
			while (B1 != NONE && B1 != (next_high) && next_high >= next_low)
				RB;
			//dprintf(2, "1, next high: %ld next low: %ld\n", next_high, next_low);
		}
		else if (next_mv == -1 && A4 != next_high){//dprintf(2, "target high\n");
			while (B1 != NONE && B1 != (next_high) && next_high >= next_low)
				RRB;
			//dprintf(2, "2, next high: %ld next low: %ld\n", next_high, next_low);
		}
		else if (next_mv == 2 && A1 != next_low){//dprintf(2, "target low\n");
			while (B1 != NONE && B1 != (next_low) && next_high >= next_low)
				RB;
				//dprintf(2, "3, next high: %ld next low: %ld\n", next_high, next_low);
				//put_piles(env);
		}
		else if (next_mv == -2 && A1 != next_low){//dprintf(2, "target low\n");
			while (B1 != NONE && B1 != (next_low) && next_high >= next_low)
				RRB;
			//dprintf(2, "4, next high: %ld next low: %ld\n", next_high, next_low);
		}
		next_mv ? PA : 0;
		(next_mv == 2 || next_mv == -2) ? RA : 0;
		//dprintf(2, "next: %d min: %d\n", get_next, env->min);
	}
	while (A4 == (A1 - 1))
		RRA;
}

static int				ladder_split(t_env *env, int steps)
{
	int		i;
	int		j;
	long	max;
	long	min;
	long	passed[env->size];

	if (steps > 1)
	{
		j = -1;
		i = -1;
		while ((i += 2) < steps)
		{
			j = -1;
			max = (env->size / steps) * (i + 1);
			min = (env->size / steps) * i;
			pile_init(passed, env->size);
			while (A1 != NONE && !pile_contains(A1, passed, env->size))
			{
				//dprintf(2,"1");
				passed[++j] = A1;
				//dprintf(2, "A1: %ld\n", A1);
				if (A1 != NONE && A1 < min)
					PB;
				else if (A1 != NONE && A1 < max)
				{
					PB;
					RB;
				}
				else
					ra_or_rra(env, max) == 1 ? RA : RRA;
			}
			j++;
		}
		while (env->b1 != 0)
			PB;
	}
	return (1);
}

static int		optimize_step(t_env *env, int min, int max)
{
	int		step;
	int		best_step;
	long	tmp_cnt;
	long	mv_cnt;
	long	tmp_pile[env->size];

	step = min - 1;
	duplicate_pile(env->a, tmp_pile, env->a1, env->size - 1);
	mv_cnt = (long)env->size * 1000;
	while (++step <= max)
	{
		//dprintf(2, "n mv: %d\n", count_moves(env));
		ladder_split(env, step);
		insert_b(env, step);
		optimize(env);
		tmp_cnt = count_moves(env);
		if (tmp_cnt < mv_cnt)
		{
			mv_cnt = tmp_cnt;
			best_step = step;
		}
		dprintf(2, "step: %d moves: %ld\n", step, tmp_cnt);
		del_moves(env);
		duplicate_pile(tmp_pile, env->a, env->a1, env->size - 1);
	}
	dprintf(2, "best step: %d\n", best_step);
	return (best_step);
}

int				ladder_sort(t_env *env)
{
	int step;

//	step = 6;
	step = optimize_step(env, 2, 50);
	env->mean = mean_value(env->a, env->a1, (env->size - 1));
	ladder_split(env, step);
	dprintf(2, "insert!!\n");
	insert_b(env, step);
	return (all_sort(env) ? 1 : 0);
}
