#include "lem_in.h"

void		solve(t_env *env)
{
	t_path *p;
	t_link *l;
//	t_room *r;

	p = new_path(env);
	(p && p->room && p->room->link && p->room->link)
	? 0 : put_error(env, "Error: faulty path init");
	l = p->link;
	while (l && l->room)
	{
		
		l = r->link;
		if (r && l)
		{

		}
	}
}
