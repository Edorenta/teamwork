/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 12:02:25 by msicot            #+#    #+#             */
/*   Updated: 2017/11/13 16:22:57 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	u;

	u = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (*(unsigned char*)(s + i) == u)
			return ((unsigned char*)(s + i));
		i++;
	}
	return (NULL);
}
