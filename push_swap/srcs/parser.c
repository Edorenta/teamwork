/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyildiz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 05:11:42 by jyildiz-          #+#    #+#             */
/*   Updated: 2018/05/15 18:01:54 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		push_to_pile(t_env *env, char *av)
{
	static int	i = -1;

	!is_int(av) ? put_error(env, "Error: arg not int") : 0;
	env->a[++i] = ft_atol(av);
	!no_duplicates(env->a, i + 1) ? put_error(env, "Error: duplicates") : 0;
	return (1);
}

static int		split_to_pile(t_env *env, char *str, int spaces)
{
	char		av[spaces][16];
	char		*p;
	int			i;
	int			j;

	i = 0;
	p = str;
	while (*p)
	{
		while (*p && is_space(*p))
			p++;
		j = -1;
		while (*p && ((*p >= '0' && *p <= '9') || *p == '-' || *p == '+'))
			av[i][++j] = *(p++);
		av[i][++j] = '\0';
		i++;
	}
	i = -1;
	while (++i < (spaces))
		push_to_pile(env, av[i]);
	return (spaces);
}

static int		get_option(t_env *env, char *av)
{
	int i;

	i = 0;
	while (av[++i])
	{
		if ((av[i] != 'v' && av[i] != 's' && av[i] != 'o'&& av[i] != 'r'))
			put_error(env, "Error: invalid option");
		else if ((av[i] == 'v' && IS_SET_V) || (av[i] == 's' && IS_SET_S)
			|| (av[i] == 'o' && IS_SET_O) || (av[i] == 'r' && IS_SET_R))
			put_error(env, "Error: duplicate option");
		(av[i] == 'v') ? SET_V : 0; //verbose breakpoints
		(av[i] == 'o') ? SET_O : 0; //move counter
		(av[i] == 's') ? SET_S : 0; //pile state
		(av[i] == 'r') ? SET_R : 0; //display A as rebased
	}
	return (active_bits(env->option));
}

int				arg_to_piles(t_env *env, int ac, char **av)
{
	int			i;
	int			opt;

	opt = 0;
	i = 0;
	while (++i < ac && av[i] && av[i][0] == '-'){
		opt += get_option(env, av[i]);
		--env->size;
	}
	i--;
	while (++i < ac && av[i])
		env->size += spaces_in(av[i]);
	alloc_piles(env);
	i = opt ? 1 : 0;
	while (++i < ac && av[i])
		spaces_in(av[i]) ? split_to_pile(env, av[i], spaces_in(av[i]) + 1)
		: push_to_pile(env, av[i]);
	env->b1 = env->size - 1;
	return (1);
}
