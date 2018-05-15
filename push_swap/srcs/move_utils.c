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

t_move	*new_move(const char *id, char which, t_move *prev)
{
	t_move *mv;

	if (!(mv = (t_move *)malloc(sizeof(t_move))))
		return (NULL);
	mv->prev = prev;
	mv->next = NULL;
	scat(mv->id, id, which);
	return (mv);
}

void	del_move(t_move *mv)
{
	mv ? free(mv) : 0;
}

void	put_move(t_move *mv)
{
	(mv && mv->id) ? pstr(mv->id) : 0;
}

int		archive_move(t_env *env, const char *id, char which, t_move *prev)
{
	if ((env->this_move = new_move(id, which, prev)))
		env->this_move = env->this_move->next;
	else
		put_error(env, "Error: this.move not historized");
}