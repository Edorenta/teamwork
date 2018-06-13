/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_type.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourne <jjourne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 04:45:46 by jjourne           #+#    #+#             */
/*   Updated: 2018/04/10 06:08:43 by jjourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		spec_s(t_printf *data, va_list vl, t_type specifier, char **str)
{
	int		len_arg;
	char	*str_tmp;

	specifier.s = va_arg(vl, char *);
	if (specifier.s == NULL)
	{
		if (!(str_tmp = ft_strdup("(null)")))
			exit(EXIT_FAILURE);
	}
	else
	{
		if (!(str_tmp = ft_strdup(specifier.s)))
			exit(EXIT_FAILURE);
	}
	len_arg = ft_strlen(str_tmp);
	len_arg = spec_s_end(data, str, str_tmp, len_arg);
	return (len_arg);
}

int		spec_s_end(t_printf *data, char **str, char *str_tmp, int len_arg)
{
	if ((data->flag[0] & flag_pre) && (data->flag[2] < len_arg))
	{
		if (!(*str = (char*)ft_memalloc(data->flag[2] + 1)))
			exit(EXIT_FAILURE);
		ft_strncpy(*str, str_tmp, data->flag[2]);
	}
	else
	{
		if (!(*str = ft_strdup(str_tmp)))
			exit(EXIT_FAILURE);
	}
	len_arg = ft_strlen(*str);
	data->flag[0] &= (data->flag[0] & flag_plus) ? ~flag_plus : data->flag[0];
	data->flag[0] &= (data->flag[0] & flag_hash) ? ~flag_hash : data->flag[0];
	data->flag[0] &= (data->flag[0] & flag_space) ? ~flag_space : data->flag[0];
	if ((data->flag[0] & flag_pre) && (data->flag[2] >= len_arg))
		data->flag[0] &= ~flag_pre;
	free(str_tmp);
	return (len_arg);
}

int		spec_c(t_printf *data, va_list vl, t_type specifier, char **str)
{
	char tab[2];

	(void)specifier;
	ft_bzero(tab, 2);
	tab[0] = (char)va_arg(vl, int);
	if (!(*str = ft_strdup((char*)tab)))
		exit(EXIT_FAILURE);
	data->flag[0] &= (data->flag[0] & flag_plus) ? ~flag_plus : data->flag[0];
	data->flag[0] &= (data->flag[0] & flag_hash) ? ~flag_hash : data->flag[0];
	data->flag[0] &= (data->flag[0] & flag_space) ? ~flag_space : data->flag[0];
	if ((data->flag[0] & flag_pre) && (data->flag[2] >= 1))
		data->flag[0] &= ~flag_pre;
	return (1);
}

int		spec_p(t_printf *data, va_list vl, t_type specifier, char **str)
{
	int len_arg;

	specifier.l = va_arg(vl, unsigned long);
	if ((data->flag[0] & flag_pre) && (data->flag[2] == 0))
	{
		if (!(*str = ft_strdup("")))
			exit(EXIT_FAILURE);
	}
	else if (!(*str = ft_lltoa_base(specifier.l, 16)))
	{
		if (!(*str = ft_lltoa_base(specifier.l, 16)))
			exit(EXIT_FAILURE);
	}
	len_arg = ft_strlen(*str);
	data->flag[0] &= (data->flag[0] & flag_plus) ? ~flag_plus : data->flag[0];
	data->flag[0] &= (data->flag[0] & flag_hash) ? ~flag_hash : data->flag[0];
	data->flag[0] &= (data->flag[0] & flag_space) ? ~flag_space : data->flag[0];
	(data->flag[0] & flag_zero) ? data->flag[0] |= flag_neg : data->flag[0];
	if (!(data->str_prefix = ft_strdup("0x")))
		exit(EXIT_FAILURE);
	data->val_prefix = 2;
	return (len_arg);
}

int		spec_u(t_printf *data, va_list vl, t_type specifier, char **str)
{
	specifier.ul = va_arg(vl, unsigned long int);
	apply_modifier_unsigned(data, &specifier);
	if ((data->flag[0] & flag_pre) && (data->flag[2] == 0) && !(specifier.l))
	{
		if (!(*str = ft_strdup("")))
			exit(EXIT_FAILURE);
	}
	else if (data->flag[0] & flag_l || (data->flag[0] & flag_z)
		|| (data->flag[0] & flag_j))
	{
		if (!(*str = ft_ulltoa_base(specifier.ul, 10)))
			exit(EXIT_FAILURE);
	}
	else
	{
		if (!(*str = ft_ulltoa_base(specifier.u, 10)))
			exit(EXIT_FAILURE);
	}
	if ((data->flag[0] & flag_pre) && (data->flag[2] <= (int)ft_strlen(*str)))
		data->flag[0] &= ~flag_pre;
	data->flag[0] &= (data->flag[0] & flag_hash) ? ~flag_hash : data->flag[0];
	data->flag[0] &= (data->flag[0] & flag_pre) ? ~flag_zero : data->flag[0];
	data->flag[0] &= (data->flag[0] & flag_space) ? ~flag_space : data->flag[0];
	return (ft_strlen(*str));
}
