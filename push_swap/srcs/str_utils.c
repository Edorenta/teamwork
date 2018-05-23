/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyildiz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 05:11:42 by jyildiz-          #+#    #+#             */
/*   Updated: 2018/05/23 18:03:08 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			scmp(const char *s1, const char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		++s1;
		++s2;
	}
	return (*s1 - *s2);
}

int			pstr(int fd, const char *s, char end)
{
	char *p;

	p = (char *)s;
	*s ? write(fd, s, slen(p)) : 0;
	return (write(fd, &end, 1) ? 1 : 0);
}

int			plong(int fd, long n, char end)
{
	char	str[16];
	int		i;

	n < 0 ? write(fd, "-", 1) : 0;
	n = (n < 0 ? -n : n);
	i = 15;
	str[i--] = '\0';
	n == 0 ? str[--i] = '0' : 0;
	while (n != 0 && (str[--i] = '0' + (n % 10)))
		n /= 10;
	while (i > 0)
		str[--i] = '\0';
	write(fd, &str, 15);
	write(fd, &end, 1);
	return (1);
}

int			scat(char *dest, const char *src, const char c)
{
	int i;

	i = -1;
	while (src[++i] != '\0')
		dest[i] = src[i];
	dest[i] = c;
	dest[++i] = '\0';
	return (1);
}
