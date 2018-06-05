#include "lem_in.h"

t_link		*add_link(t_room *new_linked_room, t_link *prev_link)
{
	t_link *link;

	link = (t_link *)malloc(sizeof(t_link));
	link->linked_room = new_linked_room;
	link->prev = prev_link;
	link->next = NULL;
	return (link);
}

void		new_link(t_env *env, t_room *room1, t_room *room2)
{
	t_parsed_link *to;
	t_parsed_link *parsed_link;

	if (!room1 || !room2)
		put_error(env, "Error: tried to link non-existing room");
	to = env->parsed_link;
	parsed_link = (t_parsed_link *)malloc(sizeof(t_parsed_link));
	parsed_link->room1 = room1;
	parsed_link->room2 = room2;
	parsed_link->next = NULL;
	if (to)
	{
		parsed_link->prev = to;
		to->next = parsed_link;
		to = to->next;
	}
	else
	{
		parsed_link->prev = NULL;
		env->parsed_room = parsed;
	}
	link_rooms(env, room1, room2);
}

void		link_rooms(t_env *env, t_room *room1, t_room *room2)
{
	if (room1->link)
		room1->link->next = add_link(room2, room1->link);
	else
		room1->link = add_link(room2, NULL);
	if (room2->link)
		room2->link->next = add_link(room1, room2->link);
	else
		room2->link = add_link(room1, NULL);
}
