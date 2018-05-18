/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyildiz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 18:26:08 by jyildiz-          #+#    #+#             */
/*   Updated: 2018/05/15 18:05:51 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

inline static int make_magic_happen(t_env *env)
{
	//init piles
	IS_SET_S ? pstr(2, "Piles initialized:", '\n') : 0;
	IS_SET_S ? put_piles(env) : 0;
	//index pile
	index_pile(env);
	IS_SET_R ? pstr(2, "Piles rebased:", '\n') : 0;
	IS_SET_R ? put_piles(env) : 0;
	//go sort
	sort_pile(env);
	IS_SET_S ? pstr(2, "Piles sorted:", '\n') : 0;
	IS_SET_S ? put_piles(env) : 0;
	//deinit piles
	deinit_env(env);
	//optimize commands
	//optimize(&env);
	IS_SET_O ? pstr(2, "# operations: ", '\0') : 0;
	IS_SET_O ? plong(2, count_moves(env), '\n') : 0;
	//print commands
	pstr(2, "Commands:", '\n');
	put_moves(env->first_move, 1, ' ');
	return (1);
}

int				main(int ac, char **av)
{
	t_env	env;

	init_env(&env, ac);
	if (ac < 2 || !av[1] || !arg_to_piles(&env, ac, av))
		put_error(&env, "Error: wrong input");
	make_magic_happen(&env);
	return (1);
}
