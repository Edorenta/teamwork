#include "lem_in.h"

int		alrdy_use(t_path *path, t_room *next)
{
	t_path	*tmp;

	tmp = path;
	if (next->ant != NULL)
		return(1);
	while (tmp->prev)
	{
		if (tmp->room == next)
			return (1);
		tmp = tmp->prev;
	}
	if (tmp->room == next)
		return (1);
	return (0);
}

void		del_ant_next(t_env *env, t_path *path)
{
	t_link	*tmp;

	tmp = path->room->link;
	while (tmp)
	{
		tmp->linked_room->ant = NULL;
		tmp = tmp->next;
	}	
}

void		solve(t_env *env, t_path *path)
{
	t_ant	*bullshit;
	t_link	*tmp;

	bullshit = new_ant(env, NULL);
	path->room->ant = bullshit;
	tmp = path->room->link;
	while (&(path->room) != &(env->end))
	{
		if (!alrdy_use(path, tmp->linked_room))
			add_path(env, path, tmp->linked_room);
		else
		{
			if (tmp->next)
				tmp = tmp->next;
			else





