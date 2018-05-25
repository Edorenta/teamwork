/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ext_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 17:59:42 by fmadura           #+#    #+#             */
/*   Updated: 2018/05/22 17:14:34 by jyildiz-         ###   ########.fr       */
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
	if (B1 < MEAN_B && B1 > B2)
		SB;
	if (B1 > MEAN_B && MEAN_B > 0)
		RB;
	return (1);
}

static int	rot_or_revrot(t_env *env)
{
	int i;

	i = 0;
	while (i < env->size)
	{
		if (env->a[i] == env->min)
		{
			if (i - env->a1 > env->size - 1 - i)
				return (-1);
			else
				return (1);
		}
		if (env->b[i] == env->min)
		{
			if (i - env->b1 > env->size - 1 - i)
				return (-1);
			else
				return (1);
		}
		i++;
	}
	return (0);
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
		{
			if (rot_or_revrot(env) == 1)
				PA;
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
	insert_b(env);
	finish_sort(env);
	return (1);
}

int		quick_sort(t_env *env)
{
	env->mean = mean_value(env->a, env->a1, (env->size - 1));
	median_split(env, 0, env->mean);
	return (1);
}
