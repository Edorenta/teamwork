#include "lem_in.h"

static int		alrdy_use(t_path *path, t_room *next)
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

static void		del_ant_next(t_path *path)
{
	t_link	*tmp;

	tmp = path->room->link;
	while (tmp)
	{
		tmp->linked_room->ant = NULL;
		tmp = tmp->next;
	}	
}

static void		del_one_path(t_path *path)
{
	t_path *tmp;

	tmp = path;
	path = path->prev;
	free(tmp);
	path->next = NULL;
}

void		solve(t_env *env)
{
	t_path	*path;
	t_ant	*bullshit;
	t_link	*tmp;

	path = new_path(env);
	bullshit = new_ant(env, NULL);
	path->room->ant = bullshit;
	tmp = path->room->link;
	while (path->room != env->end)
	{
		if (!alrdy_use(path, tmp->linked_room))
		{
			path = add_path(env, path, tmp->linked_room);
			printf("room id: %s\n", path->room->id);
			tmp = path->room->link;
		}
		else
		{
			if (tmp->next)
				tmp = tmp->next;
			else
			{
				del_ant_next(path);
				del_one_path(path);
				tmp = path->room->link;
			}
		}
	}
	if (&(path->room) != &(env->end))
		env->fastway = path;
	put_path(path);
}
