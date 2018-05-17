/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ext_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 17:59:42 by fmadura           #+#    #+#             */
/*   Updated: 2018/05/15 17:59:43 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		sort_pile(t_env *env)
{
	return (((ext_sort(env) && all_sort(env)) ? 1 : 0));
}

int		mean_value(long *pile, int start, int end)
{
	int		i;
	int		sum;

	i = start - 1;
	sum = 0;
	while (++i <= end)
		sum += pile[i];
	return (sum / (i - start));
}

int		mass_push(t_env *env, char to, int start, int end)
{
	int i;

	i = to == 'b' ? env->a1 : env->b1;
	while (++i <= start)
		rotate(env, (to == 'b' ? 'a' : 'b'));
	i = to == 'b' ? env->a1 : env->b1;
	while (++i <= (end - start + 1))
		push(env, to);
	return (1);
}

int		mass_smart_insert(t_env *env, char to)
{
	int *i;

	i = to == 'b' ? &env->a1 : &env->b1;
	while (*i != NONE)
		smart_insert(env, to);
}

int		smart_insert(t_env *env, char to)
{
	int i;
/*
	int max;
	int gap[4];

	//i = to == 'b' ? env->a1 : env->b1;
	gap[0] = labs(env->a[env->a1] - env->b[env->b1]);				//PA
	gap[1] = labs(env->a[env->size - 1] - env->b[env->b1]);			//RRA PA RA RA
	gap[2] = labs(env->a[env->a1] - env->b[env->size - 1]);			//RRB PA
	gap[3] = labs(env->a[env->size - 1] - env->b[env->size - 1]);	//RRR PA
	i = 0;
	max = 0;
	while (++i < 4)
		max = gap[i] > gap[i - 1] ? i : max;
*/
}

int		ext_sort(t_env *env)
{
	//step 1: compare mean values of first and second half:
	int mean[2];

	mean[0] = mean_value(env->a, env->a1, (env->size - 1) / 2);
	mean[1] = mean_value(env->a, 1 + (env->size - 1) / 2, env->size - 1);
	dprintf(1, "mean[0]: %d mean[1]: %d\n", mean[0], mean[1]);
	//put small half on stack 2
	mean[0] < mean[1] ? mass_push(env, 'b', env->a1, (env->size - 1) / 2)
	: mass_push(env, 'b', (env->size - (env->a1)) / 2, (env->size - 1));

	//reinsert smartly on stack 1
	mass_smart_insert(env, 'a');
	return (1);
}
