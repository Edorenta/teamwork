#include "lem_in.h"

t_links		*new_link(t_room *new_linked_room, t_links *prev_link)
{
	t_links *link;

	link = (t_links *)malloc(sizeof(t_links));
	link->linked_room = new_linked_room;
	link->prev = prev_link;
	link->next = NULL;
	return (link);
}

void		link_rooms(t_env *env, t_room *room1, t_room *room2)
{
	if (!room1 || !room2)
		put_error(env, "Error: tried to link non-existing room");
	if (room1->links)
		room1->links->next = new_link(room2, room1->links->linked_room);
	else
		room1->links = new_link(room2, NULL);
	if (room2->links)
		room2->links->next = new_link(room1, room2->links->linked_room);
	else
		room2->links = new_link(room1, NULL);
}
