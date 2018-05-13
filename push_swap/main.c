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

static void	put_error(t_env *env, const char *err_msg)
{
	env->a ? free(a) : 0;
	env->b ? free(b) : 0;
	pstr(err_msg);
	exit(1);
}

int		alloc_piles(t_env *env)
{
	int i;

	i = -1;
	if (!(env->a = (int *)malloc(sizeof(int) * env->size))
		|| !(env->b = (int *)malloc(sizeof(int) * env->size)))
		put_error(env, Error);
	while (++i < env->size)
	{
		env->a[i] = NONE;
		env->b[i] = NONE;
	}
	return (1);
}

void	free_pile(t_env *env);
{
	env->a ? free(a) : 0;
	env->b ? free(b) : 0;
}

int 		compliant_arg(int ac, char **av, t_env *env)
{
	int spaces;
	int	i;

	i = 1;
	while (env->size < ac && av[i])
	{
		spaces += space_in(av[i]);
		if (spaces && ac += spaces)
			env->size += (spaces + 1);
		else if (full_digits(av[i]))
			env->size += 1;
		else
			return (0);
		alloc_piles(env);

		i++;
	}
	return (1);
}


int 		get_stacks(int ac, char **av, t_env *env)
{
	int spaces;

	env->size = 0;
	while (env->size < ac && i > 0 && av[i])
	{
		spaces += space_in(av[i]);
		if (spaces && ac += split_push(av[i], spaces, env))
			env->size += (spaces + 1);
		else if (!full_digits(av[i]))
			env->size += push_to_stack(env, av[i]);
		i++;
	}
	return (1);
}


int		main(int ac, char **av)
{
	t_env env;

	env.size = 0;
	env.a = NULL;
	env.b = NULL;
	if (ac < 2 || !av[1] || !compliant_arg(ac, av, &env))
		put_error(env, Error);
	//get_option(ac, av, &env);
	begin_sort(&env);
	//a = stock_table(ac, av); >> get_stack
	//b = create_table(ac); >> get_stack
	//push_swap(a, b, ac - 1);
	free_pile(a, b);
	return (1);
}
