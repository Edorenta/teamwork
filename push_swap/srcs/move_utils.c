/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 19:19:08 by pde-rent          #+#    #+#             */
/*   Updated: 2018/06/07 19:19:12 by pde-rent         ###   ########.fr       */
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

t_move	*move_dup(t_move *src, t_move *prev)
{
	t_move	*mv;

	if (!(mv = (t_move *)malloc(sizeof(t_move))))
		return (NULL);
	scat(mv->id, src->id, '\0');
	mv->prev = prev;
	mv->next = NULL;
	return (mv);
}

void	insert_move(t_move *mv, t_move *to, int where)
{
	t_move *prev;
	t_move *next;

	if (mv && to)
	{
		prev = to->prev;
		next = to->next;
		if (where == 1)
		{
			to->next = mv;
			mv->next = next;
			mv->prev = to;
		}
		else if (where == -1)
		{
			to->prev = mv;
			mv->prev = prev;
			mv->next = to;
		}
	}
}

int		count_moves(t_move *start)
{
	int		i;
	t_move	*mv;

	mv = start;
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
		while (!IS_CHECKER && 1)
			if ((read(0, &c, 1) > 0) && (c == 13 || c == 10))
				break ;
	}
	return (1);
}
