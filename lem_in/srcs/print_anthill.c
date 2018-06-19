#include "lem_in.h"

/*
void	put_anthill(t_env *env)
{
	plong(1, env->nb_ants, '\n');
	put_rooms(env);
	put_links(env);
	put_lines(env);
}
*/

void	put_room_links(t_env *env, t_room *room)
{
	t_link *l;

	l = room->link;
	(room && &(room->id[0])) ? 0 : put_error(env, "Error: No room to target");
	l ? 0 : put_error(env, "Error: Room has no link");
	while ((l && l->prev && l->prev->room))
		(l = l->prev);
	pstr(2, "linked to room ", '\0');
	pstr(2, room->id, '\0');
	pstr(2, ":\n", '\0');
	&(l->room->id[0]) ? pstr(2, &(l->room->id[0]), '\n') : 0;
	while ((l->next && (l = l->next)))
		&(l->room->id[0]) ? pstr(2, &(l->room->id[0]), '\n') : 0;
}