/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 17:17:01 by fmadura           #+#    #+#             */
/*   Updated: 2018/06/04 18:36:44 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	del_moves(t_env *env)
{
	t_move *mv;
	t_move *mv_next;

	if (env->first_move)
	{
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
}

void	del_move(t_env *env, t_move *mv)
{
	t_move	*prev;
	t_move	*next;

	if (mv && env->first_move)
	{
		prev = mv->prev;
		next = mv->next;
		if (mv == env->this_move && mv == env->first_move)
		{
			env->this_move = NULL;
			env->first_move = NULL;
		}
		else if (mv == env->this_move)
		{
			prev ? (env->this_move = prev) : (env->this_move = NULL);
			env->this_move ? env->this_move->next = NULL : 0;
		}
		if (env->this_move && prev && next)
		{
			prev->next = next;
			next->prev = prev;
		}
		else if (prev && env->this_move != env->first_move)
			prev->next = NULL;
		else if (next && env->this_move != env->first_move)
			next->prev = NULL;
		free(mv);
	}
}

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
		while (start  != NULL)
		{
			start->prev ? put_move(start, sep) : put_move(start, '\n');
			if (start->prev)
				start = start->prev;
			else
				return (1);
		}
	return (0);
}
