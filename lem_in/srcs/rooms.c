#include "lem_in.h"

void		new_room(t_env *env, char *name, long x, long y)
{
	t_room			*room;
	t_parsed_room	*parsed_room;

	room = (t_room *)malloc(sizeof(t_room)) ? 0 : put_error(env, "Error: could not allocate room");
	parsed_room = (t_parsed_room *)malloc(sizeof(t_parsed_room)) ? 0
	: put_error(env, "Error: could not allocate parsed_room");
	(name && slen(name) < 256) ? scat(room->id, name, '\0')
	: put_error(env, "Error: wrong room name size (must be >0 and <256 chars)");
	x > 2147483647 ? put_error(env, "Error: room.x does not fit in an integer")
	: room->x = (int)x;
	y > 2147483647 ? put_error(env, "Error: room.y does not fit in an integer")
	: room->y = (int)y;
	room->ant = NULL;
	room->link = NULL;
	parsed_room->room = room;
	if (env->parsed_room)
	{
		parsed_room->prev = env->parsed_room;
		env->parsed_room->next = parsed_room;
		env->parsed_room = env->parsed_room->next;
	}
	else
	{
		parsed_room->prev = NULL;
		env->parsed_room = parsed_room;
	}
}

t_room		*str_to_room(t_env *env, const char *s);
{
	t_room *room;

	room = env->parsed_room;
	room ? 0 : put_error(env, "Error: no room to link to");
	s ? 0 : put_error(env, "Error: no room name to link to");
	if (!scmp(room->id, s))
		return (room);
	while (room->next && (room = room->next))
		if (!scmp(room->id, s))
			return (room);
	put_error(env, "Error: name could not relate to any room.name");
	return (NULL);
}
