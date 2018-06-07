/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bt_bruteforce.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 09:13:50 by fmadura           #+#    #+#             */
/*   Updated: 2018/06/07 17:20:30 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		generate_rnd_moves(t_env *env, char which, int nb_mv)
{
	static int		prev_mv;
	int				rnd_mv;
	int				moved;

	prev_mv = 0;
	moved = 0;
	while (moved < nb_mv)
	{
		rnd_mv = (1 + (rnd() / (RAND_MAX / 3)));
		(rnd_mv == 1 && prev_mv != 1 && ++moved) ? swap(env, which) : 0;
		(rnd_mv == 2 && prev_mv != 3 && ++moved) ? rotate(env, which) : 0;
		(rnd_mv == 3 && prev_mv != 2 && ++moved) ? rev_rotate(env, which) : 0;
		prev_mv = rnd_mv;
	}
}

static int		jack(t_env *env, char which, long *pile, int max_depth)
{
	long	tmp_pile[env->size];
	int		start;
	int		nb_mv;
	int		shuffle;

	pile_init(tmp_pile, env->size);
	start = which == 'a' ? env->a1 : env->b1;
	rnd();
	duplicate_pile(pile, tmp_pile, start, env->size - 1);
	nb_mv = 0;
	while (++nb_mv <= max_depth)
	{
		shuffle = 0;
		while (++shuffle <= (ipow(3, nb_mv) * 3))
		{
			generate_rnd_moves(env, which, nb_mv);
			if ((which == 'a' && is_sort(pile, start, env->size - 1))
				|| (which == 'b' && is_rev_sort(pile, start, env->size - 1)))
				return (1);
			del_moves(env);
			duplicate_pile(tmp_pile, pile, start, env->size - 1);
		}
	}
	return (0);
}

static void		merge_afterwork(t_env *env)
{
	env->this_move = env->first_move;
	if (env->this_move)
		while (env->this_move->next)
			env->this_move = env->this_move->next;
	while (B1 != NONE)
		PA;
}

void			median_bruteforce(t_env *env, char which)
{
	int		max_mv;
	long	pivot;
	long	*pile;
	t_move	*cache[3];

	cache_init(cache, 3);
	pile = env->b;
	(which == 'a') ? pile = env->a : 0;
	max_mv = ((which == 'a' ? LEN_A : LEN_B) * 3) / 2;
	pivot = which == 'a' ? LEN_A : LEN_B;
	pivot = pivot % 2 ? env->mean : env->mean - 1;
	while (MIN_A <= pivot && !(SORT_A))
	{
		while (A1 > pivot)
			ra_or_rra(env, pivot) == 1 ? RA : RRA;
		PB;
	}
	cache[0] = cache_moves(env);
	!(SORT_A) ? jack(env, 'a', env->a, max_mv) : 0;
	cache[1] = cache_moves(env);
	!(RSORT_B) ? jack(env, 'b', env->b, max_mv) : 0;
	cache[2] = cache_moves(env);
	env->first_move = queue_caches_merge(cache, 3);
	merge_afterwork(env);
}

void			bruteforce(t_env *env, char which)
{
	int		max_mv;
	long	*pile;

	pile = env->b;
	(which == 'a') ? pile = env->a : 0;
	max_mv = ((which == 'a' ? LEN_A : LEN_B) * 3);
	max_mv > 15 ? (max_mv = 12) : 0;
	!jack(env, which, pile, max_mv) ? median_bruteforce(env, which) : 0;
}
