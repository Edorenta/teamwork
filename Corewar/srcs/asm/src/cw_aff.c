/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyildiz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 07:01:49 by jyildiz-          #+#    #+#             */
/*   Updated: 2018/07/03 07:04:51 by jyildiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

static void	cw_check_args(t_asm *comp, int i, int *total_size)
{
	if (!(comp->r_str = ft_strsub(comp->line, i, ft_strlen(comp->line) - i)))
		cw_error(comp, "Malloc error (counting args)\n");
	cw_count_args(comp, comp->r_str, 1);
	*total_size = 0x40;
	i = cw_check_reg(comp, comp->r_str, 0);
	if (comp->r_str[i])
		cw_error(comp, "Bad argument (aff instruction)\n");
}

void		cw_aff(t_asm *comp, int i)
{
	int		total_size;

	ft_strdel(&comp->r_str);
	comp->data[comp->i++] = 16;
	i = ft_skip_whitespace(comp->line, i);
	cw_check_args(comp, i, &total_size);
	comp->data[comp->i++] = total_size;
	cw_get_args(comp, 1, 1, 2);
}
