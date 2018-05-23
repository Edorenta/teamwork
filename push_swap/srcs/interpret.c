/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpret.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 09:22:57 by fmadura           #+#    #+#             */
/*   Updated: 2018/05/18 10:47:28 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		integrity_check(t_env *env, const char *s, char c, char end)
{
	char	*p;
	int		i;

	i = -1;
	p = (char *)s;
	if (is_space(end) || !end)
		while (++i < slen(p))
			if (s[i] == c)
				return ;
	put_error(env, "Error: wrong instruction");
}

void	move_push(t_env *env, char *p, int i)
{
	integrity_check(env, "AaBb\0", p[i + 1], p[i + 2]);
	(p[i + 1] == 'a' || p[i + 1] == 'A') ? PA : 0;
	(p[i + 1] == 'b' || p[i + 1] == 'B') ? PB : 0;
}

void	move_swap(t_env *env, char *p, int i)
{
	integrity_check(env, "AaBbSs\0", p[i + 1], p[i + 2]);
	(p[i + 1] == 'a' || p[i + 1] == 'A') ? SA : 0;
	(p[i + 1] == 'b' || p[i + 1] == 'B') ? SB : 0;
	(p[i + 1] == 's' || p[i + 1] == 'S') ? SS : 0;
}

void	move_drot(t_env *env, char *p, int i)
{
	integrity_check(env, "AaBbRr\0", p[i + 2], p[i + 3]);
	(p[i + 2] == 'a' || p[i + 2] == 'A') ? RRA : 0;
	(p[i + 2] == 'b' || p[i + 2] == 'B') ? RRB : 0;
	(p[i + 2] == 'r' || p[i + 2] == 'R') ? RRR : 0;
}

void	move_rota(t_env *env, char *p, int i)
{
	integrity_check(env, "AaBbRr", p[i + 1], p[i + 2]);
	(p[i + 1] == 'a' || p[i + 1] == 'A') ? RA : 0;
	(p[i + 1] == 'b' || p[i + 1] == 'B') ? RB : 0;
	(p[i + 1] == 'r' || p[i + 1] == 'R') ? RR : 0;
}
