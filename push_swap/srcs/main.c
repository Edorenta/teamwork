/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 19:18:49 by pde-rent          #+#    #+#             */
/*   Updated: 2018/06/07 19:18:53 by pde-rent         ###   ########.fr       */
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
	IS_SET_R ? pstr(2, "Piles rebased after sort:", '\n') : 0;
	IS_SET_R ? put_piles(env) : 0;
	IS_SET_S ? pstr(2, "Piles after sort:", '\n') : 0;
	IS_SET_S ? put_unindexed_piles(env) : 0;
	(IS_SET_O && !IS_SET_T) ? pstr(2, "# operations: ", '\0') : 0;
	if (IS_SET_O || IS_SET_T)
		plong((IS_SET_T ? 1 : 2), count_moves(env->first_move), '\n');
	!IS_SET_M ? pstr(2, "Commands:", '\n') : 0;
	!IS_SET_M ? put_moves(env->first_move, 1, ' ') : 0;
	deinit_env(env);
	return (1);
}

static int			only_space(char *s)
{
	while (*s && is_space(*s))
		s++;
	return (*s == '\0');
}

int					main(int ac, char **av)
{
	t_env	env;

	(ac < 2) ? exit(0) : 0;
	init_env(&env, ac);
	(!av[1] || (ac == 2 && only_space(av[1])))
	? put_error(&env, "Error: wrong input") : 0;
	if (ac >= 2)
	{
		if (!arg_to_piles(&env, ac, av)
			|| env.a[env.a1] == NONE || env.size == 0)
			put_error(&env, "Error: wrong input");
		is_sort_precheck(env.a, 0, env.size - 1) ? soft_exit(&env) : 0;
	}
	make_magic_happen(&env);
	return (1);
}
