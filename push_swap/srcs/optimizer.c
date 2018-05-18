/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyildiz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 18:26:08 by jyildiz-          #+#    #+#             */
/*   Updated: 2018/05/15 18:05:51 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int		optimize(t_env *env)
{
	if (dir == 1)
		while (1)
		{
			start->next ? put_move(start, sep) : put_move(start, '\n');
			if (start->next)
				start = start->next;
			else
				return (1);
		}
	else if (dir == 2)
		while (1)
		{
			start->prev ? put_move(start, sep) : put_move(start, '\n');
			if (start->prev)
				start = start->prev;
			else
				return (1);
		}
	return (0);
}