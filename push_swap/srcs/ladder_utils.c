/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ladder_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 19:18:41 by pde-rent          #+#    #+#             */
/*   Updated: 2018/06/07 19:18:44 by pde-rent         ###   ########.fr       */
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

int		ra_or_rra(t_env *env, long max)
{
	int i;

	i = -1;
	while ((++i) < env->size)
	{
		if ((env->a1 + i) <= (env->size - 1) && env->a[env->a1 + i] < max)
			return (1);
		else if ((env->size - 1 - i) <= (env->a1)
				&& env->a[env->size - 1 - i] < max)
			return (-1);
	}
	return (0);
}

int		rb_or_rrb(t_env *env, long higher, long lower)
{
	int i;

	i = -1;
	if (env->a1 != (env->size - 1) && A1 == (A4 + 1))
		return (0);
	while ((++i) < env->size)
	{
		if ((env->b1 + i) <= (env->size - 1)
				&& env->b[env->b1 + i] == higher)
			return (1);
		else if ((env->b1 + i) <= (env->size - 1)
				&& env->b[env->b1 + i] == lower)
			return (2);
		else if (env->b[env->size - 1 - i] == higher)
			return (-1);
		else if (env->b[env->size - 1 - i] == lower)
			return (-2);
	}
	return (0);
}

int		optimize_step(t_env *env, int min, int max, double fract)
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
		insert_b(env, step, fract);
		optimize(env);
		tmp_cnt = count_moves(env->first_move);
		if (tmp_cnt < mv_cnt)
		{
			mv_cnt = tmp_cnt;
			best_step = step;
		}
		del_moves(env);
		duplicate_pile(tmp_pile, env->a, env->a1, env->size - 1);
	}
	return (best_step);
}

double	optimize_fract(t_env *env, double min, double max, int step)
{
	double	fract;
	double	best_fract;
	long	tmp_cnt;
	long	mv_cnt;
	long	tmp_pile[env->size];

	fract = min - 0.25;
	duplicate_pile(env->a, tmp_pile, env->a1, env->size - 1);
	mv_cnt = (long)env->size * 1000;
	while ((fract += 0.25) <= max)
	{
		ladder_split(env, step);
		insert_b(env, step, fract);
		optimize(env);
		tmp_cnt = count_moves(env->first_move);
		if (tmp_cnt < mv_cnt)
		{
			mv_cnt = tmp_cnt;
			best_fract = fract;
		}
		del_moves(env);
		duplicate_pile(tmp_pile, env->a, env->a1, env->size - 1);
	}
	return (best_fract);
}
