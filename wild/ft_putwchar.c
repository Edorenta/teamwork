/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyildiz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 12:34:24 by jyildiz-          #+#    #+#             */
/*   Updated: 2018/02/15 18:56:26 by jyildiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			test_strwchar(wchar_t *c, int b)
{
	int		ok;
	int		ret;
	wchar_t	*tmp;

	tmp = c;
	ok = 1;
	if (b == -1)
		b = 100000;
	while (*tmp && b > 0)
	{
		if ((ret = nb_wchar(*tmp)) == -1)
			ok = -1;
		b -= ret;
		tmp++;
	}
	return (ok);
}

int			nb_strwchar(wchar_t *c, int b)
{
	int ret;
	int nb;

	nb = 0;
	if (b == -1)
		b = 100000;
	while (*c && b > 0)
	{
		ret = nb_wchar(*c);
		if ((b = b - ret) < 0)
			break ;
		nb += ret;
		c++;
	}
	return (nb);
}

int			nb_wchar(wchar_t c)
{
	if ((c >= 0xD800 && c <= 0xDBFF) || (c >= 0xDC00 && c <= 0xDFFF))
		return (-1);
	if (c < 0 || c > 0x10FFFF)
		return (-1);
	if (MB_CUR_MAX == 1 && c > 0x7F && c <= 0xFF)
		return (1);
	else if (MB_CUR_MAX == 1 && c > 0xFF)
		return (-1);
	if (c <= 0x7F)
		return (1);
	else if (c <= 0x7FF)
		return (2);
	else if (c <= 0xFFFF)
		return (3);
	else if (c <= 0x10FFFF)
		return (4);
	return (-1);
}

void		ft_putwchar(wchar_t c, int i)
{
	if (i == 1)
		ft_putchar(c);
	else if (i == 2)
	{
		ft_putchar((c >> 6) + 0xC0);
		ft_putchar((c & 0x3F) + 0x80);
	}
	else if (i == 3)
	{
		ft_putchar((c >> 12) + 0xE0);
		ft_putchar(((c >> 6) & 0x3F) + 0x80);
		ft_putchar((c & 0x3F) + 0x80);
	}
	else if (i == 4)
	{
		ft_putchar((c >> 18) + 0xF0);
		ft_putchar(((c >> 12) & 0x3F) + 0x80);
		ft_putchar(((c >> 6) & 0x3F) + 0x80);
		ft_putchar((c & 0x3F) + 0x80);
	}
}
