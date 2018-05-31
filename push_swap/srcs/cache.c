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

void		cache_moves(t_env *env, t_move *cache)
{
	static long		mv_cnt = 1000000;
	long			tmp_cnt;
	t_move			*dest;
	t_move			*src;

	//optimize(env);
	tmp_cnt = count_moves(env);
	if (tmp_cnt < mv_cnt)
	{
		dprintf(2, "cached\n");
		mv_cnt = tmp_cnt;
		src = env->first_move;
		dest = cache;
		free_cache(cache);
		if (!(dest = move_dup(src, NULL)))
			put_error(env, "Error: impossible to put moves into cache");
		while (src->next)
		{
			dest->next = move_dup(src->next, dest);
			src = src->next;
			dest = dest->next;
		}
		//put_moves(cache, 1, ' ');
	}
	else
		dprintf(2, "did not cache\n");
}

void		get_cache(t_env *env, t_move *cache)
{
	t_move *tmp;

	if (cache)
	{
		tmp = cache;
		dprintf(2, "1\n");
		del_moves(env);
		dprintf(2, "2\n");
		env->first_move = tmp;
		dprintf(2, "3\n");
		while (tmp->next){
			tmp = tmp->next;
			dprintf(2, "4\n");
		}
		dprintf(2, "5\n");
		env->this_move = tmp;
	}
	free_cache(cache);
}
