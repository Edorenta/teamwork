#include "lem_in.h"

t_room		*new_room(t_env *env, char *name, long x, long y)
{
	t_room *room;

	room = (t_room *)malloc(sizeof(t_room));
	scat(room->id, name, '\0');
	x > 2147483647 ? put_error(env, "Error: room.x does not fit in an integer")
	: room->x = (int)x;
	y > 2147483647 ? put_error(env, "Error: room.y does not fit in an integer")
	: room->y = (int)y;
	room->ant = NULL;
	room->links = NULL;
	env->parsed_room ? room->prev = env->parsed_room : room->prev = NULL;
	room->next = NULL;
	env->parsed_room ? env->parsed_room->next = room : env->parsed_room = room;
	return (room);
}

t_room		*str_to_room(t_env *env, const char *s);
{
	t_room *room;

	room = env->parsed_room;
	if (!room)
		put_error(env, "Error: no room to link to");
	if (!s)
		put_error(env, "Error: no room name to link to");
	if (!scmp(room->id, s))
		return (room);
	while (room->prev && (room = room->prev))
		if (!scmp(room->id, s))
			return (room);
	put_error(env, "Error: name could not relate to any room.name");
	return (NULL);
}
