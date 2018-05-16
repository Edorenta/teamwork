/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyildiz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 20:01:50 by jyildiz-          #+#    #+#             */
/*   Updated: 2018/05/15 15:18:18 by fmadura          ###   ########.fr       */
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

void	del_move(t_move *mv)
{
	if (mv)
	{
		mv->prev->next = mv->next ? mv->next : NULL;
		mv->next->prev = mv->prev ? mv->prev : NULL;
		free(mv);
	}
}

void	put_move(t_move *mv)
{
	(mv && mv->id) ? pstr(mv->id) : 0;
}

int		archive_move(t_env *env, const char *id, char which, t_move *prev)
{
	if ((env->this_move = new_move(id, which, prev)))
		env->first_move = (env->first_move ? env->first_move : env->this_move);
	else
		put_error(env, "Error: this.move is not historized");
	return (1);
}
