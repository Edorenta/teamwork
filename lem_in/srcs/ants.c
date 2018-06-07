#include "lem_in.h"

void		put_ant(t_ant *ant)
{
	pstr(1, "L", '\0');
	plong(1, ant->n, '\0');
	pstr(1, "-", '\0');
	pstr(1, &(ant->path->current->id[0]), '\0');
}

void		move_ant_forward(t_env *env, t_ant *ant)
{
	ant ? 0 : put_error(env, "Error: tried to move non-existing ant");
	ant->path ? 0 : put_error(env, "Error: ant has no path to follow");
	ant->path->len > 0 ? 0 : put_error(env, "Error: ant path length <= 0");
	ant->path->next ? 0 : put_error(env, "Error: could not locate ant");	
	ant->path->next ? 0 : put_error(env, "Error: ant has reached end of its path");
	if (ant->path->next->ant == NULL)
	{
		ant->path->current->ant = NULL;
		ant->path->current = ant->path->next;
		ant->path->current->ant = ant;
		put_ant(ant);
	}
}

