/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 17:59:42 by pde-rent          #+#    #+#             */
/*   Updated: 2018/05/18 10:50:20 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		g_sorted = 0;

static void		sig_handler(int sig)
{
	signal(sig, SIG_IGN);
	pstr(2, (g_sorted ? "\rOK\n" : "\rKO\n"), '\0');
	exit(0);
}

static int		interpret_bool(char *p, int i, int diff, char c)
{
	return ((p[i] == c || p[i] == c + 32) &&
			(!p[i + diff] || is_space(p[i + diff])));
}

static int		interpret_moves(t_env *env, char *p)
{
	int			i;

	i = -1;
	while (p[++i])
	{
		while (p[i] && is_space(p[i]))
			++i;
		if (interpret_bool(p, i, 2, 'P'))
			move_push(env, p, i);
		else if (interpret_bool(p, i, 2, 'S'))
			move_swap(env, p, i);
		else if (interpret_bool(p, i, 3, 'R') &&
				(p[i + 1] == 'r' || p[i + 1] == 'R'))
		{
			move_drot(env, p, i);
			++i;
		}
		else if (interpret_bool(p, i, 2, 'R'))
			move_rota(env, p, i);
		else
			put_error(env, "Error: wrong instruction");
		++i;
	}
	IS_SET_S ? put_piles(env) : 0;
	return (1);
}

static int		get_moves(t_env *env)
{
	static char input[1024] = {0};
	char		*p;
	char		c;
	int			i;
	int			handler;

	p = (char *)input;
	while (1)
	{
		i = -1;
		while ((handler = read(0, &c, 1)) > 0 && (c != 13 && c != 10))
			p[++i] = c;
		p[++i] = '\0';
		*p ? interpret_moves(env, p) : 0;
		g_sorted = all_sort(env);
		!handler ? sig_handler(SIGINT) : 0;
	}
	return (1);
}

int				main(int ac, char **av)
{
	t_env		env;

	signal(SIGINT, sig_handler);
	init_env(&env, ac);
	if (ac < 2)
		exit(0);
	if (!av[1] || !arg_to_piles(&env, ac, av)
		|| env.a[env.a1] == NONE || env.size == 0)
		put_error(&env, "Error: wrong input");
	(env.option & (1 << 2)) ? pstr(2, "Piles initialized:", '\n') : 0;
	(env.option & (1 << 2)) ? put_piles(&env) : 0;
	//index_pile(&env);
	//pstr(2, "Piles rebased:", '\n');
	//put_piles(&env);
	g_sorted = all_sort(&env);
	get_moves(&env);
	pstr(2, "Piles sorted:", '\n');
	put_piles(&env);
	deinit_env(&env);
	pstr(2, "Commands:", '\n');
	put_moves(env.first_move, 1, ' ');
	return (1);
}
