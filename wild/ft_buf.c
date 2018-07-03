/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyildiz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 15:45:28 by jyildiz-          #+#    #+#             */
/*   Updated: 2018/02/15 18:54:38 by jyildiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_arg(t_arg *arg)
{
	arg->minus = 0;
	arg->plus = 0;
	arg->space = 0;
	arg->zero = 0;
	arg->hash = 0;
	arg->width = 0;
	arg->precision = -1;
	arg->tab[0] = '0';
	arg->tab[1] = '0';
	arg->conv = '0';
}

t_buf	*init_buff(va_list va, const char *format)
{
	int		i;
	t_buf	*buff;

	if ((buff = (t_buf*)malloc(sizeof(t_buf) * 1)) == NULL)
		return (NULL);
	if ((buff->buffer = (char *)malloc(sizeof(char) * BUFF_SIZE + 1)) == NULL)
		return (NULL);
	i = 0;
	while (i <= BUFF_SIZE)
	{
		buff->buffer[i] = '\0';
		i++;
	}
	buff->nbchar = 0;
	buff->index = 0;
	va_copy(buff->va, va);
	buff->format = format;
	return (buff);
}

void	reboot_buf(t_buf **buf)
{
	int i;

	i = 0;
	(*buf)->index = 0;
	while (i <= BUFF_SIZE)
	{
		(*buf)->buffer[i] = '\0';
		i++;
	}
}

void	ft_strnconcat(t_buf **buf, const char *src, int nb)
{
	int	j;

	j = 0;
	while (src[j] && j < nb)
	{
		if ((*buf)->index == BUFF_SIZE - 1)
		{
			ft_putstr((*buf)->buffer);
			reboot_buf(buf);
			ft_strnconcat(buf, &src[j], nb - j);
			(*buf)->nbchar += BUFF_SIZE;
		}
		(*buf)->buffer[(*buf)->index] = src[j];
		(*buf)->index++;
		j++;
	}
	(*buf)->buffer[(*buf)->index] = '\0';
}
