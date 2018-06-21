/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   genetic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 18:25:39 by pde-rent          #+#    #+#             */
/*   Updated: 2018/06/20 18:25:40 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		free_gen(t_path **gen, int gen_size, int ret)
{
	while (--gen_size >= 0)
		gen[gen_size] ? del_path(gen[gen_size]) : 0;
	gen ? free(gen) : 0;
	return (ret);
}

static int		generate(t_env *env, t_path *parent, t_path **p, t_link *l)
{
	*p = add_path(env, duplicate_path(env, parent), l->room);
	if ((*p)->room == env->end)
	{
		if (path_len(env->fw) == -1 ||
			(path_len(*p) < path_len(env->fw)))
		{
			del_path(env->fw);
			env->fw = duplicate_path(env, *p);
		}
		return (1);
	}
	return (0);
}

static int		next_gen(t_env *env, t_path *parent, int gen_size, int i)
{
	t_path	**p;
	t_link	*l;

	if (!(parent && parent->room && parent->room->link))
		put_error(env, "Error: cannot make new gen from this parent");
	(p = (t_path **)malloc(sizeof(t_path *) * gen_size))
	? 0 : put_error(env, "Error: t_path ** malloc failed");
	l = parent->room->link;
	while (l && l->prev && l->prev->room)
		l = l->prev;
	while (++i < gen_size && l && l->room)
	{
		if ((in_path(parent, l->room) == 1))
		{
			p[i] = NULL;
			l = l->next;
			continue;
		}
		if ((generate(env, parent, &p[i], l) || (path_len(env->fw) > 0
			&& path_len(p[i]) >= path_len(env->fw))))
			return (env->fw ? free_gen(p, i + 1, 1) : free_gen(p, i + 1, 0));
		next_gen(env, p[i], count_rooms(p[i]->room), -1);
		l = l->next;
	}
	return (env->fw ? free_gen(p, gen_size, 1) : free_gen(p, gen_size, 0));
}

void			genetic_solve(t_env *env)
{
	t_path *init;

	init = new_path(env);
	(init && init->room && init->room->link && init->room->link)
	? 0 : put_error(env, "Error: faulty path init");
	if (!next_gen(env, init, count_rooms(init->room), -1))
		put_error(env, "Error: no way out");
	del_path(init);
}
