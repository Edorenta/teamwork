/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ext_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 17:59:42 by pde-rent          #+#    #+#             */
/*   Updated: 2018/05/15 17:59:43 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int g_sorted = 0;

static void			sig_handler(int sig)
{
     signal(sig, SIG_IGN);
     pstr(2, (g_sorted ? "\rOK\n" : "\rKO\n"), '\0');
     exit(0);
}

static int 		interpret_moves(t_env *env, char *p)
{
	int i;

	i = -1;
	while (p[++i])
	{
		while (p[i] && is_space(p[i]))
			++i;
		if ((p[i] == 'p' || p[i] == 'P')
			&& (!p[i + 2] || is_space(p[i + 2])))
		{
			(p[i + 1] == 'a' || p[i + 1] == 'A') ? PA : 0;
			(p[i + 1] == 'b' || p[i + 1] == 'B') ? PB : 0;
		}
		else if ((p[i] == 's' || p[i] == 'S')
			&& (!p[i + 2] || is_space(p[i + 2])))
		{
			(p[i + 1] == 'a' || p[i + 1] == 'A') ? SA : 0;
			(p[i + 1] == 'b' || p[i + 1] == 'B') ? SB : 0;
			(p[i + 1] == 's' || p[i + 1] == 'S') ? SS : 0;
		}
		else if ((p[i] == 'r' || p[i] == 'R')
			&& (p[i + 1] == 'r' || p[i + 1] == 'R')
			&& (!p[i + 3] || is_space(p[i + 3])))
		{
			(p[i + 2] == 'a' || p[i + 2] == 'A') ? RRA : 0;
			(p[i + 2] == 'b' || p[i + 2] == 'B') ? RRB : 0;
			(p[i + 2] == 'r' || p[i + 2] == 'R') ? RRR : 0;
			++i;
		}
		else if ((p[i] == 'r' || p[i] == 'R')
			&& (!p[i + 2] || is_space(p[i + 2])))
		{
			(p[i + 1] == 'a' || p[i + 1] == 'A') ? RA : 0;
			(p[i + 1] == 'b' || p[i + 1] == 'B') ? RB : 0;
			(p[i + 1] == 'r' || p[i + 1] == 'R') ? RR : 0;
		}
		else
			put_error(env, "Error: wrong in struction");
		++i;
	}
	return (1);
}

static int		get_moves(t_env *env)
{
	static char input[1024] = {0};
	char *p;
	char c;
	int i;

	p = (char *)input;
	while (1)
	//while(!all_sort(env))
	{
		i = -1;
		while((read(0, &c, 1) > 0) && (c != 13 && c != 10))
			p[++i] = c;
		p[++i] = '\0';
		//pstr(2, p, '\n');
		interpret_moves(env, p);
		put_piles(env);
		g_sorted = all_sort(env);
	}
	return (1);
}

int				main(int ac, char **av)
{
	t_env	env;

	signal(SIGINT, sig_handler);
	init_env(&env, ac);
	if (ac < 2 || !av[1] || !arg_to_piles(&env, ac, av))
		put_error(&env, "Error: wrong input");
	//init piles
	pstr(2, "Piles initialized:", '\n');
	put_piles(&env);
	//index pile
	//index_pile(&env);
	//pstr(2, "Piles rebased:", '\n');
	//put_piles(&env);
	//manual sort
	get_moves(&env);
	pstr(2, "Piles sorted:", '\n');
	put_piles(&env);
	//deinit piles
	deinit_env(&env);
	//print commands
	pstr(2, "Commands:", '\n');
	put_moves(env.first_move, 1, ' ');
	return (1);
}