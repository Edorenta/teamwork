/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyildiz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 07:07:33 by jyildiz-          #+#    #+#             */
/*   Updated: 2018/07/03 07:07:36 by jyildiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

static void	cw_check_args(t_asm *comp, int i, int *total_size)
{
	int		ret;

	if (!(comp->r_str = ft_strsub(comp->line, i, ft_strlen(comp->line) - i)))
		cw_error(comp, "Malloc error (counting args)\n");
	cw_count_args(comp, comp->r_str, 3);
	i = 0;
	cw_get_type(comp->r_str[i], total_size);
	i = cw_check_reg(comp, comp->r_str, i);
	i = cw_check_separator(comp, i, "Bad argument (sti instruction)\n");
	if ((ret = cw_get_type(comp->r_str[i], total_size)) == 1)
		i = cw_check_reg(comp, comp->r_str, i);
	else if (ret == 2)
		i = cw_check_dir(comp, comp->r_str, i);
	else
		i = cw_check_ind(comp, comp->r_str, i);
	i = cw_check_separator(comp, i, "Bad argument (sti instruction)\n");
	if ((ret = cw_get_type(comp->r_str[i], total_size)) == 1)
		i = cw_check_reg(comp, comp->r_str, i);
	else if (ret == 2)
		i = cw_check_dir(comp, comp->r_str, i);
	else
		cw_error(comp, "Bad argument (sti instruction)\n");
	if (comp->r_str[i])
		cw_error(comp, "Bad argument (sti instruction)\n");
	(*total_size) = (*total_size) << 2;
}

void		cw_sti(t_asm *comp, int i)
{
	int		total_size;
	int		label_index;

	total_size = 0;
	label_index = 2;
	ft_strdel(&comp->r_str);
	comp->data[comp->i++] = 11;
	i = ft_skip_whitespace(comp->line, i);
	cw_check_args(comp, i, &total_size);
	comp->data[comp->i++] = total_size;
	i = 0;
	i = cw_get_args(comp, i + cw_tsize(2, total_size >> 6, 1),
		cw_tsize(2, total_size >> 6, 0), label_index);
	label_index += cw_tsize(2, total_size >> 6, 0);
	i = cw_get_args(comp, i + cw_tsize(2, (total_size >> 4) & 0x3, 1),
		cw_tsize(2, (total_size >> 4) & 0x3, 0), label_index);
	label_index += cw_tsize(2, (total_size >> 4) & 0x3, 0);
	cw_get_args(comp, i + cw_tsize(2, (total_size >> 2) & 0x3, 1),
		cw_tsize(2, (total_size >> 2) & 0x3, 0), label_index);
}
