/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyildiz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 18:26:08 by jyildiz-          #+#    #+#             */
/*   Updated: 2018/05/29 16:51:43 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int			make_magic_happen(t_env *env)
{
	IS_SET_S ? pstr(2, "Piles before sort:", '\n') : 0;
	IS_SET_S ? put_piles(env) : 0;
	index_pile(env);
	IS_SET_R ? pstr(2, "Piles rebased before sort:", '\n') : 0;
	IS_SET_R ? put_piles(env) : 0;
	sort_pile(env);
	optimize(env);
	//pstr(2, "moves:\n", '\0');
	//put_moves(env->first_move, 1, ' ');
	IS_SET_R ? pstr(2, "Piles rebased after sort:", '\n') : 0;
	IS_SET_R ? put_piles(env) : 0;
	IS_SET_S ? pstr(2, "Piles after sort:", '\n') : 0;
	IS_SET_S ? put_unindexed_piles(env) : 0;
	(IS_SET_O && !IS_SET_T) ? pstr(2, "# operations: ", '\0') : 0;
	(IS_SET_O || IS_SET_T) ? plong((IS_SET_T ? 1 : 2),
		count_moves(env->first_move), '\n') : 0;
	!IS_SET_M ? pstr(2, "Commands:", '\n') : 0;
	!IS_SET_M ? put_moves(env->first_move, 1, ' ') : 0;
	deinit_env(env);
	return (1);
}

int					main(int ac, char **av)
{
	t_env	env;

	init_env(&env, ac);
	if (ac < 2 || !av[1] || !arg_to_piles(&env, ac, av)
		|| env.a[env.a1] == NONE || env.size == 0)
		put_error(&env, "Error: wrong input");
	if (ac == 2 || all_sort(&env))
	{
		deinit_env(&env);
		exit(0);
	}
	make_magic_happen(&env);
	return (1);
}
