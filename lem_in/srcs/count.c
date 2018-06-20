#include "lem_in.h"

int		in_path(t_path *path, t_room *r)
{
	t_path *p;

	p = path;
	if (r && p && p->room)
	{
		while (p && p->prev)
			p = p->prev;
		while (p)
		{
			if (p->room == r)
				return (1);
			else
				p = p->next;
		}
		return (0);
	}
	return (-1);
}

int		path_len(t_path *path)
{
	t_path	*p;
	int		len;

	len = 1;
	p = path;
	if (p && p->room && &(p->room->id[0]))
	{
		while (p && p->prev && p->prev->room)
			p = p->prev;
		while (p->next && p->next->room)
		{
			p = p->next;
			++len;
		}
		return (len);
	}
	return (-1);
}

int		count_rooms(t_room *r)
{
	t_link	*l;
	int		cnt;

	cnt = 1;
	if (!(r && r->link && r->link->room))
		return (0);
	l = r->link;
	while (l && l->prev && l->prev->room)
		l = l->prev;
	while (l->next && l->next->room)
	{
		l = l->next;
		++cnt;
	}
	return (cnt);
}
