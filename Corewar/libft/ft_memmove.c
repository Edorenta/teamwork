/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 08:52:27 by jjourne           #+#    #+#             */
/*   Updated: 2017/01/28 19:50:46 by jjourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t i;

	if (src < dest)
	{
		i = n;
		while (i > 0)
		{
			--i;
			((unsigned char*)dest)[i] = ((unsigned char*)src)[i];
		}
	}
	else
	{
		i = 0;
		while (i < n)
		{
			((unsigned char*)dest)[i] = ((unsigned char*)src)[i];
			++i;
		}
	}
	return (dest);
}
