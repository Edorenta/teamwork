/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyildiz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 20:01:50 by jyildiz-          #+#    #+#             */
/*   Updated: 2018/05/14 19:25:27 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	*swap(t_env *env, char which)
{
	long	*pile;
	int		tmp;
	int		i;

	pile = (which == 'A' ? env->a : env->b);
	i = (which == 'A' ? env->a1 : env->b1);
	if (i < env->size && pile[i] != NONE && pile[i + 1] != NONE)
	{
		tmp = pile[i];
		pile[i] = pile[i + 1];
		pile[i + 1] = tmp;
	}
	env->last_move = new_move("S", which, env->prev_move); 
	env->last_move = env->last_move->next;
	return (pile);
}

t_env	*push(t_env *env, char to)
{
	int		*i;
	int		*j;
	int		tmp;
	long	*pilefrom;
	long	*pileto;

	pilefrom = (to == 'B' ? env->a : env->b);
	pileto = (to == 'B' ? env->b : env->a);
	i = (to == 'B' ? &env->a1 : &env->b1);
	j = (to == 'B' ? &env->b1 : &env->a1);
	if (pilefrom[*i] != NONE)
	{
		tmp = pilefrom[*i];
		pilefrom[*i] = pileto[*j];
		pileto[*j] = tmp;
		--*i;
		++*j;
	}
	env->last_move = new_move("P", to, env->prev_move); 
	env->last_move = env->last_move->next;
	return (env);
}

long	*rotate(t_env *env, char which)
{
	long	*pile;
	int		tmp;
	int		i;

	pile = (which == 'A' ? env->a : env->b);
	i = (which == 'A' ? env->a1 : env->b1);
	if (i < env->size)
	{
		tmp = pile[i];
		while (i < env->size - 1)
		{
			pile[i] = pile[i + 1];
			i++;
		}
		pile[i] = tmp;
	}
	env->last_move = new_move("R", which, env->prev_move); 
	env->last_move = env->last_move->next;
	return (pile);
}

long	*reverse_rotate(t_env *env, char which)
{
	long	*pile;
	int		tmp;
	int		felem;
	int		i;

	pile = (which == 'A' ? env->a : env->b);
	felem = (which == 'A' ? env->a1 : env->b1);
	i = env->size - 1;
	if (pile[env->size - 1] != NONE)
	{
		tmp = pile[env->size - 1];
		while (i >= felem)
		{
			pile[i] = pile[i - 1];
			i--;
		}
		pile[felem] = tmp;
	}
	env->last_move = new_move("RR", which, env->prev_move); 
	env->last_move = env->last_move->next;
	return (pile);
}

void	combine(long (*move)(t_env *, char), t_env *env)
{
	move(env, 'A');
	move(env, 'B');
}

/*
long	*swap(long *pile, int size, int felem)
{
	int		tmp;
	int		i;

	i = felem;
	if (i < size && pile[i] != NONE && pile[i + 1] != NONE)
	{
		tmp = pile[i];
		pile[i] = pile[i + 1];
		pile[i + 1] = tmp;
	}
	return (pile);
}

long	*rotate(long *pile, int size, int felem)
{
	int		i;
	int		tmp;

	i = felem;
	if (i < size)
	{
		tmp = pile[i];
		while (i < size - 1)
		{
			pile[i] = pile[i + 1];
			i++;
		}
		pile[i] = tmp;
	}
	return (pile);
}

long	*reverse_rotate(long *pile, int size, int felem)
{
	int		i;
	int		tmp;

	i = size - 1;
	if (pile[size - 1] != NONE)
	{
		tmp = pile[size - 1];
		while (i >= felem)
		{
			pile[i] = pile[i - 1];
			i--;
		}
		pile[felem] = tmp;
	}
	return (pile);
}
*/
