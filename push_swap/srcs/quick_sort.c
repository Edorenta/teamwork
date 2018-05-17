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

int		quick_sort(t_env *env)
{
	//step 1: compare mean values of first and second half:
	int mean;

	//reinsert smartly on stack 1
	while (!all_sort(env))
	//for (int i = 0; i < 10 ; i++)
	{
		mean = mean_value(env->a, env->a1, (env->size - 1));
		dprintf(1, "mean: %d\n", mean);
		//put small half on stack 2
		median_split(env, 'b', env->a1, (env->size - 1), mean);
		pstr(1, "after split:",'\n');
		put_piles(env);
		//mass_smart_insert(env, 'a', (mean[1] > mean[0] ? mean[1] : mean[0]));
	}
	return (1);
}

int		median_split(t_env *env, char to, int start, int end, int mean)
{
	int		i;
	int		*j;
	long	*pilefrom;
	long	*pileto;

	pilefrom = (to == 'b' ? env->a : env->b);
	pileto = (to == 'b' ? env->b : env->a);
	i = (to == 'b' ? env->a1 : env->b1);
	j = (to == 'b' ? &env->b1 : &env->a1);
	while (++i <= start)
		rotate(env, (to == 'b' ? 'a' : 'b'));
	i = to == 'b' ? env->a1 : env->b1;
	while (++i <= end)
	{
		if (pilefrom[i] >= mean)
			push(env, to);
		pileto[*j] >= (mean * 1.5) ? rotate(env, to) : 0;
	}
	return (1);
}
