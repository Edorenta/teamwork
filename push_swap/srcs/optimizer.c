/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyildiz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 18:26:08 by jyildiz-          #+#    #+#             */
/*   Updated: 2018/05/23 11:06:23 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reduce_list(t_env *env)
{
	t_move	*iter;
	t_move	*del;

	iter = env->first_move;
	while (iter != NULL)
	{
		if (iter->next != NULL)
		{
			if ((scmp(iter->id, "ra") == 0 && scmp(iter->next->id, "rb") == 0)
			|| (scmp(iter->id, "rb") == 0 && scmp(iter->next->id, "ra") == 0))
			{
				del = iter;
				iter = iter->next;
				del_move(del);
				iter->id[1] = 'r';
			}
			if ((scmp(iter->id, "pa") == 0 && scmp(iter->next->id, "pb") == 0)
			|| (scmp(iter->id, "pb") == 0 && scmp(iter->next->id, "pa") == 0))
			{
				del = iter;
				iter = iter->next;
				del_move(del);
				del = iter;
				iter = iter->next;
				del_move(del);
			}
			if (env->first_move == NULL)
				env->first_move = iter;
		}
		iter = iter->next;
	}
}

int		optimize(t_env *env)
{
	reduce_list(env);
	return (count_moves(env));
}
