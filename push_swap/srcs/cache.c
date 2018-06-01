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

t_move			*queue_caches_merge(t_move **cache, int size)
{
	t_move *merge;
	t_move *start;
	int		i;

	merge = NULL;
	start = NULL;
	i = -1;
	while (++i < size)
	{
		if (cache[i])
		{
			//pstr(2, "to merge:\n", '\0');
			//put_moves(cache[i], 1, ' ');
			//put_moves(cache[i], 1, ' ');
			!merge ? (merge = cache[i]) : 0;
			!start ? (start = merge) : 0;
			if (merge != cache[i])
			{
				merge->next = cache[i];
				merge = merge->next;
			}
			while (cache[i]->next)
			{
				cache[i] = cache[i]->next;
				merge->next = cache[i];
				merge = merge->next;
			}
		}
	}
	//pstr(2, "merged:\n", '\0');
	//put_moves(start, 1, ' ');
	return (start);
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
