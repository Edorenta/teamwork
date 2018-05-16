/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piles_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyildiz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 18:25:31 by jyildiz-          #+#    #+#             */
/*   Updated: 2018/05/15 18:03:58 by fmadura          ###   ########.fr       */
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

void	put_piles(t_env *env)
{
	int i;
	//dprintf(2, "env->a[a1]: %ld\n", env->a[env->a1]);
	//dprintf(2, "env->b[b1]: %ld\n", env->b[env->b1]);
	
	i = env->a1 - 1;
	(env->a[env->a1] != NONE) ? pstr(2, "Pile A:", '\n')
	: pstr(2, "Pile A: EMPTY", '\n');
	if (env->a[env->a1] != NONE)
		while (++i < env->size && env->a[i] && env->a[i] != NONE)
			if (i == env->size - 1)
				plong(2, env->a[i], '\n');
			else
				plong(2, env->a[i], ' ');
	i = env->b1 - 1;
	(env->b[env->b1] != NONE) ? pstr(2, "Pile B:", '\n')
	: pstr(2, "Pile B: EMPTY", '\n');
	if (env->b[env->b1] != NONE)
		while (++i < env->size && env->b[i] && env->b[i] != NONE)
			if (i == env->size - 1)
				plong(2, env->b[i], '\n');
			else
				plong(2, env->b[i], ' ');
	write(2, "\n", 1);
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
