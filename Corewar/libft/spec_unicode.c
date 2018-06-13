/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_unicode.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourne <jjourne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 04:45:51 by jjourne           #+#    #+#             */
/*   Updated: 2018/04/10 05:45:23 by jjourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		put_unicode(wchar_t wchar, char **str, int *i)
{
	int s;

	s = *i;
	if ((wchar <= 0x7f))
		(*str)[*i] = wchar;
	else if (wchar <= 0x7ff)
	{
		(*str)[*i] = (wchar >> 6) + 0xC0;
		(*str)[++(*i)] = (wchar & 0x3F) + 0x80;
	}
	else if (wchar <= 0xffff)
	{
		(*str)[*i] = (wchar >> 12) + 0xE0;
		(*str)[++(*i)] = ((wchar >> 6) & 0x3F) + 0x80;
		(*str)[++(*i)] = (wchar & 0x3F) + 0x80;
	}
	else
	{
		(*str)[*i] = (wchar >> 18) + 0xF0;
		(*str)[++(*i)] = ((wchar >> 12) & 0x3F) + 0x80;
		(*str)[++(*i)] = ((wchar >> 6) & 0x3F) + 0x80;
		(*str)[++(*i)] = (wchar & 0x3F) + 0x80;
	}
	return (*i - s);
}

int		unicode_len(wchar_t *uni_str, int *byte_len)
{
	wchar_t *asd;

	asd = uni_str;
	while (*uni_str != 0)
	{
		if (*uni_str <= 0x7f)
			*byte_len += 1;
		else if (*uni_str <= 0x7ff)
			*byte_len += 2;
		else if (*uni_str <= 0xffff)
			*byte_len += 3;
		else
			*byte_len += 4;
		uni_str++;
	}
	return (uni_str - asd);
}

int		spec_lc(t_printf *data, va_list vl, t_type specifier, char **str)
{
	int i;

	i = 0;
	specifier.lc = va_arg(vl, wchar_t);
	if (!(*str = ft_strnew(4)))
		exit(EXIT_FAILURE);
	put_unicode(specifier.lc, str, &i);
	data->flag[0] &= (data->flag[0] & flag_plus) ? ~flag_plus : data->flag[0];
	data->flag[0] &= (data->flag[0] & flag_hash) ? ~flag_hash : data->flag[0];
	data->flag[0] &= (data->flag[0] & flag_space) ? ~flag_space : data->flag[0];
	return (ft_strlen(*str));
}

int		spec_ls(t_printf *data, va_list vl, t_type specifier, char **str)
{
	int uni_len;

	uni_len = 0;
	specifier.ls = va_arg(vl, wchar_t*);
	if (specifier.ls == NULL)
	{
		if (!(*str = ft_strdup("(null)")))
			exit(EXIT_FAILURE);
	}
	else
		spec_ls_no_null(data, specifier, str, uni_len);
	data->flag[0] &= (data->flag[0] & flag_plus) ? ~flag_plus : data->flag[0];
	data->flag[0] &= (data->flag[0] & flag_hash) ? ~flag_hash : data->flag[0];
	data->flag[0] &= (data->flag[0] & flag_space) ? ~flag_space : data->flag[0];
	if ((data->flag[0] & flag_pre) && (data->flag[2] >= uni_len))
		data->flag[0] &= ~flag_pre;
	return (ft_strlen(*str));
}

int		spec_ls_no_null(t_printf *data, t_type specifier, char **str,
	int uni_len)
{
	int		i;
	int		j;
	int		z;
	int		uni_byte_len;

	i = 0;
	j = 0;
	uni_byte_len = 0;
	uni_len = unicode_len(specifier.ls, &uni_byte_len);
	if (!(*str = ft_strnew(uni_len * 4)))
		exit(EXIT_FAILURE);
	while (j < uni_len)
	{
		z = i;
		put_unicode((specifier.ls)[j], str, &i);
		if ((data->flag[0] & flag_pre) && (i >= data->flag[2]))
		{
			str[0][z] = 0;
			break ;
		}
		++i;
		++j;
	}
	return (uni_len);
}
