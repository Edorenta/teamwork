/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_format.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourne <jjourne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 04:45:38 by jjourne           #+#    #+#             */
/*   Updated: 2018/04/10 05:20:16 by jjourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		spec_o(t_printf *data, va_list vl, t_type specifier, char **str)
{
	specifier.ul = va_arg(vl, unsigned long);
	apply_modifier_unsigned(data, &specifier);
	if ((data->flag[0] & flag_pre) && (data->flag[2] == 0) && !(specifier.ul))
	{
		if (!(*str = ft_strdup("")))
			exit(EXIT_FAILURE);
	}
	else if (specifier.ul == 0)
	{
		*str = ft_strdup("0");
		data->flag[0] &= ~flag_hash;
	}
	else if ((data->flag[0] & flag_l) || (data->flag[0] & flag_z) ||
		(data->flag[0] & flag_j))
	{
		if (!(*str = ft_ulltoa_base(specifier.ul, 8)))
			exit(EXIT_FAILURE);
	}
	else
	{
		if (!(*str = ft_ulltoa_base(specifier.u, 8)))
			exit(EXIT_FAILURE);
	}
	spec_o_end(data, str);
	return (ft_strlen(*str));
}

void	spec_o_end(t_printf *data, char **str)
{
	if ((data->flag[0] & flag_pre) && (data->flag[2] <= (int)ft_strlen(*str)))
		data->flag[0] &= ~flag_pre;
	data->flag[0] &= (data->flag[0] & flag_plus) ? ~flag_plus : data->flag[0];
	data->flag[0] &= (data->flag[0] & flag_space) ? ~flag_space : data->flag[0];
	if (data->flag[2] > (int)ft_strlen(*str))
		data->flag[0] &= ~flag_hash;
	if ((data->flag[0] & flag_hash))
	{
		data->flag[0] &= ~flag_space;
		data->val_prefix = 1;
		if (!(data->str_prefix = ft_strdup("0")))
			exit(EXIT_FAILURE);
	}
	data->flag[0] &= (data->flag[0] & flag_pre) ? ~flag_zero : data->flag[0];
}

int		spec_x(t_printf *data, va_list vl, t_type specifier, char **str)
{
	int i;

	i = -1;
	specifier.ul = va_arg(vl, unsigned long);
	apply_modifier_unsigned(data, &specifier);
	if ((data->flag[0] & flag_pre) && (data->flag[2] == 0))
	{
		if (!(*str = ft_strdup("")))
			exit(EXIT_FAILURE);
	}
	else if ((data->flag[0] & flag_l) || (data->flag[0] & flag_z) ||
		(data->flag[0] & flag_j))
	{
		if (!(*str = ft_ulltoa_base(specifier.ul, 16)))
			exit(EXIT_FAILURE);
	}
	else
	{
		if (!(*str = ft_ulltoa_base(specifier.u, 16)))
			exit(EXIT_FAILURE);
	}
	spec_x_end(data, specifier, str, i);
	return (ft_strlen(*str));
}

void	spec_x_end(t_printf *data, t_type specifier, char **str, int i)
{
	while (++i <= (int)ft_strlen(*str))
		if (data->format[data->format_i] == 'X')
			(*str)[i] = ft_toupper((*str)[i]);
	if ((data->flag[0] & flag_pre) && (data->flag[2] <= (int)ft_strlen(*str)))
		data->flag[0] &= ~flag_pre;
	data->flag[0] &= (data->flag[0] & flag_plus) ? ~flag_plus : data->flag[0];
	data->flag[0] &= (data->flag[0] & flag_space) ? ~flag_space : data->flag[0];
	if ((data->flag[0] & flag_hash) && (specifier.ul != 0))
	{
		data->flag[0] &= ~flag_space;
		if (data->format[data->format_i] == 'x')
		{
			if (!(data->str_prefix = ft_strdup("0x")))
				exit(EXIT_FAILURE);
		}
		else
		{
			if (!(data->str_prefix = ft_strdup("0X")))
				exit(EXIT_FAILURE);
		}
		data->val_prefix = 2;
	}
	data->flag[0] &= (data->flag[0] & flag_pre) ? ~flag_zero : data->flag[0];
}
