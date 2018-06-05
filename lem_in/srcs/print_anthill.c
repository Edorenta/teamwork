#include "lem_in.h"

void	print_all(t_env *env)
{
	plong(1, env->nb_ants, '\n');
	print_rooms(env);
	print_links(env);
}

void	print_room(t_env *env)
{
	t_room *r;

	r = env->parsed_room;
	if (r)
	{
		//print first room
		...
		//print others
		while(r->next)
		{
			r = r->next;
			...
		}
	}
}

void	print_links(t_env *env)
{
	t_link *l;

	l = env->parsed_link;
	if (l)
	{
		//print first link
		...
		//print others
		while(l->next)
		{
			l = l->next;
			...
		}
	}
}