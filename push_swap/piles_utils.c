/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piles_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyildiz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 18:25:31 by jyildiz-          #+#    #+#             */
/*   Updated: 2018/05/14 20:17:29 by jyildiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_sort(long *pile, int size, int felem)
{
	int		i;

	i = felem - 1;
	while (++i < size - 1)
		if (pile[i] >= pile[i + 1])
			return (0);
	return (1);
}

int		all_sort(t_env *env)
{
	if (!is_sort(env->a, env->size, 0) || env->b[env->size - 1] != NONE)
		return (0);
	return (1);
}

int		no_duplicates(long *pile, int size)
{
	long *i;
	long *j;

	j = pile;
	while (j != (pile + size - 1))
	{
		i = j + 1;
		while (i != (pile + size))
		{
		 	///dprintf(1, "i:%ld j:%ld\n", *i,*j);
			if (i != j && *i == *j)
				return (0);
			++i;
		}
		++j;
	}
	return (1);
}

int		alloc_piles(t_env *env)
{
	int i;

	i = -1;
	if (!(env->a = (long *)malloc(sizeof(long) * env->size))
		|| !(env->b = (long *)malloc(sizeof(long) * env->size))
		|| !(env->c = (long *)malloc(sizeof(long) * env->size)))
		put_error(env, "Error: piles allocation failed");
	while (++i < env->size)
	{
		env->a[i] = NONE;
		env->b[i] = NONE;
		env->c[i] = NONE;
	}
	return (1);
}

void	free_piles(t_env *env)
{
	env->a ? free(env->a) : 0;
	env->b ? free(env->b) : 0;
	env->c ? free(env->c) : 0;
}
