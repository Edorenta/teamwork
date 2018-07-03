/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 10:56:05 by msicot            #+#    #+#             */
/*   Updated: 2017/11/13 15:36:08 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = 0;
	if (dst < src)
		while (i < len)
		{
			*(char*)(dst + i) = *(char*)(src + i);
			i++;
		}
	else
		while (len--)
			*(char*)(dst + len) = *(char*)(src + len);
	return (dst);
}
