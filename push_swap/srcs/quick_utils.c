/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_utils.c                                      :+:      :+:    :+:   */
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
