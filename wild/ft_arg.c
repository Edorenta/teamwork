/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyildiz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 11:39:19 by jyildiz-          #+#    #+#             */
/*   Updated: 2018/02/15 18:56:43 by jyildiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_type2(char c, t_arg *tmp, t_buf **buf)
{
	if (c == 'U')
	{
		tmp->tab[0] = 'l';
		ft_conv_u(tmp, buf);
	}
	else if (c == 'x' || c == 'X')
		ft_conv_x(tmp, buf, c);
	else if (c == 'c')
		return (ft_conv_c(tmp, buf));
	else if (c == 'C')
	{
		tmp->tab[0] = 'l';
		return (ft_conv_c(tmp, buf));
	}
	else if (c == 's')
		return (ft_conv_s(tmp, buf));
	else
		return (0);
	return (1);
}

static int	ft_type3(char c, t_arg *tmp, t_buf **buf)
{
	if (c == 'p')
	{
		tmp->tab[0] = 'l';
		tmp->tab[1] = 'l';
		tmp->hash = 1;
		ft_conv_x(tmp, buf, c);
	}
	else if (c == 'S')
	{
		tmp->tab[0] = 'l';
		return (ft_conv_s(tmp, buf));
	}
	else if (c == '%')
		ft_conv_per(tmp, buf);
	else if (c == 'u')
		ft_conv_u(tmp, buf);
	else
		return (0);
	return (1);
}

static int	ft_type(char c, t_arg *tmp, t_buf **buf)
{
	int ret;

	ret = 0;
	tmp->conv = c;
	if (c == 'd' || c == 'i')
		ft_conv_d(tmp, buf);
	else if (c == 'D')
	{
		tmp->tab[0] = 'l';
		tmp->tab[1] = '0';
		ft_conv_d(tmp, buf);
	}
	else if (c == 'o')
		ft_conv_o(tmp, buf);
	else if (c == 'O')
	{
		tmp->tab[0] = 'l';
		ft_conv_o(tmp, buf);
	}
	else if ((ret = ft_type2(c, tmp, buf)) != 0)
		return (ret);
	else if ((ret = ft_type3(c, tmp, buf)) != 0)
		return (ret);
	return (1);
}

static void	test_zero(t_buf **buf, t_arg *tmp, int index)
{
	if (tmp->zero == -1 && (*buf)->format[index] == '%')
		tmp->zero = 1;
	else if (tmp->zero == -1)
		tmp->zero = 0;
}

int			ft_arg(t_buf **buf, int index)
{
	int		i;
	t_arg	*tmp;
	int		bug;

	if ((tmp = malloc(sizeof(t_arg) * 1)) == NULL)
		return (-1);
	init_arg(tmp);
	i = index;
	i += ft_flags(&((*buf)->format[i]), tmp);
	i += ft_width(&((*buf)->format[i]), (*buf)->va, tmp);
	i += ft_precision(&((*buf)->format[i]), (*buf)->va, tmp);
	i += ft_length(&((*buf)->format[i]), tmp);
	test_zero(buf, tmp, i);
	if ((bug = ft_type((*buf)->format[i], tmp, buf)) == -1)
		i = -1;
	else
	{
		ft_putstr((*buf)->buffer);
		(*buf)->nbchar += (*buf)->index;
		reboot_buf(buf);
		i++;
	}
	free(tmp);
	return (i);
}
