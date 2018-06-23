/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 18:24:28 by pde-rent          #+#    #+#             */
/*   Updated: 2018/06/20 18:24:29 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	g_ant_id = 0;

t_ant	*new_ant(t_env *env, t_path *path)
{
	t_ant		*a;

	(a = (t_ant *)malloc(sizeof(t_ant)))
	? 0 : put_error(env, "t_ant malloc failed");
	a->n = ++g_ant_id;
	a->path = path ? duplicate_path(env, path) : NULL;
	while (a->path && a->path->prev && a->path->prev->room)
		a->path = a->path->prev;
	return (a);
}

void	put_ants(t_env *env)
{
	int i;

	(env->colony && env->nb_ants > 0) ? 0 : put_error(env, "Error: no colony");
	i = -1;
	pstr(1, "Colony size:", ' ');
	plong(1, env->nb_ants, '\n');
	if (IS_SET_V)
	{
		pstr(1, "Ants' paths:", '\n');
		while (++i < env->nb_ants)
		{
			pstr(1, "#", '\0');
			plong(1, i, ' ');
			put_path(env->colony[i]->path);
		}
	}
}

void	del_ant(t_ant *ant)
{
	(ant && ant->path && ant->path->room && ant->path->room->ant)
	? (ant->path->room->ant = NULL) : 0;
	del_path(ant->path);
	ant ? free(ant) : 0;
	--g_ant_id;
}

void	ant_add_path(t_env *env, t_ant *ant, t_room *room)
{
	(ant && ant->path && ant->path->room && ant->path->room->ant)
	? (ant->path->room->ant = NULL) : put_error(env, "Error: faulty ant->path");
	(room) ? add_path(env, ant->path, room)
	: put_error(env, "Error: missing room to move ant to");
	(ant->path->room->ant) = ant;
}
