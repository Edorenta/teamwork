/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ext_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 17:59:42 by fmadura           #+#    #+#             */
/*   Updated: 2018/05/23 17:53:34 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int 	quick_fix_a(t_env *env)
{
	if (A1 > env->mean && A1 > A2)
		SA;
	if (A1 > env->mean)
		RA;	
	return (1);
}

static int 	quick_fix_b(t_env *env)
{
	put_piles(env);
	printf("env->a1  : %d \n", env->a1);
	printf("env->b1  : %d \n", env->b1);
	if (B1 < MEAN_B && B1 > B2)
		SB;
	if (B1 > MEAN_B && B1 > B2)
		RB;
	if (B1 > MEAN_B && B1 > B4)
		RRB;
	return (1);
}

static int	a_or_b(t_env *env)
{
	int i;

	i = 0;
	while (i < env->size)
	{
		if (env->a[i] == env->min)
			return (1);
		if (env->b[i] == env->min)
			return (0);
		i++;
	}
	return (-1);
}

static int 	insert_b(t_env *env)
{
	while (B1 != NONE)
	{
		if (B1 == env->min)
		{
			PA;
			RA;
			env->min++;
			if (a_or_b(env) == 1)
			{
				while (A1 <= env->mean)
				{
					if (A1 == env->min)
					{
						RA;
						env->min++;
					}
					else
						PB;
				}
			}
		}
		else
			PA;
		if (A1 == env->min)
		{
			RA;
			env->min++;
			if (a_or_b(env) == 1)
			{
				while (A1 <= env->mean)
				{
					if (A1 == env->min)
					{
						RA;
						env->min++;
					}
					else
						PB;
				}
			}
		}
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
			while (B1 != NONE && A1 != env->min && a_or_b(env) == 0)
				PA;
		}
		else if (a_or_b(env) == 1)
		{
			PB;
			if (B1 > MEAN_B && B1 > B2)
				RB;
		}
		else if (a_or_b(env) == 0)
			PA;
	}
}


static int		median_split(t_env *env, double min, double max)
{
	while (env->b1 == NONE || env->a1 < env->b1)
	{
		if (A1 <= max && A1 >= min)
			PB;
		quick_fix_a(env);
		quick_fix_b(env);		
	}
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
