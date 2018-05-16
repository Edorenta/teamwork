/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rebase.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyildiz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 14:29:14 by jyildiz-          #+#    #+#             */
/*   Updated: 2018/05/15 10:35:44 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	duplicate_pile(t_env *env)
{
	int i;

	i = -1;
	while (++i < env->size)
		env->c[i] = env->a[i];
}

void	index_pile(t_env *env)
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
