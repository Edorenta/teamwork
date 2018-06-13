/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourne <jjourne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 01:43:35 by jjourne           #+#    #+#             */
/*   Updated: 2018/04/10 04:06:53 by jjourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	del_list(t_result *lst)
{
	t_result *tmp;

	tmp = lst;
	while (tmp)
	{
		tmp = tmp->next;
		ft_memdel((void **)&lst);
		lst = tmp;
	}
	ft_memdel((void **)&tmp);
}

void	add_to_result(t_printf *data, char c, int flag)
{
	t_result *new;

	if ((data->result_i == 0) || (data->result_i == BUF_SIZE))
	{
		if (!(new = (t_result*)ft_memalloc(sizeof(t_result))))
			exit(EXIT_FAILURE);
		if (data->result_i == 0)
			data->result_start = new;
		else if (!(data->result_i = 0))
			data->result_end->next = new;
		data->result_end = new;
		new->next = NULL;
	}
	if (flag == 0)
		data->result_end->buf[data->result_i] = data->format[data->format_i];
	else if (flag == 2)
		data->result_end->buf[data->result_i] = '\0';
	else
		data->result_end->buf[data->result_i] = c;
	++(data->result_i);
	++(data->len_final);
}

void	add_str_to_result(t_printf *data, char *str, int flag)
{
	int i;

	i = -1;
	while (str[++i])
		add_to_result(data, str[i], flag);
}

void	put_n_char_to_result(t_printf *data, char c, int n)
{
	int i;

	i = -1;
	while (++i < n)
		add_to_result(data, c, 1);
}

int		ft_printf(const char *format, ...)
{
	va_list		vl;
	t_printf	data;
	t_result	*curr;

	ft_bzero(&data, sizeof(data));
	if (!(data.format = ft_strdup(format)))
		exit(EXIT_FAILURE);
	data.format_i = -1;
	va_start(vl, format);
	ft_printf_parser(&data, vl);
	va_end(vl);
	curr = data.result_start;
	while (curr)
	{
		if (curr->next == NULL)
			write(1, curr, data.result_i);
		else
			write(1, curr, BUF_SIZE);
		curr = curr->next;
	}
	ft_memdel((void **)&(data.format));
	del_list(data.result_start);
	return (data.len_final);
}
