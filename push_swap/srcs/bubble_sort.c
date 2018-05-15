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

void	cpy_pile(t_env *env)
{
	int i;

	i = -1;
	while (++i < env->size)
		env->c[i] = env->a[i];
}

int		bb_sort(t_env *env)
{
	int		i;
	int		j;
	int		min;
	int		tmp;

	i = -1;
	cpy_pile(env);
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

void	ft_index(t_env *env)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < env->size)
	{
		j = 0;
		while (env->a[j] != env->c[i])
			j++;
		env->a[j] = i;
		i++;
	}
}
