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

int		sort_pile(t_env *env)
{
	return (((quick_sort(env) && all_sort(env)) ? 1 : 0));
}

inline	static void put_pile(long *pile, int start, int end, const char *title)
{
	int i;

	i = start - 1;
	pstr(2, title, '\n');
	pile[start] == NONE ? pstr(2, "empty", '\n') : 0;
	if (pile[start] != NONE)
		while (++i <= end && pile[i] != NONE)
			if (i == end)
				plong(2, pile[i], '\n');
			else
				plong(2, pile[i], ' ');
}

void	put_piles(t_env *env)
{
	//dprintf(2, "env->a[a1]: %ld\n", env->a[env->a1]);
	//dprintf(2, "env->b[b1]: %ld\n", env->b[env->b1]);
	put_pile(env->a, env->a1, env->size - 1, "Pile A:");
	put_pile(env->b, env->b1, env->size - 1, "Pile B:");
	//put_pile(env->c, env->a1, env->size - 1, "Pile C:");
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
