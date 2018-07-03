/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 18:00:59 by msicot            #+#    #+#             */
/*   Updated: 2017/11/16 13:51:17 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	size_t	i;
	char	*t;

	i = 0;
	if (!(t = (char*)malloc((sizeof(char) * (size + 1)))))
		return (NULL);
	while (i < size)
	{
		*(t + i) = '\0';
		i++;
	}
	t[i] = 0;
	return (t);
}
