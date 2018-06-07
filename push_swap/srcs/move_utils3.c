/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 19:19:24 by pde-rent          #+#    #+#             */
/*   Updated: 2018/06/07 19:19:27 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		del_moves(t_env *env)
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

static void	assign_env(t_env *env, t_move *mv, t_move *prev, t_move *next)
{
	(void)next;
	if (mv == env->this_move && mv == env->first_move)
	{
		env->this_move = NULL;
		env->first_move = NULL;
	}
	else if (mv == env->this_move)
	{
		env->this_move = prev ? prev : NULL;
		env->this_move ? env->this_move->next = NULL : 0;
	}
}

static void	assign_link(t_env *env, t_move *mv, t_move *prev, t_move *next)
{
	(void)mv;
	if (env->this_move && prev && next)
	{
		prev->next = next;
		next->prev = prev;
	}
	else if (prev && env->this_move != env->first_move)
		prev->next = NULL;
	else if (next && env->this_move != env->first_move)
		next->prev = NULL;
}

void		del_move(t_env *env, t_move *mv)
{
	t_move	*prev;
	t_move	*next;

	if (mv && env->first_move)
	{
		prev = mv->prev;
		next = mv->next;
		assign_env(env, mv, prev, next);
		assign_link(env, mv, prev, next);
		free(mv);
	}
}
