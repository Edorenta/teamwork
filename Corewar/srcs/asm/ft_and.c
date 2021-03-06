/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_and.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 08:07:30 by fmadura           #+#    #+#             */
/*   Updated: 2018/07/03 08:07:36 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op_asm.h"

static void	ft_check_args(t_asm *comp, int i, int *total_size)
{
	int		ret;

	if (!(comp->r_str = ft_strsub(comp->line, i, ft_strlen(comp->line) - i)))
		ft_error(comp, "Malloc error (counting args)\n");
	ft_count_args(comp, comp->r_str, 3);
	i = 0;
	if ((ret = ft_get_type(comp->r_str[i], total_size)) == 1)
		i = ft_check_reg(comp, comp->r_str, i);
	else if (ret == 2)
		i = ft_check_dir(comp, comp->r_str, i);
	else
		i = ft_check_ind(comp, comp->r_str, i);
	i = ft_check_separator(comp, i, "Bad argument (and instruction)\n");
	if ((ret = ft_get_type(comp->r_str[i], total_size)) == 1)
		i = ft_check_reg(comp, comp->r_str, i);
	else if (ret == 2)
		i = ft_check_dir(comp, comp->r_str, i);
	else
		i = ft_check_ind(comp, comp->r_str, i);
	i = ft_check_separator(comp, i, "Bad argument (and instruction)\n");
	ft_get_type(comp->r_str[i], total_size);
	i = ft_check_reg(comp, comp->r_str, i);
	if (comp->r_str[i])
		ft_error(comp, "Bad argument (and instruction)\n");
	(*total_size) = (*total_size) << 2;
}

void		ft_and(t_asm *comp, int i)
{
	int		total_size;
	int		label_index;

	total_size = 0;
	label_index = 2;
	ft_strdel(&comp->r_str);
	comp->data[comp->i++] = 6;
	i = ft_skip_whitespace(comp->line, i);
	ft_check_args(comp, i, &total_size);
	comp->data[comp->i++] = total_size;
	i = 0;
	i = ft_get_args(comp, i + ft_tsize(4, total_size >> 6, 1),
			ft_tsize(4, total_size >> 6, 0), label_index);
	label_index += ft_tsize(4, total_size >> 6, 0);
	i = ft_get_args(comp, i + ft_tsize(4, (total_size >> 4) & 0x3, 1),
			ft_tsize(4, (total_size >> 4) & 0x3, 0), label_index);
	label_index += ft_tsize(4, (total_size >> 4) & 0x3, 0);
	ft_get_args(comp, i + 1, 1, label_index);
}
