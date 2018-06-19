#include "lem_in.h"
char dbg = (char)('A' - 1);

/*
static int		free_gen(t_path **gen, int gen_size)
{
	while (--gen_size >= 0)
		gen[gen_size] ? del_path(gen[gen_size]) : 0;
	gen ? free(gen) : 0;
	return (1);
}
*/
static int		next_gen(t_env *env, t_path *parent, int gen_size)
{
	t_path	**p;
//	t_path	*found;
	t_link	*l;
	int		i;

	if (!(parent && parent->room && parent->room->link))
		put_error(env, "Error: cannot make new gen from this parent");
	p = (t_path **)malloc(sizeof(t_path *) * gen_size);
	l = parent->room->link;
	while (l && l->prev && l->prev->room)
		l = l->prev;
	i = -1;
	//dprintf(2, "gensize: %d\n", gen_size);
	//put_room_links(env, l->room);
	while (++i < gen_size && l && l->room){
		if (in_path(parent, l->room) == 1){
			//dprintf(2, "already in: %s\n", l->room->id);
			l = l->next;
			continue;
		}
		p[i] = add_path(env, duplicate_path(env, parent), l->room);
																				put_path(p[i]);
		if (p[i]->room == env->end)
		{
			if (path_len(env->fastway) == -1 || path_len(p[i]) < path_len(env->fastway))
			{
				del_path(env->fastway);
				env->fastway = duplicate_path(env, p[i]);
			}
			return (1/*free_gen(p, gen_size)*/);
		}
		next_gen(env, p[i], count_rooms(p[i]->room));
		l = l->next;
	}
	//free_gen(p, gen_size);
	return (env->fastway ? 1 : 0);
}

void			genetic_solve(t_env *env)
{
	t_path *init;

	init = new_path(env);
	(init && init->room && init->room->link && init->room->link)
	? 0 : put_error(env, "Error: faulty path init");
	if (!next_gen(env, init, count_rooms(init->room)))
		put_error(env, "Error: no way out");
	//dprintf(2, "fastway:\n");
	//put_path(env->fastway);
}
