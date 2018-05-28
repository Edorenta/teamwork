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

static int 		insert_b(t_env *env)
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
		{
			if (rot_or_revrot(env) == 1)
			{
				if (B1 > env->mean / 4)
					RB;
				else
					PA;
			}
			else
				RRB;
		}
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

static void		finish_sort(t_env *env)
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
			if (B1 > MEAN_B)
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
	return (1);
}

int				quick_sort(t_env *env)
{
	env->mean = mean_value(env->a, env->a1, (env->size - 1));
	median_split(env, 0, env->mean);
	insert_b(env);
	finish_sort(env);
	return (all_sort(env) ? 1 : 0);
}
