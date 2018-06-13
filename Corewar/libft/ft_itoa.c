/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 17:30:43 by jjourne           #+#    #+#             */
/*   Updated: 2017/01/27 17:34:51 by jjourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long int		ifneg(long int ln, int *f)
{
	if (ln < 0)
	{
		*f = 1;
		ln = -ln;
	}
	else
		*f = 0;
	return (ln);
}

static char			*sizemallocstr(char *s, long int ln, int f, int base)
{
	while (ln >= 10)
	{
		ln /= 10;
		base++;
	}
	s = ft_strnew(base + f);
	if (s == NULL)
		return (NULL);
	return (s);
}

static char			*conv(char *s, long int ln, int base, int i)
{
	while (base > 0)
	{
		s[i] = ((ln / base) % 10) + '0';
		base /= 10;
		i++;
	}
	s[i] = '\0';
	return (s);
}

char				*ft_itoa(int n)
{
	char		*s;
	int			base;
	int			i;
	int			f;
	long int	ln;

	i = 0;
	ln = n;
	base = 1;
	s = NULL;
	ln = ifneg(ln, &f);
	s = sizemallocstr(s, ln, f, base);
	if (s == NULL)
		return (NULL);
	if (f == 1)
	{
		s[i] = '-';
		i++;
	}
	while ((ln / base) >= 10)
		base *= 10;
	s = conv(s, ln, base, i);
	return (s);
}
