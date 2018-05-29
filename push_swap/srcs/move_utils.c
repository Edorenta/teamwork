/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyildiz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 20:01:50 by jyildiz-          #+#    #+#             */
/*   Updated: 2018/05/23 17:13:09 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_move	*new_move(const char *id, char which, t_move *prev)
{
	t_move	*mv;

	if (!(mv = (t_move *)malloc(sizeof(t_move))))
		return (NULL);
	scat(mv->id, id, which);
	if (prev)
	{
		prev->next = mv;
		mv->prev = prev;
	}
	mv->next = NULL;
	return (mv);
}

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
	//put_moves(env->first_move, 1, ' ');
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

int		count_moves(t_env *env)
{
	int		i;
	t_move	*mv;

	mv = env->first_move;
	i = mv ? 0 : -1;
	while (++i && mv->next)
		mv = mv->next;
	return (i);
}

int		archive_move(t_env *env, const char *id, char which, t_move *prev)
{
	char c;

	if ((env->this_move = new_move(id, which, prev)))
		env->first_move = (env->first_move ? env->first_move : env->this_move);
	else
		put_error(env, "Error: this.move is not historized");
	if (IS_SET_V)
	{
		put_move(env->this_move, '\n');
		put_piles(env);
		while(1)
			if ((read(0, &c, 1) > 0) && (c == 13 || c == 10))
				break ;
	}
	return (1);
}
