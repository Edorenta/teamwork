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

int				main(int ac, char **av)
{
	t_env	env;

	init_env(&env, ac);
	if (ac < 2 || !av[1] || !arg_to_piles(&env, ac, av))
		put_error(&env, "Error: wrong input");
	//init piles
	pstr(2, "Piles initialized:", '\n');
	put_piles(&env);
	//index pile
	index_pile(&env);
	//pstr(2, "Piles rebased:", '\n');
	//put_piles(&env);
	//go sort
	sort_pile(&env);
	pstr(2, "Piles sorted:", '\n');
	put_piles(&env);
	//deinit piles
	deinit_env(&env);
	//optimize commands
	//optimize(&env);
	//print commands
	pstr(2, "Commands:", '\n');
	put_moves(env.first_move, 1, ' ');
	return (1);
}
