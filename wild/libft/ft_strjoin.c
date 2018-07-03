/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 09:21:47 by msicot            #+#    #+#             */
/*   Updated: 2017/11/15 19:02:24 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_joint(char const *s1, char const *s2, char *t)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[j])
	{
		t[j] = s1[j];
		j++;
	}
	i = 0;
	while (s2[i])
	{
		t[j] = s2[i];
		i++;
		j++;
	}
	t[j] = 0;
	return (t);
}

char			*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*t;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		i++;
	while (s2[j])
	{
		i++;
		j++;
	}
	if (!(t = malloc(i + 1)))
		return (NULL);
	return (ft_joint(s1, s2, t));
}
