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

static int		mv_lst(t_env *env, char which, int mv)
{
	if (mv == 1)
		swap(env, which);
	else if (mv == 2 && !(env->this_move->id[1] == 'r'))
		rotate(env, which);
	else if (mv == 3
		&& !(env->this_move->id[0] == 'r' && env->this_move->id[1] == which))
		reverse_rotate(env, which);
	else
		return (0);
	return (1);
}

void			bruteforce(t_env *env, char which)
{
	int		i;
	int		j;
	int		k;
	int		nb_mv;
	int		max_mv;
	int		start;
	long	**pile;
	long	tmp_pile[env->size];

	*pile = (which == 'a' ? env->a : env->b);
	start = (which = 'a' ? env->a1 : env->b1);
	max_mv = ((which = 'a' ? LEN_A : LEN_B) * 3);
	duplicate_pile(*pile, tmp_pile, start, env->size - 1);
	nb_mv = 0;
	while (++nb_mv <= max_mv)
	{
		i = 0;
		while (++i <= nb_mv)
		{
			j = 0;
			while (++j <= 3){
				mv_lst(env, which, nb_mv);
			}
			if (is_sort(*pile, start, env->size - 1))
				return ;
			del_moves(env);
			duplicate_pile(tmp_pile, *pile, start, env->size - 1);
		}
	}
	return (best_step);
}