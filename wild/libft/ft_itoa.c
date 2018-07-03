/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 09:04:55 by msicot            #+#    #+#             */
/*   Updated: 2017/11/16 14:19:19 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_fill2(long nb, int j, char *s, char c)
{
	if (s == NULL)
		return (NULL);
	if (c == '-')
		s[0] = '-';
	s[j] = '\0';
	j--;
	if (nb == 0)
		s[0] = nb + '0';
	while (nb != 0)
	{
		if (nb % 10 == 0)
		{
			s[j] = (nb % 10) + '0';
			nb = nb / 10;
			j--;
		}
		else
		{
			s[j] = nb % 10 + '0';
			nb = nb / 10;
			j--;
		}
	}
	return (s);
}

char		*ft_itoa(int n)
{
	char	*s;
	long	nb;
	int		j;
	char	c;

	nb = n;
	j = 1;
	if (nb < 0)
	{
		nb = nb * -1;
		j++;
		c = '-';
	}
	while (n / 10 != 0)
	{
		n = n / 10;
		j++;
	}
	if (!(s = ft_fill2(nb, j, ft_strnew(j), c)))
		return (NULL);
	return (s);
}
