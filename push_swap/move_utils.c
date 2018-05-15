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

t_move	*new_move(const char *id, t_move *prev)
{
	t_move *mv;

	if (!(mv = (t_move *)malloc(sizeof(t_move))))
		return (NULL);
	mv->prev = prev;
	mv->next = NULL;
	scpy(mv->id, id);
	return (mv);
}

void	del_move(t_move *mv)
{
	mv ? free(mv) : 0;
}

void	put_move(t_move *mv)
{
	(mv && mv->id) ? pstr(mv->id);
}