/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyildiz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 16:34:58 by jyildiz-          #+#    #+#             */
/*   Updated: 2018/02/15 18:56:52 by jyildiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*fill_conv_d(intmax_t nb)
{
	uintmax_t	nbr;
	char		*str;

	if (nb < 0)
	{
		nbr = -nb;
		str = ft_itoa_base(nbr, 10, -1);
	}
	else
	{
		nbr = nb;
		str = ft_itoa_base(nbr, 10, 1);
	}
	return (str);
}

void	ft_conv_d(t_arg *tmp, t_buf **buf)
{
	char		*str;
	char		*ptr;
	intmax_t	nb;

	nb = ft_con_d(tmp, buf);
	str = fill_conv_d(nb);
	ptr = str;
	if (nb < 0)
		str = &str[1];
	fill_conv_d2(tmp, buf, nb, str);
	free(ptr);
}

void	fill_conv_x(intmax_t nb, t_arg *tmp, t_buf **buf, char c)
{
	if (tmp->hash == 1 && (tmp->precision != 0 || nb != 0))
	{
		if (nb == 0 && c != 'p')
			ft_strnconcat(buf, "0", 1);
		else if (c == 'x' || c == 'p')
			ft_strnconcat(buf, "0x", 2);
		else
			ft_strnconcat(buf, "0X", 2);
	}
}

void	fill_conv_x2(intmax_t nb, t_arg *tmp, t_buf **buf, char *str)
{
	if (tmp->conv == 'p' || nb != 0 || (tmp->precision != 0 && tmp->hash != 1))
		ft_strnconcat(buf, str, ft_strlen(str));
}

void	fill_conv_s(t_buf **buf, t_arg *tmp, int ret)
{
	ft_putstr((*buf)->buffer);
	(*buf)->nbchar += (*buf)->index;
	reboot_buf(buf);
	if (tmp->minus != 1)
		ft_wdth_s(tmp, buf, ret);
}
