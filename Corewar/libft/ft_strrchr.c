/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourne <jjourne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 17:39:21 by jjourne           #+#    #+#             */
/*   Updated: 2017/01/30 13:23:16 by jjourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int i;

	i = ft_strlen(s);
	if ((char)c == '\0')
		return ((char*)s + i);
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char*)s + i);
		--i;
	}
	return (NULL);
}
