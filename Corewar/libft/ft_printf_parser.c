/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 04:09:54 by jjourne           #+#    #+#             */
/*   Updated: 2018/04/10 04:09:57 by jjourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_flag(t_printf *data, int i)
{
	int *j;

	j = &(data->format_i);
	if (!(data->format[*j + 1]))
		return (0);
	while (ft_strchr(FLAG, data->format[++(*j)]) && (i = -1))
	{
		while (++i <= 11)
			if (data->format[*j] != 'h')
				data->flag[0] |= (data->format[*j] == FLAG[i]) << i;
		if (data->format[*j] == 'h' && (data->flag[0] |= flag_hh))
			data->flag[0] ^= (data->flag[0] & flag_h) ? 1 << 6 : 3 << 5;
		if (ft_isdigit(data->format[*j]) && (data->format[*j] != '0') &&
				(data->flag[0] |= flag_width) && !(data->flag[1] = 0))
		{
			--*j;
			while (ft_isdigit(data->format[*j + 1]) && (++*j))
				data->flag[1] = data->flag[1] * 10 + data->format[*j] - '0';
		}
		if ((data->format[*j] == '.') && !(data->flag[2] = 0))
			while (ft_isdigit(data->format[*j + 1]) && (++*j))
				data->flag[2] = data->flag[2] * 10 + data->format[*j] - '0';
	}
	maj_specifiers(data);
	return (1);
}

void	maj_specifiers(t_printf *data)
{
	if (data->format[data->format_i] == 'D' ||
			data->format[data->format_i] == 'O' ||
			data->format[data->format_i] == 'U')
		data->flag[0] |= flag_l;
	if (data->format[data->format_i] == 'c' && (data->flag[0] & flag_l))
		data->format[data->format_i] = 'C';
	if (data->format[data->format_i] == 's' && (data->flag[0] & flag_l))
		data->format[data->format_i] = 'S';
}

void	percent_case(t_printf *data)
{
	if (!(data->flag[0] & flag_neg))
	{
		put_n_char_to_result(data, (data->flag[0] & flag_zero)
				? '0' : ' ', data->flag[1] - 1);
		add_to_result(data, data->format[data->format_i], 1);
	}
	else
	{
		add_to_result(data, data->format[data->format_i], 1);
		put_n_char_to_result(data, (data->flag[0] & flag_zero) ?
				'0' : ' ', data->flag[1] - 1);
	}
}

void	ft_printf_parser(t_printf *data, va_list vl)
{
	t_bool	is_flag;
	int		ret;
	int		i;

	i = 0;
	while ((data->format[++(data->format_i)]) && !(is_flag = false))
	{
		if (data->format[data->format_i] == '%' && (is_flag = true))
		{
			data->flag[0] = 0;
			ret = get_flag(data, i);
			if (ft_strchr(SPECIFIER, data->format[data->format_i]))
				apply_specifier(data, vl);
			else if ((!(ft_strchr(SPECIFIER,
								data->format[data->format_i]))) && ret)
				percent_case(data);
			else if (ret)
				add_to_result(data, 'c', 0);
		}
		else
			add_to_result(data, 'c', 0);
	}
}
