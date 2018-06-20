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
	//put_rooms(env);
	//put_links(env);
	genetic_solve(env);
	put_lines(env);
	move_colony(env);
	deinit_env(env);
	//sleep(50);
	exit(EXIT_SUCCESS);
	//put_paths(env);
}
/*
static int		get_option(t_env *env, char *av)
{
	int i;

	i = 0;
	while (av[++i])
	{
		if ((av[i] != 'v' && av[i] != 's' && av[i] != 'o'
			&& av[i] != 'r' && av[i] != 'm' && av[i] != 't'))
			put_error(env, "Error: invalid option");
		else if ((av[i] == 'v' && IS_SET_V) || (av[i] == 's' && IS_SET_S)
			|| (av[i] == 'o' && IS_SET_O) || (av[i] == 'r' && IS_SET_R)
			|| (av[i] == 'm' && IS_SET_M) || (av[i] == 't' && IS_SET_T))
			put_error(env, "Error: duplicate option");
		(av[i] == 'v') ? SET_V : 0;
		(av[i] == 'o') ? SET_O : 0;
		(av[i] == 's') ? SET_S : 0;
		(av[i] == 'r') ? SET_R : 0;
		(av[i] == 'm') ? SET_M : 0;
		(av[i] == 't') ? SET_T : 0;
	}
	return (active_bits(env->option));
}

static void		get_options(t_env *env, int ac, char **av)
{
	int i;

	i = 0;
	if (ac > 2)
		while (++i <= ac)
			if ((!av[i] || av[i][0] != '-'))
}
*/
int				main(void)
{
	t_env	env;

	//env = malloc(sizeof(env));
	//exit(0);
	signal(SIGINT, sig_handler);
	init_env(&env);
	//get_options(&env, ac, av);
	get_lines(&env);
	make_magic_happen(&env);
	return (1);
}
