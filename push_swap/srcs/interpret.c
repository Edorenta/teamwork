/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpret.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 09:22:57 by fmadura           #+#    #+#             */
/*   Updated: 2018/05/18 10:35:59 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_push(t_env *env, char *p, int i)
{
	(p[i + 1] == 'a' || p[i + 1] == 'A') ? PA : 0;
	(p[i + 1] == 'b' || p[i + 1] == 'B') ? PB : 0;
}

void	move_swap(t_env *env, char *p, int i)
{
	(p[i + 1] == 'a' || p[i + 1] == 'A') ? SA : 0;
	(p[i + 1] == 'b' || p[i + 1] == 'B') ? SB : 0;
	(p[i + 1] == 's' || p[i + 1] == 'S') ? SS : 0;
}

void	move_drot(t_env *env, char *p, int i)
{
	(p[i + 2] == 'a' || p[i + 2] == 'A') ? RRA : 0;
	(p[i + 2] == 'b' || p[i + 2] == 'B') ? RRB : 0;
	(p[i + 2] == 'r' || p[i + 2] == 'R') ? RRR : 0;
}

void	move_rota(t_env *env, char *p, int i)
{
	(p[i + 1] == 'a' || p[i + 1] == 'A') ? RA : 0;
	(p[i + 1] == 'b' || p[i + 1] == 'B') ? RB : 0;
	(p[i + 1] == 'r' || p[i + 1] == 'R') ? RR : 0;
}
