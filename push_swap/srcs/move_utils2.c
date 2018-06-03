/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 17:17:01 by fmadura           #+#    #+#             */
/*   Updated: 2018/06/03 18:20:35 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	undo_move(t_env *env, t_move *mv)
{
	(!scmp(mv->id, "pa")) ? PB : 0;
	(!scmp(mv->id, "pb")) ? PA : 0;
	(!scmp(mv->id, "ra") || !scmp(mv->id, "rr")) ? RRA : 0;
	(!scmp(mv->id, "rb") || !scmp(mv->id, "rr")) ? RRB : 0;
	(!scmp(mv->id, "rra") || !scmp(mv->id, "rrr")) ? RA : 0;
	(!scmp(mv->id, "rrb") || !scmp(mv->id, "rrr")) ? RB : 0;
	(!scmp(mv->id, "sa") || !scmp(mv->id, "ss")) ? SA : 0;
	(!scmp(mv->id, "sb") || !scmp(mv->id, "ss")) ? SB : 0;
	(!scmp(mv->id, "rrr") || !scmp(mv->id, "rr") || !scmp(mv->id, "ss"))
	? del_move(env, env->this_move) : 0;
	del_move(env, env->this_move);
	del_move(env, env->this_move);
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
		while (start != NULL)
		{
			start->prev ? put_move(start, sep) : put_move(start, '\n');
			if (start->prev)
				start = start->prev;
			else
				return (1);
		}
	return (0);
}
