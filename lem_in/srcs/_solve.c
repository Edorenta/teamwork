#include "lem_in.h"

int		alrdy_use(t_parsed_room *path, t_room *next)
{
	while (path->prev)
	{
		if (path->room == next)
			return (1);
		path = path->prev;
	}
	return (0);
}

void	solve(t_env *env, t_parsed_room *path, t_link *link)
{
	t_parsed_room *tmp;

	tpm = path;
	if (tmp->room = env->end)
		return (tmp);
	while (tmp)
	{
		if (alrdy_use(tmp, link->linked_room))
		{
			if (link->next)
				link = link->next;
			else
			{
				link = tmp->room->link;
				tmp = tmp->prev;
				while (link != tmp->room->link->linked_room->link)
					tmp->room->link = tmp->room->link->next;
				solve(env, tmp,);
				
		else
		{
			tmp->next = tmp->room->linked_room;
			tmp = tmp->next;
			solve(env, tmp);
		}




	put_room_links(env, env->start);
	put_room_links(env, env->end);
}
