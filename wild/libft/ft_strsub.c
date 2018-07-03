/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 09:08:59 by msicot            #+#    #+#             */
/*   Updated: 2017/11/14 16:37:34 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*t;
	size_t	i;

	if (s == NULL)
		return (NULL);
	i = 0;
	if (!(t = malloc(len + 1)))
		return (NULL);
	while (i < len)
	{
		t[i] = s[start + i];
		i++;
	}
	t[i] = 0;
	return (t);
}
