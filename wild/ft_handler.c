/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyildiz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 11:31:07 by jyildiz-          #+#    #+#             */
/*   Updated: 2018/02/15 18:56:10 by jyildiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_flags(const char *format, t_arg *tmp)
{
	int	i;

	i = 0;
	while (format[i] == '-' || format[i] == '+' || format[i] == ' '
			|| format[i] == '0' || format[i] == '#')
	{
		if (format[i] == '-')
			tmp->minus = 1;
		if (format[i] == '+')
			tmp->plus = 1;
		if (format[i] == ' ')
			tmp->space = 1;
		if (format[i] == '0')
			tmp->zero = 1;
		if (format[i] == '#')
			tmp->hash = 1;
		if (tmp->minus)
			tmp->zero = 0;
		i++;
	}
	return (i);
}

int			ft_width(const char *format, va_list va, t_arg *tmp)
{
	int	i;

	i = 0;
	if (ft_isdigit(format[i]))
		tmp->width = ft_atoi(&format[i]);
	else if (format[i] == '*')
	{
		tmp->width = va_arg(va, int);
		i++;
	}
	while (ft_isdigit(format[i]))
		i++;
	return (i);
}

int			ft_precision(const char *format, va_list va, t_arg *tmp)
{
	int	i;

	i = 0;
	if (format[i] == '.')
	{
		if (tmp->zero != 0)
			tmp->zero = -1;
		i++;
		tmp->precision = 0;
		if (format[i] == '*')
		{
			tmp->precision = va_arg(va, int);
			i++;
		}
		else
		{
			tmp->precision = ft_atoi(&format[i]);
			while (ft_isdigit(format[i]))
				i++;
		}
	}
	return (i);
}

int			ft_length(const char *format, t_arg *tmp)
{
	int	i;

	i = 0;
	if (format[i] == 'h' && format[i + 1] == 'h')
	{
		tmp->tab[0] = format[i];
		tmp->tab[1] = format[i];
		i += 2;
	}
	else if (format[i] == 'l' && format[i + 1] == 'l')
	{
		tmp->tab[0] = format[i];
		tmp->tab[1] = format[i];
		i += 2;
	}
	else if (format[i] == 'h' || format[i] == 'l' || format[i] == 'z'
			|| format[i] == 'j')
	{
		tmp->tab[0] = format[i];
		i++;
	}
	return (i);
}
