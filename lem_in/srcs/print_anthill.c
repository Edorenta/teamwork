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
	plong(1, env->nb_ants, '\n');
	print_rooms(env);
	print_link(env);
}

void	put_rooms(t_env *env)
{
	t_parsed_room *parsed;

	parsed = env->parsed_room;
	if (parsed && parsed->room)
	{
		put_room(parsed->room);
		while(parsed->next && (parsed = parsed->next))
		{
			parsed->room->id ? pstr(1, parsed->room->id, ' ') : put_error(env, "Error: no room name to print");
			parsed->room->x > 0 ? plong(1, parsed->room->x, ' ') : put_error(env, "Error: no room x to print");
			parsed->room->y > 0 ? plong(1, parsed->room->y, '\n') : put_error(env, "Error: no room y to print");
		}
	}
}

void	put_links(t_env *env)
{
	t_parsed_link *parsed;

	parsed = env->parsed_link;
	if (parsed->room1 && parsed->room2)
	{
		pstr(1, parsed->room1->id, '-');
		pstr(1, parsed->room2->id, '\n');
		while(parsed->next && (parsed = parsed->next))
		{
			pstr(1, parsed->room1->id, '-');
			pstr(1, parsed->room2->id, '\n');
		}
	}
}
