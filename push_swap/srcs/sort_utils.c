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

int 	quick_fix_a(t_env *env)
{
	if (A1 > env->mean && A1 > A2)
		SA;
	if (A1 > env->mean)
		RA;	
	return (1);
}

int 	quick_fix_b(t_env *env)
{
	if (B1 < MEAN_B && B1 > B2)
		SB;
	if (B1 > MEAN_B && MEAN_B > 0)
		RB;
	return (1);
}

int		rot_or_revrot(t_env *env)
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

int		a_or_b(t_env *env)
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

int		median_split(t_env *env, double min, double max)
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

static int	pile_contains(long i, long *pile, int size)
{
	while (--size >= 0){
		//dprintf(2, "i: %ld pile[size]: %ld\n", i, pile[size]);
		if (i == pile[size])
			return (1);
	}
	return (0);
}

static void	pile_init(long *pile, int size)
{
	while (--size >= 0)
		pile[size] = NONE;
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
		i = steps - 1;
		max = (env->size / steps) * i;					//simplistic but the data is rebased >> OK
		//dprintf(1, "max: %ld\n", max);
		pile_init(passed, env->size);
		while (!pile_contains(A1, passed, env->size))
		{	//first sort
			passed[++j] = A1;
			if (A1 <= max && A1 >= 0)
				PB;
			else
				RA;
			//dprintf(1, "4\n");
		}
		while (--i)
		{
			//dprintf(1, "5\n");
			j = -1;
			max = (env->size / steps) * i;
			min = (env->size / steps) * i - 1;
			pile_init(passed, env->size);
			//split pile B in 3 parts
			while (!pile_contains(B1, passed, env->size))
			{
				//dprintf(1, "%ld\n", B1);
				passed[++j] = B1;
				if (B1 <= max && B1 > min)	//selective push
				{
					PA;
					RA;
				}
				else if (B1 <= max)			//non-selective push
				{
					RB;
				}
				else
					PA;
			}
			//get back the A part onto stack B
			j++;
			while (A1 <= max)
				PB;
			while (A4 <= max)
			{
				PB;
				RB;
			}
		}
	}
	return (1);
}