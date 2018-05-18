/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyildiz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 18:26:08 by jyildiz-          #+#    #+#             */
/*   Updated: 2018/05/15 18:05:51 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		put_error(t_env *env, const char *err_msg)
{
	free_piles(env);
	pstr(2, err_msg, '\n');
	exit(1);
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
}

void		deinit_env(t_env *env)
{
	free_piles(env);
}
