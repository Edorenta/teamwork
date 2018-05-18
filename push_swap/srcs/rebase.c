/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rebase.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyildiz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 14:29:14 by jyildiz-          #+#    #+#             */
/*   Updated: 2018/05/18 11:04:13 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	duplicate_pile(long *src, long *dest, int start, int end)
{
	int i;

	i = start - 1;
	while (++i <= end && src[i] != NONE)
		dest[i] = src[i];
}

void	index_pile(t_env *env)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	duplicate_pile(env->a, env->c, env->a1, env->size - 1);
	bb_sort(env->c, env->a1, env->size - 1);
	while (i < env->size)
	{
		j = 0;
		while (env->a[j] != env->c[i])
			j++;
		env->a[j] = i;
		i++;
	}
}
