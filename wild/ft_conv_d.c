/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyildiz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 11:46:53 by jyildiz-          #+#    #+#             */
/*   Updated: 2018/02/15 18:55:45 by jyildiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_plus(t_arg *tmp, intmax_t nb, t_buf **buf)
{
	if (tmp->plus == 1 && nb >= 0)
		ft_strnconcat(buf, "+", 1);
	else if (tmp->space == 1 && nb >= 0)
		ft_strnconcat(buf, " ", 1);
	if (nb < 0)
		ft_strnconcat(buf, "-", 1);
}

static void	ft_lgt(t_arg *tmp, int nbchar, t_buf **buf)
{
	int	i;

	i = 0;
	while (i < tmp->precision - nbchar)
	{
		ft_strnconcat(buf, "0", 1);
		i++;
	}
}

static void	ft_wdth(t_arg *tmp, t_buf **buf, int nbc, intmax_t nb)
{
	int	i;
	int nbchar;

	i = 0;
	if (tmp->precision < nbc)
		nbchar = nbc;
	else
		nbchar = tmp->precision;
	if (nb < 0)
		nbchar++;
	if (nb >= 0 && (tmp->plus == 1 || tmp->space == 1))
		nbchar++;
	if (nb == 0 && tmp->precision == 0)
		nbchar = 0;
	while (i < tmp->width - nbchar)
	{
		if (tmp->zero == 0)
			ft_strnconcat(buf, " ", 1);
		else
			ft_strnconcat(buf, "0", 1);
		i++;
	}
}

intmax_t	ft_con_d(t_arg *tmp, t_buf **buf)
{
	if (tmp->tab[0] == 'l' && tmp->tab[1] == 'l')
		return (va_arg((*buf)->va, long long int));
	else if (tmp->tab[0] == 'h' && tmp->tab[1] == 'h')
		return ((char)va_arg((*buf)->va, int));
	else if (tmp->tab[0] == 'h')
		return ((short int)va_arg((*buf)->va, int));
	else if (tmp->tab[0] == 'l')
		return (va_arg((*buf)->va, long int));
	else if (tmp->tab[0] == 'z')
		return (va_arg((*buf)->va, size_t));
	else if (tmp->tab[0] == 'j')
		return (va_arg((*buf)->va, intmax_t));
	else
		return (va_arg((*buf)->va, int));
}

void		fill_conv_d2(t_arg *tmp, t_buf **buf, intmax_t nb, char *str)
{
	if (tmp->minus == 1)
	{
		ft_plus(tmp, nb, buf);
		ft_lgt(tmp, ft_strlen(str), buf);
		if (nb != 0 || tmp->precision != 0)
			ft_strnconcat(buf, str, ft_strlen(str));
		ft_wdth(tmp, buf, ft_strlen(str), nb);
	}
	else
	{
		if (tmp->zero == 1)
			ft_plus(tmp, nb, buf);
		ft_wdth(tmp, buf, ft_strlen(str), nb);
		if (tmp->zero == 0)
			ft_plus(tmp, nb, buf);
		ft_lgt(tmp, ft_strlen(str), buf);
		if (nb != 0 || tmp->precision != 0)
			ft_strnconcat(buf, str, ft_strlen(str));
	}
}
