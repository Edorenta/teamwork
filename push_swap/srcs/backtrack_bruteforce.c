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

static void		mv_lst(t_env *env, char which,
	long *pile, int max_depth, int nb_mv)
{
	static int	first = 0;
	static int	mv = 3;
	static int	i = 0;
	t_move		*cache;

	cache = NULL;
	//if (!is_sort(pile, 0, env->size - 1))
	if (max_depth > 0)
	{
		//dprintf(2, "which: %c max_depth: %d nb_mv: %d\n", which, max_depth, nb_mv);
		if (nb_mv == 0)
		{
			//dprintf(2, "which: %c max_depth: %d\n", which, max_depth);
			i = 0 - first;
			mv = ((mv + 1) > 3 ? (mv - 2) : (mv + 1));
			(!(mv % 3) ? --max_depth : 0);
			while (++i <= max_depth){
				//dprintf(2, "i: %d max_depth: %d\n", i, max_depth);
				undo_move(env, env->this_move);
				//put_moves(env->first_move, 1, ' ');
			}
			//dprintf(2, "mv: %d\n", mv);
			//if (mv == 2 && !(env->this_move->id[1] == 'r'))
			if (mv == 2)
				rotate(env, which);
			//else if (mv == 3 && !(env->this_move->id[0] == 'r'
			//	&& env->this_move->id[1] == which))
			else if (mv == 3)
				reverse_rotate(env, which);
			else
				swap(env, which);
			nb_mv = max_depth - 1;
			//first = 1;

		}
		else if (max_depth > 0)
		{
			swap(env, which);
			is_sort(pile, 0, env->size - 1) ? cache_moves(env, cache) : 0;
			undo_move(env, env->this_move);
//			if (!(env->this_move && env->this_move->id[1] == 'r'))
//			{
			rotate(env, which);
			is_sort(pile, 0, env->size - 1) ? cache_moves(env, cache) : 0;
			undo_move(env, env->this_move);
//			}
//			if (!(env->this_move && env->this_move->id[0] == 'r' && env->this_move->id[1] == which))
			reverse_rotate(env, which);
			is_sort(pile, 0, env->size - 1) ? cache_moves(env, cache) : 0;
			--nb_mv;
			//undo_move(env, env->this_move);
		}
		mv_lst(env, which, pile, max_depth, nb_mv);
	}
	get_cache(env, cache);
}

void			bruteforce(t_env *env, char which)
{
	int		max_mv;
	long	*pile;

	pile = env->a;
	(which == 'a') ? pile = env->a : 0;
	max_mv = ((which == 'a' ? LEN_A : LEN_B) * 3);
	mv_lst(env, which, pile, max_mv, max_mv);
}