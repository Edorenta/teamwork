/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cache.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 19:18:05 by pde-rent          #+#    #+#             */
/*   Updated: 2018/06/07 19:18:09 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		cache_init(t_move **cache, int size)
{
	int i;

	i = -1;
	while (++i < size)
		cache[i] = NULL;
}

t_move		*queue_caches_merge(t_move **cache, int size)
{
	t_move	*merge;
	t_move	*start;
	int		i;

	merge = NULL;
	start = NULL;
	i = -1;
	while (++i < size)
		if (cache[i])
		{
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
	return (start);
}

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

t_move		*cache_moves(t_env *env)
{
	long			tmp_cnt;
	t_move			*mv;
	t_move			*src;
	t_move			*cache;

	cache = NULL;
	tmp_cnt = count_moves(env->first_move);
	if (tmp_cnt > 0)
	{
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
	}
	del_moves(env);
	return (cache);
}
