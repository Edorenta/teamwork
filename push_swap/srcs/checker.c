/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 19:17:24 by pde-rent          #+#    #+#             */
/*   Updated: 2018/06/12 16:51:54 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	make_magic_happen(t_env *env)
{
	SET_CHECKER;
	index_pile(env);
	get_moves(env);
	(IS_SET_R || IS_SET_S) ? pstr(2, "Piles rebased before sort:", '\n') : 0;
	(IS_SET_R || IS_SET_S) ? put_piles(env) : 0;
	sort_pile(env);
	IS_SET_R ? pstr(2, "Piles rebased after sort:", '\n') : 0;
	IS_SET_R ? put_piles(env) : 0;
	IS_SET_S ? pstr(2, "Piles after sort:", '\n') : 0;
	IS_SET_S ? put_unindexed_piles(env) : 0;
	optimize(env);
	IS_SET_O ? pstr(2, "# operations: ", '\0') : 0;
	IS_SET_O ? plong(2, count_moves(env->first_move), '\n') : 0;
	!IS_SET_M ? pstr(2, "Commands:", '\n') : 0;
	!IS_SET_M ? put_moves(env->first_move, 1, ' ') : 0;
	deinit_env(env);
	return (1);
}

static int	only_space(char *s)
{
	while (*s && is_space(*s))
		s++;
	return (*s == '\0');
}

int			main(int ac, char **av)
{
	t_env		env;

	signal(SIGINT, sig_handler);
	(ac < 2) ? exit(0) : 0;
	init_env(&env, ac);
	(!av[1] || (ac == 2 && only_space(av[1])))
	? put_error(&env, "Error: wrong input") : 0;
	if (ac >= 2)
	{
		if (!arg_to_piles(&env, ac, av)
			|| env.a[env.a1] == NONE || env.size == 0)
			put_error(&env, "Error: wrong input");
	}
	make_magic_happen(&env);
	return (1);
}
