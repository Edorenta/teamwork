/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 19:18:58 by pde-rent          #+#    #+#             */
/*   Updated: 2018/06/07 19:19:02 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_env *env, char which)
{
	long	*pile;
	int		tmp;
	int		i;

	pile = (which == 'a' ? env->a : env->b);
	i = (which == 'a' ? env->a1 : env->b1);
	if (i < env->size && pile[i] != NONE && pile[i + 1] != NONE)
	{
		tmp = pile[i];
		pile[i] = pile[i + 1];
		pile[i + 1] = tmp;
	}
	archive_move(env, "s", which, env->this_move);
}

void	push(t_env *env, char to)
{
	int		*i;
	int		*j;
	long	*pilefrom;
	long	*pileto;

	pilefrom = (to == 'b' ? env->a : env->b);
	pileto = (to == 'b' ? env->b : env->a);
	i = (to == 'b' ? &env->a1 : &env->b1);
	j = (to == 'b' ? &env->b1 : &env->a1);
	if (pilefrom[*i] != NONE)
	{
		(*j == env->size - 1 && pileto[*j] == NONE) ? 0 : --*j;
		pileto[*j] = pilefrom[*i];
		pilefrom[*i] = NONE;
		*i == env->size - 1 ? 0 : ++*i;
	}
	archive_move(env, "p", to, env->this_move);
}

void	rotate(t_env *env, char which)
{
	long	*pile;
	int		tmp;
	int		i;

	pile = (which == 'a' ? env->a : env->b);
	i = (which == 'a' ? env->a1 : env->b1);
	if (i < env->size && pile[i] != NONE)
	{
		tmp = pile[i];
		while (i < env->size - 1)
		{
			pile[i] = pile[i + 1];
			i++;
		}
		pile[i] = tmp;
	}
	archive_move(env, "r", which, env->this_move);
}

void	rev_rotate(t_env *env, char which)
{
	long	*pile;
	int		tmp;
	int		start;
	int		i;

	pile = (which == 'a' ? env->a : env->b);
	start = (which == 'a' ? env->a1 : env->b1);
	i = env->size - 1;
	if (pile[env->size - 1] != NONE)
	{
		tmp = pile[env->size - 1];
		while (i > start)
		{
			pile[i] = pile[i - 1];
			i--;
		}
		pile[start] = tmp;
	}
	archive_move(env, "rr", which, env->this_move);
}

void	combine(void (*move)(t_env *, char), t_env *env)
{
	move(env, 'a');
	move(env, 'b');
}
