/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_anthill.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyildiz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 18:04:20 by jyildiz-          #+#    #+#             */
/*   Updated: 2018/06/05 18:10:06 by jyildiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	put_anthill(t_env *env)
{
	/*
	plong(1, env->nb_ants, '\n');
	put_rooms(env);
	put_links(env);
	*/
	print_lines(env);
}

void	put_room_links(t_env *env, t_room *room)
{
	t_link *l;

	l = room->link;
	(room && &(room->id[0])) ? 0 : put_error(env, "Error: No room to target");
	l ? 0 : put_error(env, "Error: Room has no link");
	pstr(2, "linked to room ", '\0');
	pstr(2, room->id, '\0');
	pstr(2, ":\n", '\0');
	&(l->linked_room->id[0]) ? pstr(2, &(l->linked_room->id[0]), '\n') : 0;
	while ((l->next && (l = l->next)))
		&(l->linked_room->id[0]) ? pstr(2, &(l->linked_room->id[0]), '\n') : 0;
}