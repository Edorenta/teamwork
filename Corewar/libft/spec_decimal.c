/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_decimal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourne <jjourne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 05:56:18 by jjourne           #+#    #+#             */
/*   Updated: 2018/04/10 06:16:09 by jjourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		spec_d(t_printf *data, va_list vl, t_type specifier, char **str)
{
	int neg;

	specifier.l = va_arg(vl, long);
	apply_modifier_signed(data, &specifier);
	if ((data->flag[0] & flag_pre) && (data->flag[2] == 0) && !(specifier.l))
	{
		if (!(*str = ft_strdup("")))
			exit(EXIT_FAILURE);
		neg = 0;
	}
	else if ((data->flag[0] & flag_l) || (data->flag[0] & flag_z)
		|| (data->flag[0] & flag_j))
	{
		if (!(*str = ft_lltoa_base(specifier.l, 10)))
			exit(EXIT_FAILURE);
		neg = (specifier.l < 0) ? 1 : 0;
	}
	else
	{
		if (!(*str = ft_lltoa_base(specifier.d, 10)))
			exit(EXIT_FAILURE);
		neg = (specifier.d < 0) ? 1 : 0;
	}
	spec_d_end(data, str, neg);
	return (ft_strlen(*str));
}

void	spec_d_end(t_printf *data, char **str, int neg)
{
	if ((data->flag[0] & flag_pre) && (data->flag[2] <= (int)ft_strlen(*str)))
		data->flag[0] &= ~flag_pre;
	data->flag[0] &= (data->flag[0] & flag_hash) ? ~flag_hash : data->flag[0];
	data->flag[0] &= (data->flag[0] & flag_pre) ? ~flag_zero : data->flag[0];
	data->flag[0] &= (neg) ? ~flag_space : data->flag[0];
	if (neg && (data->val_prefix = 1))
	{
		if (!(data->str_prefix = ft_strdup("-")))
			exit(EXIT_FAILURE);
		data->flag[0] |= flag_plus;
	}
	if ((data->flag[0] & flag_plus) && !(neg) && (data->val_prefix = 1))
	{
		if (!(data->str_prefix = ft_strdup("+")))
			exit(EXIT_FAILURE);
	}
}
