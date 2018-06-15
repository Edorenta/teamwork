#include "lem_in.h"

static int		free_gen(t_path **gen, int gen_size)
{
	while (--gen_size >= 0)
		gen[gen_size] ? free(gen[gen_size]) : 0;
	return (1);
}

static t_path	*next_gen(t_env *env, t_path *parent, int gen_size)
{
	t_path	*p[gen_size];
	t_path	*found;
	t_link	*l;
	int		i;

	if (!(parent && parent->room && parent->room->link))
		put_error(env, "Error: cannot make new gen from this parent");
	i = -1;
	while (++i < gen_size)
		p[i] = duplicate_path(env, parent);
	l = parent->room->link;
	i = -1;
	while (l && l->room && (++i < gen_size))
	{
		if (l->room == parent->prev->room)
			continue ;
		p[i] = add_path(env, p[i], l->room);
		if (!l->next)
			break ;
		if (p[i]->room == env->end && (found = duplicate_path(env, p[i])) && (free_gen(p, gen_size)))
			return (found);
		if ((found = next_gen(env, p[i], count_rooms(p[i]->room))) && (free_gen(p, gen_size)))
			return (found);
		l = l->next;
	}
	return (NULL);
}

void			genetic_solve(t_env *env)
{
	t_path *init;

	init = new_path(env);
	(init && init->room && init->room->link && init->room->link)
	? 0 : put_error(env, "Error: faulty path init");
	env->fastway = next_gen(env, init, count_rooms(init->room));
}
