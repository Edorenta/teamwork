/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 16:09:29 by msicot            #+#    #+#             */
/*   Updated: 2017/11/15 19:03:51 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_nblet(char const *s, char c, char **tab)
{
	int	i;
	int	j;
	int k;

	i = 0;
	k = 0;
	while (s[i] != 0)
	{
		j = 0;
		while (s[i] == c && s[i] != 0)
			i++;
		while (s[i] != c && s[i] != 0)
		{
			i++;
			j++;
		}
		if (j > 0)
		{
			if (!(tab[k] = (char*)malloc(sizeof(char) * (j + 1))))
				return (NULL);
			k++;
		}
	}
	return (tab);
}

static int	ft_nbmots(char const *s, char c)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (s[i] != 0)
	{
		while (s[i] == c && s[i] != 0)
			i++;
		if (s[i] != c && s[i] != 0)
		{
			j++;
			while (s[i] != c && s[i] != 0)
				i++;
		}
	}
	return (j);
}

static void	ft_fill(char const *s, char c, char **tab)
{
	int	i;
	int k;
	int j;

	j = 0;
	i = 0;
	k = 0;
	while (s[i] != 0 && k < ft_nbmots(s, c))
	{
		j = 0;
		while (s[i] == c && s[i] != 0)
			i++;
		while (s[i] != c && s[i] != 0)
		{
			tab[k][j] = s[i];
			i++;
			j++;
		}
		tab[k][j] = '\0';
		k++;
	}
	tab[k] = 0;
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;

	if (s == NULL)
		return (NULL);
	if (!(tab = (char**)malloc(sizeof(char*) * (ft_nbmots(s, c) + 1))))
		return (NULL);
	tab = ft_nblet(s, c, tab);
	ft_fill(s, c, tab);
	return (tab);
}
