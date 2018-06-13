/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 19:19:40 by pde-rent          #+#    #+#             */
/*   Updated: 2018/06/12 18:23:23 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		push_to_pile(t_env *env, char *av)
{
	static int	i = -1;

	env->a[++i] = fatol(env, av);
	!no_duplicates(env->a, i + 1) ? put_error(env, "Error: duplicates") : 0;
	return (1);
}

static int		split_to_pile(t_env *env, char *p, int spaces)
{
	char		av[spaces][32];
	int			i;
	int			j;
	int			k;

	i = 0;
	k = 0;
	while (p[k])
	{
		while (p[k] && is_space(p[k]))
			p++;
		p[k] ? 0 : put_error(env, "Error: empty arg");
		j = -1;
		while (p[k] && (is_digit(p[k]) || ((p[k] == '-' || p[k] == '+'))))
			(av[i][++j] = p[k++]);
		(j >= 0) ? 0 : put_error(env, "Error: wrong arg");
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
		if ((av[i] != 'v' && av[i] != 's' && av[i] != 'o' && av[i] != 'r'
			&& av[i] != 'm' && av[i] != 't' && av[i] != 'j'))
			put_error(env, "Error: invalid option");
		else if ((av[i] == 'v' && IS_SET_V) || (av[i] == 's' && IS_SET_S)
			|| (av[i] == 'o' && IS_SET_O) || (av[i] == 'r' && IS_SET_R)
			|| (av[i] == 'm' && IS_SET_M) || (av[i] == 't' && IS_SET_T)
			|| (av[i] == 'j' && IS_SET_J))
			put_error(env, "Error: duplicate option");
		(av[i] == 'v') ? SET_V : 0;
		(av[i] == 'o') ? SET_O : 0;
		(av[i] == 's') ? SET_S : 0;
		(av[i] == 'r') ? SET_R : 0;
		(av[i] == 'm') ? SET_M : 0;
		(av[i] == 't') ? SET_T : 0;
		(av[i] == 'j') ? SET_J : 0;
	}
	return (active_bits(env->option));
}

int				arg_to_piles(t_env *env, int ac, char **av)
{
	int			i;
	int			opt;

	opt = 0;
	i = 0;
	while (++i < ac && av[i] && av[i][0] == '-' && !is_digit(av[i][1]))
	{
		get_option(env, av[i]);
		opt++;
		--env->size;
	}
	i--;
	while (++i < ac && av[i])
		env->size += spaces_in(av[i]);
	alloc_piles(env);
	i = opt ? opt : 0;
	while (++i < ac && av[i])
		spaces_in(av[i]) ? split_to_pile(env, av[i], spaces_in(av[i]) + 1)
		: push_to_pile(env, av[i]);
	env->b1 = env->size - 1;
	(env->size == 1) ? soft_exit(env) : 0;
	env->b1 <= 0 ? put_error(env, "Error: wrong input") : 0;
	return (1);
}
