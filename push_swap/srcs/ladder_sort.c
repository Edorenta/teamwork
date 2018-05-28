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

static void		smooth_push(t_env *env)
{
	long get_next;

	get_next = (long)(env->size - 1);
	while (get_next >= (long)env->min)
	{
		if (rb_or_rrb(env, get_next) == 1)
			while (B1 != NONE && B1 != get_next){
				//dprintf(2, "next: %ld B1: %ld >>RB\n", get_next, B1);
				RB;
			}
		else if (rb_or_rrb(env, get_next) == -1){
			while (B1 != NONE && B1 != get_next)
				//dprintf(2, "next: %ld B1: %ld >>RRB\n", get_next, B1);
				RRB;
			}
		PA;
		--get_next;
		//dprintf(2, "next: %d min: %d\n", get_next, env->min);
	}
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
		i = 0;
		//simplistic but the data is rebased >> OK
		//dprintf(1, "max: %ld\n", max);
		while ((i += 2) < steps)
		{
			//dprintf(1, "5\n");
			j = -1;
			max = (env->size / steps) * (i + 1);
			min = (env->size / steps) * i;
			pile_init(passed, env->size);
			//ladder scale A
			while (!pile_contains(A1, passed, env->size))
			{
				//dprintf(1, "%ld\n", B1);
				passed[++j] = A1;
				//dprintf(2, "a1: %ld, min: %ld max: %ld\n", A1, min, max);
				if (A1 < min)
					PB;
				else if (A1 < max)			//non-selective push
				{
					PB;
					RB;
				}
				else
					RA;
			}
			//get back the A part onto stack B
			j++;
			/*
			while (A4 <= max)
			{
				PB;
				RB;
			}
			*/
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
		ladder_split(env, step);
		smooth_push(env);
		tmp_cnt = count_moves(env);
		if (tmp_cnt < mv_cnt)
		{
			mv_cnt = tmp_cnt;
			best_step = step;
		}
		dprintf(2, "step: %d moves: %ld\n", step, tmp_cnt);
		del_moves(env);
		env->first_move = NULL;
		env->this_move = NULL;
		duplicate_pile(tmp_pile, env->a, env->a1, env->size - 1);
	}
	dprintf(2, "best step: %d\n", best_step);
	return (best_step);
}

int				ladder_sort(t_env *env)
{
	env->mean = mean_value(env->a, env->a1, (env->size - 1));
	ladder_split(env, optimize_step(env, 2, 120));
	smooth_push(env);
	return (all_sort(env) ? 1 : 0);
}
