#include "lem_in.h"
char dbg = (char)('A' - 1);

static int		free_gen(t_path **gen, int gen_size)
{
	while (--gen_size >= 0)
		gen[gen_size] ? del_path(gen[gen_size]) : 0;
	gen ? free(gen) : 0;
	return (1);
}

static int		next_gen(t_env *env, t_path *parent, int gen_size)
{
	t_path	**p;
//	t_path	*found;
	t_link	*l;
	int		i;

																				//dprintf(2, "%c\n", (char)(++dbg));
	if (!(parent && parent->room && parent->room->link))
		put_error(env, "Error: cannot make new gen from this parent");
																				//dprintf(2, "%c\n", (char)(++dbg));
	p = (t_path **)malloc(sizeof(t_path *) * gen_size);
	l = parent->room->link;
	i = -1;
	while (++i < gen_size && l && l->room){
		if (in_path(parent, l->room) == 1){
			//dprintf(2, "room: %s\n", l->room->id);
			l = l->next;
			continue;
		}
		p[i] = add_path(env, duplicate_path(env, parent), l->room);
																				//put_path(p[i]);
		if (p[i]->room == env->end)
		{
			if (path_len(env->fastway) == -1 || path_len(p[i]) < path_len(env->fastway))
			{
																				//dprintf(2, "%c\n", (char)(++dbg));
				del_path(env->fastway);
																				//dprintf(2, "%c\n", (char)(++dbg));
				env->fastway = duplicate_path(env, p[i]);
																				//dprintf(2, "%c\n", (char)(++dbg));
			}
			return (free_gen(p, gen_size));
		}
		next_gen(env, p[i], count_rooms(p[i]->room));
		l = l->next;
																				//dprintf(2, "%c\n", (char)(++dbg));
	}
	//free_gen(p, gen_size);
/*																				//dbg = (char)('A' - 1);
	l = parent->room->link;
	i = -1;
	while (l && l->room && (++i < gen_size))
	{
																				//dprintf(2, "%c\n", (char)(++dbg));
		if (parent->prev && parent->prev->room && (l->room == parent->prev->room) && (l = l->next))
			continue ;
																				//dprintf(2, "%c\n", (char)(++dbg));
		p[i] = add_path(env, p[i], l->room);
																				//dprintf(2, "%c\n", (char)(++dbg));
																				put_path(p[i]);
		if (p[i]->room == env->end && (found = duplicate_path(env, p[i]))
			&& (free_gen(p, gen_size)))
			return (found);
																				//dprintf(2, "%c\n", (char)(++dbg));
		if ((found = next_gen(env, p[i], count_rooms(p[i]->room)))
			&& (free_gen(p, gen_size)))
			return (found);
																				//dprintf(2, "%c\n", (char)(++dbg));
		//if (!l->next)
		//	break ;
																				//dprintf(2, "%c\n", (char)(++dbg));
		l = l->next;
	}
*/
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
	dprintf(2, "fastway:\n");
	put_path(env->fastway);
}
