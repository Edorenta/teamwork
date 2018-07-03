/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyildiz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 15:21:13 by jyildiz-          #+#    #+#             */
/*   Updated: 2018/02/15 18:55:52 by jyildiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_loop2(t_arg tmp, t_buf **buf, char *c)
{
	if (c == NULL)
		c = "(null)";
	if (tmp.precision == -1)
		while (*c)
		{
			ft_putchar(*c);
			(*buf)->nbchar++;
			c++;
		}
	else
		while (*c && tmp.precision > 0)
		{
			tmp.precision = tmp.precision - 1;
			ft_putchar(*c);
			(*buf)->nbchar++;
			c++;
		}
}

static int		ft_loop(t_arg tmp, t_buf **buf, wchar_t *wc, int ret)
{
	if (wc == NULL)
		ft_loop2(tmp, buf, NULL);
	else if (tmp.precision == -1)
		while (*wc)
		{
			if ((ret = nb_wchar(*wc)) == -1)
				return (-1);
			ft_putwchar(*wc, ret);
			(*buf)->nbchar += ret;
			wc++;
		}
	else
		while (*wc && tmp.precision > 0)
		{
			if ((ret = nb_wchar(*wc)) == -1)
				return (-1);
			if (tmp.precision - ret < 0)
				break ;
			tmp.precision = tmp.precision - ret;
			ft_putwchar(*wc, ret);
			(*buf)->nbchar += ret;
			wc++;
		}
	return (1);
}

void			ft_wdth_s(t_arg *tmp, t_buf **buf, int ret)
{
	int		i;

	if (tmp->precision >= 0)
		if (ret > tmp->precision)
			ret = tmp->precision;
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

static int		ft_fill(t_arg *tmp, t_buf **buf, wchar_t *wc, int ret)
{
	if (tmp->minus == 1)
	{
		fill_conv_s(buf, tmp, ret);
		if (tmp->tab[0] == 'l')
		{
			if ((ft_loop(*tmp, buf, wc, ret)) == -1)
				return (-1);
		}
		else
			ft_loop2(*tmp, buf, (char*)wc);
		ft_wdth_s(tmp, buf, ret);
	}
	else
	{
		fill_conv_s(buf, tmp, ret);
		if (tmp->tab[0] == 'l')
		{
			if ((ft_loop(*tmp, buf, wc, ret)) == -1)
				return (-1);
		}
		else
			ft_loop2(*tmp, buf, (char*)wc);
	}
	return (0);
}

int				ft_conv_s(t_arg *tmp, t_buf **buf)
{
	wchar_t		*wc;
	int			ret;

	if (tmp->tab[0] == 'l')
	{
		wc = va_arg((*buf)->va, wchar_t*);
		if (wc != NULL)
		{
			if (test_strwchar(wc, tmp->precision) == -1)
				return (-1);
			ret = nb_strwchar(wc, tmp->precision);
		}
	}
	else
	{
		wc = va_arg((*buf)->va, int*);
		if (wc != NULL)
			ret = ft_strlen((char *)wc);
	}
	if (wc == NULL)
		ret = 6;
	if (ft_fill(tmp, buf, wc, ret) == -1)
		return (-1);
	return (1);
}
