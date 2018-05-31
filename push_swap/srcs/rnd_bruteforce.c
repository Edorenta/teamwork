/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bt_bruteforce.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 09:13:50 by fmadura           #+#    #+#             */
/*   Updated: 2018/05/29 14:08:26 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		ipow(int a, int power)
{
	int ret;

	ret = 1;
	while (power > 0)
	{
		if (power & 1)
			ret *= a;
		a *= a;
		power >>= 1;
	}
	return (ret);
}

static int		mv_lst(t_env *env, char which, long *pile, int max_depth)
{
	long	tmp_pile[env->size];
	int		rnd_mv;
	int		prev_mv;
	int		moved;
	int		nb_mv;
	int		shuffle;

	srand(time(NULL));
	duplicate_pile(env->a, tmp_pile, env->a1, env->size - 1);
	nb_mv = 0;
	while (++nb_mv <= max_depth)
	{
		shuffle = 0;
		while (++shuffle <= ipow(3, nb_mv))
		{
			prev_mv = 0;
			moved = 0;
			while(moved < nb_mv)
			{
				rnd_mv = (1 + (rand() / (RAND_MAX / 3)));
				(rnd_mv == 1 && prev_mv != 1 && ++moved) ? swap(env, which) : 0;
				(rnd_mv == 2 && prev_mv != 3 && ++moved) ? rotate(env, which) : 0;
				(rnd_mv == 3 && prev_mv != 2 && ++moved) ? reverse_rotate(env, which) : 0;
				prev_mv = rnd_mv;
			}
			//put_moves(env->first_move, 1, ' ');
			if (is_sort(pile, 0, env->size - 1)){
				//dprintf(2, "\r>> SUCCESS!! <<\n");	
				return (1);
			}
			//dprintf(2, "\rfail #%d!", shuffle);
			del_moves(env);
			duplicate_pile(tmp_pile, env->a, env->a1, env->size - 1);
		}
	}
	return (0);
}

void			bruteforce(t_env *env, char which)
{
	int		max_mv;
	long	*pile;

	pile = env->a;
	(which == 'a') ? pile = env->a : 0;
	max_mv = ((which == 'a' ? LEN_A : LEN_B) * 3);
	mv_lst(env, which, pile, max_mv);
}