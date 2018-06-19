#include "lem_in.h"

t_path	*new_path(t_env *env)
{
	t_path *p;

	(p = (t_path *)malloc(sizeof(t_path))) ? 0 : put_error(env, "t_path malloc failed");
	p->prev = NULL;
	p->next = NULL;
	p->room = env->start;
	return (p);
}

t_path	*duplicate_path(t_env *env, t_path *path)
{
	t_path *p;
	t_path *new;

	p = path;
	new = new_path(env);
	while (p && p->prev && p->prev->room)
		p = p->prev;
	while (p && p->next && (p = p->next))
		new = add_path(env, new, p->room);
	return (new);
}

t_path	*add_path(t_env *env, t_path *path, t_room *room)
{
	t_path *p;

	(path && path->room && room) ? 0 : put_error(env, "Error: faulty add_path element");
	(p = (t_path *)malloc(sizeof(t_path))) ? 0 : put_error(env, "t_path malloc failed");
	while (path && path->next && path->next->room)
		path = path->next;
	path->next = p;
	p->prev = path;
	p->next = NULL;
	p->room = room;
	return (path->next);
}

void	del_path(t_path *path)
{
	t_path *p;

	p = path;
	while (p && p->prev && (p = p->prev))
	{
		path ? free(path) : 0;
		path = p;
	}
	p ? free(p) : 0;
}

void	put_path(t_path *path)
{
	t_path *p;

	p = path;
	while (p && p->prev)
		p = p->prev;
	while (p && p->room && &(p->room->id[0]))
	{
		&(p->room->id[0]) ? pstr(1, p->room->id, ' ') : 0;
		p = p->next;
	}
	write(1, "\n", 1);
}
