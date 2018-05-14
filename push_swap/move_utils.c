/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyildiz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 20:01:50 by jyildiz-          #+#    #+#             */
/*   Updated: 2018/05/14 19:25:27 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		new_move(const char *id, )
{

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

void	free_move(t_move *mv)
{
	env->a ? free(env->a) : 0;
	env->b ? free(env->b) : 0;
	env->c ? free(env->c) : 0;
}