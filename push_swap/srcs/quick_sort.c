/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ext_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 17:59:42 by fmadura           #+#    #+#             */
/*   Updated: 2018/05/18 09:39:14 by jyildiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int 	quick_fix_a(t_env *env, double mean)
{
	//pstr(2, "before A fix:",'\n');
	//put_piles(env);

	//if (A1 > A2 && A1 < MEAN_A)
	if (A1 > mean)
	{
		if (A1 > MEAN_A)
		{
			if (A2 > A1)
				RA;
			RA;
		}
	}
	//pstr(2, "after A fix:",'\n');
	//put_piles(env);
	return (1);
}

static int 	quick_fix_b(t_env *env, double mean)
{
	//pstr(2, "before B fix:",'\n');
	//put_piles(env);
	if (B1 < mean)
	{
		if (B1 < MEAN_B)
		{
			if (B2 < B1)
				RB;
			RB;
		}
	}
	//pstr(2, "aft
	//pstr(2, "after B fix:",'\n');
	//put_piles(env);
	return (1);
}

static int 	insert_b(t_env *env, double mean)
{
	//pstr(2, "before insertion:",'\n');
	//put_piles(env);

	while (B1 != NONE)
	{
		quick_fix_a(env, mean);
		quick_fix_b(env, mean);
		PA;
		quick_fix_a(env, mean);
		quick_fix_b(env, mean);
		//pstr(2, "after insertion:",'\n');
		//put_piles(env);
	}
	return (1);
}

static int		median_split(t_env *env, double mean, double coef)
{
	mean *= coef;
	while (env->b1 == NONE || env->a1 < env->b1)
	{
		if (A1 <= mean)
		{
			PB;
			quick_fix_a(env, mean);
			quick_fix_b(env, mean);
		}
		all_sort(env) ? 0 : RA;
		//printf("i: %d j: %d\n", *i, *j);
	}
	//quick_fix_a(env);
	insert_b(env, mean);
	return (1);
}

int		quick_sort(t_env *env)
{
	//step 1: compare mean values of first and second half:
	double mean;

	mean = mean_value(env->a, env->a1, (env->size - 1));
	//put small half on stack 2
	median_split(env, mean, 1);
	return (1);
}
