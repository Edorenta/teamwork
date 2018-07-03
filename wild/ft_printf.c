/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyildiz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 10:40:34 by jyildiz-          #+#    #+#             */
/*   Updated: 2018/02/15 18:57:04 by jyildiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		intern_printf(t_buf *buf)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (buf->format[i])
	{
		if (buf->format[i] == '%')
		{
			ft_strnconcat(&buf, &(buf->format[j]), i - j);
			i++;
			if ((i = ft_arg(&buf, i)) == -1)
				return (-1);
			j = i;
		}
		else
			i++;
	}
	ft_strnconcat(&buf, &(buf->format[j]), i);
	ft_putstr(buf->buffer);
	buf->nbchar += buf->index;
	return (buf->nbchar);
}

int				ft_printf(const char *format, ...)
{
	va_list	va;
	t_buf	*buf;
	int		nbchar;

	va_start(va, format);
	if ((buf = init_buff(va, format)) == NULL)
		return (-1);
	nbchar = intern_printf(buf);
	free(buf->buffer);
	free(buf);
	return (nbchar);
}
