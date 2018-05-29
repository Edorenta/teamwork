/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 17:17:01 by fmadura           #+#    #+#             */
/*   Updated: 2018/05/29 17:18:39 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	del_moves(t_env *env)
{
	t_move *mv;
	t_move *mv_next;

	mv = env->first_move;
	while (mv->next && (mv_next = mv->next))
	{
		free(mv);
		mv = mv_next;
	}
	mv ? free(mv) : 0;
	env->first_move = NULL;
	env->this_move = NULL;
}

void	del_move(t_move *mv)
{
	t_move	*prev;
	t_move	*next;

	if (mv)
	{
		prev = mv->prev;
		next = mv->next;
		if (prev && next)
		{
			prev->next = next;
			next->prev = prev;
		}
		else if (prev)
			prev->next = NULL;
		else if (next)
			next->prev = NULL;
		free(mv);
	}
}

void	put_move(t_move *mv, char end)
{
	mv ? pstr(1, mv->id, end) : 0;
}

int		put_moves(t_move *start, int dir, char sep)
{
	if (dir == 1)
		while (start)
		{
			start->next ? put_move(start, sep) : put_move(start, '\n');
			if (start->next)
				start = start->next;
			else
				return (1);
		}
	else if (dir == 2)
		while (start)
		{
			start->prev ? put_move(start, sep) : put_move(start, '\n');
			if (start->prev)
				start = start->prev;
			else
				return (1);
		}
	return (0);
}
