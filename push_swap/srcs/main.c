/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyildiz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 18:26:08 by jyildiz-          #+#    #+#             */
/*   Updated: 2018/05/18 09:24:03 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int			put_unindexed_piles(t_env *env)
{
	int		i;

	i = env->a1 - 1;
	while (++i < env->size)
		env->a[i] = env->c[(int)env->a[i]];
	put_piles(env);
	return (1);
}

inline static int	make_magic_happen(t_env *env)
{
	IS_SET_S ? pstr(2, "Piles before sort:", '\n') : 0;
	IS_SET_S ? put_piles(env) : 0;
	index_pile(env);
	IS_SET_R ? pstr(2, "Piles rebased before sort:", '\n') : 0;
	IS_SET_R ? put_piles(env) : 0;
	sort_pile(env);
	IS_SET_R ? pstr(2, "Piles rebased after sort:", '\n') : 0;
	IS_SET_R ? put_piles(env) : 0;
	deinit_env(env);
	IS_SET_S ? pstr(2, "Piles after sort:", '\n') : 0;
	IS_SET_S ? put_unindexed_piles(env) : 0;
	//optimize commands
	//optimize(&env);
	IS_SET_O ? pstr(2, "# operations: ", '\0') : 0;
	IS_SET_O ? plong(2, count_moves(env), '\n') : 0;
	pstr(2, "Commands:", '\n');
	put_moves(env->first_move, 1, ' ');
	return (1);
}

int					main(int ac, char **av)
{
	t_env	env;

	init_env(&env, ac);
	if (ac < 2 || !av[1] || !arg_to_piles(&env, ac, av))
		put_error(&env, "Error: wrong input");
	pstr(2, "Piles before sort:", '\n');
	//put_piles(&env);
	for (int i = 0; i < env.size; i++)
		printf("a[%d]: %ld\n", i, env.a[i]);
	make_magic_happen(&env);
	return (1);
}
