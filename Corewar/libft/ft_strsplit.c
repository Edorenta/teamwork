/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourne <jjourne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 17:39:29 by jjourne           #+#    #+#             */
/*   Updated: 2017/01/30 17:40:17 by jjourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		wordnbr(char const *s, char c)
{
	int i;
	int nw;

	i = 0;
	nw = 0;
	if (s[i] != c && s[i])
		nw++;
	while (s[i])
	{
		if (s[i + 1] && s[i] == c && s[i + 1] != c)
			++nw;
		++i;
	}
	return (nw);
}

static int		wordlen(const char *s, char c)
{
	int i;

	i = 0;
	while (*s != c && *s)
	{
		++s;
		++i;
	}
	return (i);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tabs;
	int		i;
	int		nw;

	if (!(s && c))
		return (0);
	i = 0;
	nw = wordnbr(s, c);
	if (!(tabs = (char**)ft_memalloc(sizeof(char*) * (nw + 1))))
		return (NULL);
	while (i < nw)
	{
		while (*s == c)
			++s;
		tabs[i] = ft_strsub(s, 0, wordlen(s, c));
		s = s + wordlen(s, c);
		++i;
	}
	return (tabs);
}
