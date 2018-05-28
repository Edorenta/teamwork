/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyildiz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 18:26:08 by jyildiz-          #+#    #+#             */
/*   Updated: 2018/05/23 11:02:07 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int			put_unindexed_piles(t_env *env)
{
	int		i;

	i = env->a1 - 1;
	dprintf(2, "env_size: %d env[i]: %d\n", env->size, (int)env->a[i]);
	while (++i < env->size)
	{
		dprintf(2, "a1: %d env->a[1]: %ld\n", env->a1, env->c[(int)env->a[i]]);
		env->a[i] = env->c[(int)env->a[i]];
		pstr(2, "OK", '\n');
	}
	put_piles(env);
	return (1);
}

static int			make_magic_happen(t_env *env)
{
	IS_SET_S ? pstr(2, "Piles before sort:", '\n') : 0;
	IS_SET_S ? put_piles(env) : 0;
	index_pile(env);
	IS_SET_R ? pstr(2, "Piles rebased before sort:", '\n') : 0;
	IS_SET_R ? put_piles(env) : 0;
	sort_pile(env);
	IS_SET_R ? pstr(2, "Piles rebased after sort:", '\n') : 0;
	IS_SET_R ? put_piles(env) : 0;
	IS_SET_S ? pstr(2, "Piles after sort:", '\n') : 0;
	IS_SET_S ? put_unindexed_piles(env) : 0;
	optimize(env);
	IS_SET_O ? pstr(2, "# operations: ", '\0') : 0;
	IS_SET_O ? plong(2, count_moves(env), '\n') : 0;
	pstr(2, "Commands:", '\n');
	put_moves(env->first_move, 1, ' ');
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
