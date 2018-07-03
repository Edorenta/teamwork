/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_lfork.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyildiz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 07:06:18 by jyildiz-          #+#    #+#             */
/*   Updated: 2018/07/03 07:06:21 by jyildiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

static void	cw_check_args(t_asm *comp, int i)
{
	if (!(comp->r_str = ft_strsub(comp->line, i, ft_strlen(comp->line) - i)))
		cw_error(comp, "Malloc error (counting args)\n");
	cw_count_args(comp, comp->r_str, 1);
	i = cw_check_dir(comp, comp->r_str, 0);
	if (comp->r_str[i])
		cw_error(comp, "Bad argument (lfork instruction)\n");
}

void		cw_lfork(t_asm *comp, int i)
{
	ft_strdel(&comp->r_str);
	comp->data[comp->i++] = 15;
	i = ft_skip_whitespace(comp->line, i);
	cw_check_args(comp, i);
	cw_get_args(comp, 1, 2, 1);
}
