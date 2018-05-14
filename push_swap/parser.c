/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyildiz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 05:11:42 by jyildiz-          #+#    #+#             */
/*   Updated: 2018/05/14 14:56:10 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

inline static int	push_to_pile(t_env *env, char *av)
{
	static int  i = -1;

	!is_int(av) ? put_error(env, "Error") : 0;
	env->a[++i] = ft_atol(av);
	!no_duplicates(env->a, env->size) ? put_error(env, "Error") : 0;
	return (1);
}

inline static int	split_to_pile(t_env *env, char *str, int spaces)
{
	char	av[spaces][16];
	char	*p;
	int		i;
	int		j;

	i = 0;
	p = str;
	while (*p)
	{
		while (*p && is_space(*p))
			p++;
		j = -1;
		while (*p && (*p >= '0' && *p <= '9'))
			av[i][++j] = *p++;
		av[i][++j] = '\0';
		//dprintf(1, "tok[%d] : %s\n", i, av[i]);
		i++;
	}
	//dprintf(1, "tokens: %d theorical: %d\n", i, spaces + 1);
	i = -1;
	while (++i < (spaces + 1))
		push_to_pile(env, av[i]);
	return (spaces + 1);
}

int 				arg_to_piles(t_env *env, int ac, char **av)
{
	int	i;

	i = 0;
	while (++i < ac && av[i])
		env->size += spaces_in(av[i]);
	alloc_piles(env);
	i = 0;
	while (++i < ac && av[i])
		spaces_in(av[i]) ? split_to_pile(env, av[i], spaces_in(av[i])) : push_to_pile(env, av[i]);
	return (1);
}
