/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ext_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 17:59:42 by fmadura           #+#    #+#             */
/*   Updated: 2018/05/22 13:33:40 by jyildiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int 	quick_fix_a(t_env *env)
{
	//pstr(2, "before A fix:",'\n');
	//put_piles(env);

	//if (A1 > A2 && A1 < MEAN_A)
	if (A1 > env->mean && A1 > A2)
		SA;
	/*else if (A1 > MEAN_A && A4 < A1)
	{
		RRA;
		SA;
	}*/
	if (A1 > env->mean)
		RA;	
	//pstr(2, "after A fix:",'\n');
	//put_piles(env);
	return (1);
}

static int 	quick_fix_b(t_env *env)
{
	//pstr(2, "before B fix:",'\n');
	//put_piles(env);
	/*if (B1 < env->mean)
	{
		if (B1 < MEAN_B)
		{
			if (B2 < B1)
				RB;
			RB;
		}
	}*/
	if (B1 < MEAN_B && B1 > B2)
		SB;
	/*else if (B1 > MEAN_B && B4 < B1)
	{
		RRB;
		SB;
	}*/
	if (B1 > MEAN_B)
		RB;
	//pstr(2, "aft
	//pstr(2, "after B fix:",'\n');
	//put_piles(env);
	return (1);
}

static int 	insert_b(t_env *env)
{
	//pstr(2, "before insertion:",'\n');
	//put_piles(env);

	while (B1 != NONE)
	{
		//printf("B1:%ld, env->min:%d\n", B1, env->min);
		if (B1 == env->min)
		{
			PA;
			RA;
			env->min++;
			while (A1 < env->mean)
			{
				if (A1 == env->min)
				{
					RA;
					env->min++;
				}
				if (A1 < env->mean)
					PB;
			}
		}
		else
		{
			PA;
			if (A1 > A2)
				SA;
		}
		if (A1 == env->min)
		{
			RA;
			env->min++;
			while (A1 < env->mean)
				PB;
		}
	//	quick_fix_a(env, env->mean);
//		quick_fix_b(env, env->mean);
		//PA;
		//quick_fix_a(env, env->mean);
		//quick_fix_b(env, env->mean);
		//pstr(2, "after insertion:",'\n');
		//put_piles(env);
	}
	return (1);
}

void			finish_sort(t_env *env)
{
	while (A1 >= env->mean)
	{
		if (A1 == env->min)
		{
			RA;
			env->min++;
			while (B1 != NONE)
				PA;
		}
		else
		{
			PB;
			if (B1 > MEAN_B)
				RB;
		}
	}
}


static int		median_split(t_env *env, double min, double max)
{
	while (env->b1 == NONE || env->a1 < env->b1)
	{
		if (A1 <= max && A1 >= min)
			PB;
		//	quick_fix_a(env, env->mean);
		//	quick_fix_b(env, env->mean);
		//all_sort(env) ? 0 : RA;
		quick_fix_a(env);
		quick_fix_b(env);		//printf("i: %d j: %d\n", *i, *j);
	}
	//quick_fix_a(env);
	insert_b(env);
	finish_sort(env);
	return (1);
}

int		quick_sort(t_env *env)
{
	//step 1: compare env->mean values of first and second half:
	env->mean = mean_value(env->a, env->a1, (env->size - 1));
	//put small half on stack 2
	median_split(env, 0, env->mean);
	return (1);
}
