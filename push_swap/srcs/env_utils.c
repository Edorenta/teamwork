/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 19:17:40 by pde-rent          #+#    #+#             */
/*   Updated: 2018/06/07 19:18:19 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		put_error(t_env *env, const char *err_msg)
{
	pstr(2, err_msg, '\n');
	soft_exit(env);
}

void		init_env(t_env *env, int ac)
{
	env->option = (char)0;
	env->size = ac - 1;
	env->first_move = NULL;
	env->this_move = NULL;
	env->a = NULL;
	env->b = NULL;
	env->c = NULL;
	env->a1 = 0;
	env->b1 = env->size - 1;
	env->min = 0;
	env->mean = 0;
}

void		deinit_env(t_env *env)
{
	free_piles(env);
}

void		soft_exit(t_env *env)
{
	deinit_env(env);
	exit(0);
}
