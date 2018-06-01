/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_bruteforce.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 09:13:50 by fmadura           #+#    #+#             */
/*   Updated: 2018/05/29 14:08:26 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		queue_caches_merge(t_env *env, t_move **cache, int size)
{
	int	i;

	del_moves(env);
	i = -1;
	while (++i < size)
	{
		if (cache[i])
		{
			//put_moves(cache[i], 1, ' ');
			env->first_move ? 0 : (env->first_move = cache[i]);
			if (env->this_move)
			{
				env->this_move->next = cache[i];
				env->this_move = env->this_move->next;
			}
			else
				env->this_move = cache[i];
			while (cache[i]->next)
			{
				cache[i] = cache[i]->next;
				env->this_move->next = cache[i];
				env->this_move = env->this_move->next;
			}
		}
	}
	optimize(env);
	//put_moves(env->first_move, 1, ' ');
}

/*
void		parallel_caches_merge(t_env *env, t_move *cache1, t_move *cache2)
{
	t_move	*best_merge;
	t_move	*c1;
	t_move	*c2;
	t_move	*rnd_mv;
	int		rnd_i;

	del_moves(env);
	srand(time(NULL));
	c1 = cache1;
	c2 = cache2;
	nb_mv = 0;
	while (1)
	{
		BLABLABLA
		DO RANDOM INSERTION BETWEEN C1 AND C2 AND COUNT MOVES AFTER OPTIMIZATION EVERY TIME
		KEEP THE BEST INSERTION TEMPLATE
	}
	return (0);
}
*/

void		free_cache(t_move *cache)
{
	t_move *mv;
	t_move *mv_next;

	if (cache)
	{
		mv = cache;
		while (mv->next && (mv_next = mv->next))
		{
			free(mv);
			mv = mv_next;
		}
		mv ? free(mv) : 0;
	}
	cache = NULL;
}

t_move *cache_moves(t_env *env)
{
	//static long		mv_cnt = 1000000;
	long			tmp_cnt;
	t_move			*mv;
	t_move			*src;
	t_move			*cache;

	//optimize(env);
	cache = NULL;
	//put_moves(env->first_move, 1, ' ');
	tmp_cnt = count_moves(env->first_move);
	//dprintf(2, "nb moves: %ld\n", tmp_cnt);
	if (tmp_cnt > 0)
	{
		//dprintf(2, "cached\n");
		//mv_cnt = tmp_cnt;
		src = env->first_move;
		if (!(cache = move_dup(src, NULL)))
			put_error(env, "Error: impossible to put moves into cache");
		mv = cache;
		while (src->next)
		{
			src = src->next;
			mv->next = move_dup(src, mv);
			mv = mv->next;
		}
		//put_moves(cache, 1, ' ');
	}
	//else
	//	dprintf(2, "did not cache\n");
	del_moves(env);
	return (cache);
}

void		get_cache(t_env *env, t_move *cache)
{
	t_move *tmp;

	if (cache)
	{
		tmp = cache;
		del_moves(env);
		env->first_move = tmp;
		while (tmp->next)
			tmp = tmp->next;
		env->this_move = tmp;
	}
	free_cache(cache);
}
