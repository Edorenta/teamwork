/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 17:59:42 by pde-rent          #+#    #+#             */
/*   Updated: 2018/06/03 18:25:22 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		g_sorted = 0;

void			sig_handler(int sig)
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
		else if (p[i + 2] && !is_space(p[i + 2]) && interpret_bool(p, i, 3, 'R')
				&& (p[i + 1] == 'r' || p[i + 1] == 'R'))
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

int				get_moves(t_env *env)
{
	static char input[10240] = {0};
	char		*p;
	char		c;
	int			i;
	int			handler;

	g_sorted = all_sort(env);
	p = (char *)input;
	while (1)
	{
		i = -1;
		while ((handler = read(0, &c, 1)) >= 0)
		{
			p[++i] = c;
			!handler ? sig_handler(SIGINT) : 0;
			if (c == 10)
			{
				p[i] = '\0';
				*p ? interpret_moves(env, p) : 0;
				g_sorted = all_sort(env);
				i = -1;
			}
		}
	}
	return (1);
}
