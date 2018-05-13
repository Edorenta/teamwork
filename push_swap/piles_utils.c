/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piles_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyildiz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 18:25:31 by jyildiz-          #+#    #+#             */
/*   Updated: 2018/05/12 12:06:27 by jyildiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		no_duplicates(int *pile, int size)
{
	int *i;
	int *j;

	j = pile;
	while (j != (pile + size - 1))
	{
		i = j + 1;
		while (i != (pile + size))
		{
		 	//dprintf(1, "i:%d j:%d\n", *i,*j);
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
	if (!(env->a = (int *)malloc(sizeof(int) * env->size))
		|| !(env->b = (int *)malloc(sizeof(int) * env->size)))
		put_error(env, "Error");
	while (++i < env->size)
	{
		env->a[i] = NONE;
		env->b[i] = NONE;
	}
	return (1);
}

void	free_piles(t_env *env);
{
	env->a ? free(a) : 0;
	env->b ? free(b) : 0;
}
