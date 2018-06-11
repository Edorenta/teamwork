#include "lem_in.h"

void		new_room(t_env *env, char *name, long x, long y)
{
	t_room			*room;
	t_parsed_room	*parsed_room;

	(room = (t_room *)malloc(sizeof(t_room))) ? 0 : put_error(env, "Error: could not allocate room");
	(parsed_room = (t_parsed_room *)malloc(sizeof(t_parsed_room))) ? 0
	: put_error(env, "Error: could not allocate parsed_room");
	(name && slen(name) < 256) ? scat(room->id, name, '\0')
	: put_error(env, "Error: wrong room name size (must be >0 and <256 chars)");
	x > 2147483647 ? put_error(env, "Error: room.x does not fit in an integer")
	: (room->x = (int)x);
	y > 2147483647 ? put_error(env, "Error: room.y does not fit in an integer")
	: (room->y = (int)y);
	room->ant = NULL;
	room->link = NULL;
	parsed_room->room = room;
	parsed_room->next = NULL;
	if (R2)
	{
		parsed_room->prev = R2;
		R2->next = parsed_room;
		R2 = R2->next;
	}
	else
	{
		parsed_room->prev = NULL;
		R1 ? put_error(env, "Error: no last room but at least one was parsed") : 0;
		R2 = parsed_room;
		R1 = parsed_room;
	}
}

t_room		*str_to_room(t_env *env, const char *s)
{
	t_parsed_room *parsed;

	parsed = R1;
	(parsed && parsed->room) ? 0 : put_error(env, "Error: no room to link to");
	s ? 0 : put_error(env, "Error: no room name to link to");
	if (!scmp(parsed->room->id, s))
		return (parsed->room);
	while (parsed->next && parsed->next->room && (parsed = parsed->next))
		if (!scmp(parsed->room->id, s))
			return (parsed->room);
	put_error(env, "Error: name could not relate to any room.name");
	return (NULL);
}

void		put_room(t_env *env, t_room *r)
{
	&(r->id[0]) ? pstr(1, r->id, ' ') : put_error(env, "Error: no room name to print");
	r->x > 0 ? plong(1, r->x, ' ') : put_error(env, "Error: no room x to print");
	r->y > 0 ? plong(1, r->y, '\n') : put_error(env, "Error: no room y to print");
}

void		put_rooms(t_env *env)
{
	t_parsed_room *parsed;

	parsed = R1;
	if (parsed && parsed->room)
	{
		put_room(env, parsed->room);
		while(parsed->next && (parsed = parsed->next))
			put_room(env, parsed->room);
	}
}
