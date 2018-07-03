/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyildiz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 11:20:06 by jyildiz-          #+#    #+#             */
/*   Updated: 2018/02/15 18:54:46 by jyildiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_wdth(t_arg *tmp, t_buf **buf, int ret)
{
	int	i;

	i = 0;
	while (i < tmp->width - ret)
	{
		if (tmp->zero == 0)
			write(1, " ", 1);
		else
			write(1, "0", 1);
		i++;
		(*buf)->nbchar++;
	}
}

static void		fill_conv_c(t_arg *tmp, t_buf **buf, wchar_t wc, int ret)
{
	if (tmp->minus == 1)
	{
		ft_putstr((*buf)->buffer);
		(*buf)->nbchar += (*buf)->index;
		reboot_buf(buf);
		if (tmp->tab[0] == 'l')
			ft_putwchar(wc, ret);
		else
			ft_putchar((char)wc);
		ft_wdth(tmp, buf, ret);
	}
	else
	{
		ft_putstr((*buf)->buffer);
		(*buf)->nbchar += (*buf)->index;
		reboot_buf(buf);
		ft_wdth(tmp, buf, ret);
		if (tmp->tab[0] == 'l')
			ft_putwchar(wc, ret);
		else
			ft_putchar((char)wc);
	}
}

int				ft_conv_c(t_arg *tmp, t_buf **buf)
{
	wchar_t		wc;
	int			ret;

	if (tmp->tab[0] == 'l')
	{
		wc = va_arg((*buf)->va, wchar_t);
		if ((ret = nb_wchar(wc)) == -1)
			return (-1);
	}
	else
	{
		wc = (char)va_arg((*buf)->va, int);
		ret = 1;
	}
	fill_conv_c(tmp, buf, wc, ret);
	(*buf)->nbchar += ret;
	return (1);
}
