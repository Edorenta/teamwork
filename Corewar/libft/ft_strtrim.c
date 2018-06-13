/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 17:40:02 by jjourne           #+#    #+#             */
/*   Updated: 2017/01/25 18:59:55 by jjourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	istrimspace(int c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	return (0);
}

char		*ft_strtrim(const char *s)
{
	char	*st;
	int		i;
	int		j;

	if (!s)
		return (0);
	i = 0;
	j = ft_strlen(s);
	while (istrimspace(s[i]))
		++i;
	while (istrimspace(s[j - 1]))
		--j;
	if (j < i)
		j = i;
	st = ft_strnew(j - i);
	if (st == NULL)
		return (NULL);
	st = ft_strncpy(st, s + i, j - i);
	return (st);
}
