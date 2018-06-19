/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anthill_builder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyildiz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 16:49:05 by jyildiz-          #+#    #+#             */
/*   Updated: 2018/06/05 17:43:17 by jyildiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		assign_colony(t_env *env)
{
	int		i;

	i = -1;
	(env->colony = (t_ant **)malloc(sizeof(t_ant *) * env->nb_ants))
	? 0 : put_error(env, "Error: t_ant ** malloc failed");
	while (++i < env->nb_ants)
		env->colony[i] = new_ant(env, env->fastway);
}

void			put_ant(t_env *env, t_ant *ant)
{
	ant ? 0 : dprintf(2, "Error: tried to print non-existing ant");
	ant->path ? 0 : dprintf(2, "Error: ant has no path to follow");
	ant->path->room ? 0 : dprintf(2, "Error: no path->room on ant");
	if (ant && ant->path && ant->path->room)
	{
		((ant->path->room != env->end) && (ant != env->colony[0])) ? write(1, " ", 1) : 0;
		write(1, "L", 1);
		plong(1, ant->n, '\0');
		write(1, "-", 1);
		&(ant->path->room->id[0]) ? pstr(1, &(ant->path->room->id[0]), '\0') : 0;
	}
}

int				move_ant_forward(t_env *env, t_ant *ant)
{
	ant ? 0 : put_error(env, "Error: tried to move non-existing ant");
	ant->path ? 0 : put_error(env, "Error: ant has no path to follow");
	path_len(ant->path) > 0 ? 0 : put_error(env, "Error: ant path length <= 0");
	ant->path->room ? 0 : put_error(env, "Error: could not locate ant");	
	//ant->path->next ? 0 : put_error(env, "Error: ant has reached end of its path");
	//ant->path->next->room ? 0 : put_error(env, "Error: no room in path->next");
	//(ant->path->next->room->ant != NULL) ? 0 : put_error(env, "Error: ant inside path->next->room");
	//dprintf(2, "ant: %d next room: %s\n", ant->n, ant->path->next->room->id);
	if (ant->path->next && ant->path->next->room
		&& ant->path->next->room->ant == NULL)
	{
		ant->path->room->ant = NULL;
		ant->path = (ant->path->room == env->end) ? ant->path : ant->path->next;
		ant->path->room->ant = (ant->path->room == env->end) ? NULL : ant;
		put_ant(env, ant);
		return (1);
	}
	return (0);
}

void			move_colony(t_env *env)
{
	//last ant will arrive in (nb_ants + len_path(env->fastway)
	int		i;
	int		j;
	int		rounds;

	//dprintf(2, "ok\n");
	i = -1;
	assign_colony(env);
	rounds = (env->nb_ants + path_len(env->fastway));
	//dprintf(2,"nb ants: %d, fastway len: %d\n", env->nb_ants, path_len(env->fastway));
	write(1, "\n", 1);
	while (++i < rounds)
	{
		j = -1;
		while (++j < env->nb_ants)
			move_ant_forward(env, env->colony[j]);
		(i < (rounds - 1)) ? write(1, "\n", 1) : 0;
	}
}
