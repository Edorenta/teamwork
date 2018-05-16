/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyildiz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 05:11:42 by jyildiz-          #+#    #+#             */
/*   Updated: 2018/05/15 18:03:34 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			is_space(const char c)
{
	return ((c < 14 && c > 7) || c == 32);
}

int			is_digit(const char c)
{
	return ((c >= '0' && c <= '9') ? 1 : 0);
}

int			slen(char *s)
{
	return (*s ? slen(++s) + 1 : 0);
}

int			pstr(const char *s)
{
	char *p;

	p = (char *)s;
	*s ? write(1, s, slen(p)) : 0;
	return (write(1, "\n", 1) ? 1 : 0);
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