/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ext_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 17:59:42 by fmadura           #+#    #+#             */
/*   Updated: 2018/05/25 12:53:17 by jyildiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


static int	pile_contains(long i, long *pile, int size)
{
	while (--size >= 0)
		if (i == pile[size])
			return (1);
	return (0);
}

static void	pile_init(long *pile, int size)
{
	while (--size >= 0)
		pile[size] = NONE;
}

static int		rb_or_rrb(t_env *env, long n)
{
	int i;

	i = -1;
	while (++i < env->size)
		if (env->b[i] == n)
			return((i - env->b1 > env->size - 1 - i) ? -1 : 1);
	return (0);
}

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

int		ladder_split(t_env *env, int steps)
{
	int		i;
	int		j;
	long	max;
	long	min;
	long	passed[env->size];

	if (steps > 1)
	{
		j = -1;
		i = steps;
		//simplistic but the data is rebased >> OK
		//dprintf(1, "max: %ld\n", max);
		while ((i -= 2) > 1)
		{
			//dprintf(1, "5\n");
			j = -1;
			max = (env->size / steps) * i;
			min = (env->size / steps) * (i - 1);
			pile_init(passed, env->size);
			//ladder scale A
			while (!pile_contains(A1, passed, env->size))
			{
				//dprintf(1, "%ld\n", B1);
				passed[++j] = A1;
				//dprintf(2, "a1: %ld, min: %ld max: %ld\n", A1, min, max);
				if (A1 <= min)
				{
					RA;
				}
				else if (A1 > max)			//non-selective push
				{
					PB;
					RB;
				}
				else if (A1 > min)
				{
					PB;
				}
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

int				dumb_sort(t_env *env)
{
	env->mean = mean_value(env->a, env->a1, (env->size - 1));
	ladder_split(env, env->size / 25);
	//insert_b(env);
	smooth_push(env);
	return (all_sort(env) ? 1 : 0);
}
