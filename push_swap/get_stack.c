/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyildiz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 05:11:42 by jyildiz-          #+#    #+#             */
/*   Updated: 2018/05/12 06:07:02 by jyildiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		alloc_piles(t_env *env)
{
	int i;

	i = -1;
	if (!(env->a = (int *)malloc(sizeof(int) * env->size)))
		put_error();
	if (!(env->b = (int *)malloc(sizeof(int) * env->size)))
		put_error();
	while (++i < env->size)
	{
		env->a[i] = NONE;
		env->b[i] = NONE;
	}
	return (1);
}

int 	compliant_arg(int ac, char **av, t_env *env)
{
	int spaces;

	while (env->size < ac && i > 0 && av[i])
	{
		if (!full_digits(av[i]))
			return (0);
		spaces += space_in(av[i]);
		if (spaces && ac += spaces)
			//env->size += split_push(av[i], spaces, env);
			env->size += (spaces + 1);
		else
			env->size += 1;
		i++;
	}
	return (1);
}
