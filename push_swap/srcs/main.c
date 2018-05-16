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

void			put_error(t_env *env, const char *err_msg)
{
	free_piles(env);
	pstr(2, err_msg, '\n');
	exit(1);
}

inline void		init_env(t_env *env, int ac)
{
	env->size = ac;
	env->first_move = NULL;
	env->this_move = NULL;
	env->a = NULL;
	env->b = NULL;
	env->c = NULL;
	env->a1 = 0;
	env->b1 = 0;
}

inline void		deinit_env(t_env *env)
{
	free_piles(env);
}

int				main(int ac, char **av)
{
	t_env	env;

	init_env(&env, ac);
	if (ac < 2 || !av[1] || !arg_to_piles(&env, ac, av))
		put_error(&env, "Error: wrong input");
	//print init piles
	pstr(1, "Before sort:", '\n');
	for (int i = 0; i <= env.size - 1; i++)
		printf("a[%d] = %ld\n", i, env.a[i]);
	//go sort
	sort_pile(&env);
	//print sorted pile
	pstr(1, "After sort:", '\n');
	for (i = 0; i <= env.size - 1; i++)
		printf("a[%d] = %ld\n", i, env.a[i]);
	//deinit piles
	deinit_env(&env);
	//print commands
	pstr("Commands:");
	put_moves(env.first_move, 1, ' ');

	while(++i)
		;
	return (1);
}
