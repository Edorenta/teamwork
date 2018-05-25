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
	int get_next;

	get_next = env->size - 1;
	while (get_next >= env->min)
	{
		if (rb_or_rrb(env, get_next) == 1)
			while (B1 != NONE && B1 != get_next)
				RB;
		else if (rb_or_rrb(env, get_next) == -1)
			while (B1 != NONE && B1 != get_next)
				RRB;
		PA;
		--get_next;
		dprintf(2, "next: %d min: %d\n", get_next, env->min);
	}
}

int				dumb_sort(t_env *env)
{
	env->mean = mean_value(env->a, env->a1, (env->size - 1));
	ladder_split(env, env->size / 25);
	//insert_b(env);
	smooth_push(env);
	return (all_sort(env) ? 1 : 0);
}
