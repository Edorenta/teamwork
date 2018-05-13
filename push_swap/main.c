/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyildiz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 18:26:08 by jyildiz-          #+#    #+#             */
/*   Updated: 2018/05/13 19:37:31 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			put_error(t_env *env, const char *err_msg)
{
	free_piles(env);
	pstr(err_msg);
	exit(1);
}

inline void		init_env(t_env *env)
{
	env->size = ac;
	env->a = NULL;
	env->b = NULL;
	env->a1 = 0;
	env->b1 = 0;
}

inline void		deinit_env(t_env *env)
{
	free_piles();
}

int				main(int ac, char **av)
{
	t_env env;

	init_env(&env, ac);
	if (ac < 2 || !av[1] || !arg_to_piles(ac, av, &env))
		put_error(env, Error);
	sort_pile(&env);
	deinit_env(&env);
	return (1);
}
