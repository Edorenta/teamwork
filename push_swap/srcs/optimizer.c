/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyildiz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 18:26:08 by jyildiz-          #+#    #+#             */
/*   Updated: 2018/05/29 14:25:23 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_move	*reduce_del(t_env *env, t_move *iter)
{
	t_move *del;

	del = iter;
	iter = iter->next;
	del_move(env, del);
	return (iter);
}

static int		reduce_check(t_move *iter, char *s1, char *s2)
{
	return ((scmp(iter->id, s1) == 0 && scmp(iter->next->id, s2) == 0)
		|| (scmp(iter->id, s2) == 0 && scmp(iter->next->id, s1) == 0));
}

int				optimize(t_env *env)
{
	t_move	*iter;

	iter = env->first_move;
	while (iter != NULL)
	{
		if (iter->next != NULL)
		{
			if (reduce_check(iter, "ra", "rb") == 1)
			{
				iter = reduce_del(env, iter);
				iter->id[1] = 'r';
			}
			if (reduce_check(iter, "pa", "pb") == 1)
				iter = reduce_del(env, reduce_del(env, iter));
			if (reduce_check(iter, "rra", "rrb") == 1)
			{
				iter = reduce_del(env, iter);
				iter->id[2] = 'r';
			}
			if (env->first_move == NULL)
				env->first_move = iter;
		}
		iter = iter->next;
	}
	return (count_moves(env->first_move));
}
