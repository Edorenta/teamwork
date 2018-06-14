#include "lem_in.h"

static int	g_ant_id = 0;

t_ant	*new_ant(t_env *env, t_path *path)
{
	t_ant		*a;

	(a = (t_ant *)malloc(sizeof(t_ant))) ? 0 : put_error(env, "t_ant malloc failed");
	a->n = ++g_ant_id;
	a->path = path;
	return (a);
}

void	del_ant(t_ant *ant)
{
	(ant && ant->path && ant->path->room && ant->path->room->ant) ? (ant->path->room->ant = NULL) : 0;
	ant ? free(ant) : 0;
	--g_ant_id;
}

void	ant_add_path(t_env *env, t_ant *ant, t_room *room)
{
	(ant && ant->path && ant->path->room && ant->path->room->ant) ? (ant->path->room->ant = NULL) : put_error(env, "Error: faulty ant->path");
	(room) ? add_path(env, ant->path, room) : put_error(env, "Error: missing room to move ant to");
	(ant->path->room->ant) = ant;
}

void	put_ant(t_ant *ant)
{
	pstr(1, "L", '\0');
	plong(1, ant->n, '\0');
	pstr(1, "-", '\0');
	pstr(1, &(ant->path->room->id[0]), '\0');
}

void	move_ant_forward(t_env *env, t_ant *ant)
{
	ant ? 0 : put_error(env, "Error: tried to move non-existing ant");
	ant->path ? 0 : put_error(env, "Error: ant has no path to follow");
	ant->path->len > 0 ? 0 : put_error(env, "Error: ant path length <= 0");
	ant->path->next ? 0 : put_error(env, "Error: could not locate ant");	
	ant->path->next ? 0 : put_error(env, "Error: ant has reached end of its path");
	if (ant->path->next->room->ant == NULL)
	{
		ant->path->room->ant = NULL;
		ant->path->room = ant->path->next->room;
		ant->path->room->ant = ant;
		put_ant(ant);
	}
}
