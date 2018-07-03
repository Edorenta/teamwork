/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 18:38:28 by msicot            #+#    #+#             */
/*   Updated: 2017/11/14 16:01:35 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	long i;
	char *t;

	if (s == NULL)
		return (NULL);
	i = 0;
	while (s[i])
		i++;
	if (!(t = malloc(i + 1)))
		return (NULL);
	i = 0;
	while (s[i])
	{
		t[i] = f(s[i]);
		i++;
	}
	t[i] = 0;
	return (t);
}
