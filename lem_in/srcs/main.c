/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 18:25:46 by pde-rent          #+#    #+#             */
/*   Updated: 2018/06/20 18:25:47 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		make_magic_happen(t_env *env)
{
	anthill_complete(env);
	genetic_solve(env);
	put_lines(env);
	move_colony(env);
	deinit_env(env);
	exit(EXIT_SUCCESS);
}

int				main(int ac, char **av)
{
	t_env	env;

	signal(SIGINT, sig_handler);
	init_env(&env);
	(ac > 1 || av[1]) ? put_error(&env, "lem-in works without arguments") : 0;
	get_lines(&env);
	make_magic_happen(&env);
	return (1);
}
