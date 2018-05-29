/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyildiz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 20:01:50 by jyildiz-          #+#    #+#             */
/*   Updated: 2018/05/29 17:18:25 by fmadura          ###   ########.fr       */
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
		while (1)
			if ((read(0, &c, 1) > 0) && (c == 13 || c == 10))
				break ;
	}
	return (1);
}
