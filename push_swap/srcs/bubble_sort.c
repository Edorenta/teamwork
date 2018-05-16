/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyildiz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 14:29:14 by jyildiz-          #+#    #+#             */
/*   Updated: 2018/05/15 10:35:44 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		bb_sort(t_env *env)
{
	int		i;
	int		j;
	int		min;
	int		tmp;

	i = -1;
	duplicate_pile(env);
	while (++i < env->size - 1)
	{
		min = env->c[i];
		tmp = i;
		j = i + 1;
		while (j < env->size)
		{
			if (min > env->c[j])
			{
				min = env->c[j];
				tmp = j;
			}
			j++;
		}
		env->c[tmp] = env->c[i];
		env->c[i] = min;
	}
	return (all_sort(env) ? 1 : 0);
}
