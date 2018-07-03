/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 09:26:54 by msicot            #+#    #+#             */
/*   Updated: 2017/11/16 13:44:23 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t len;
	size_t j;

	len = 0;
	j = 0;
	len = ft_strlen(dst);
	if (len >= size)
		return (ft_strlen(src) + size);
	while (src[j] && j < (size - len - 1))
	{
		dst[len + j] = src[j];
		j += 1;
	}
	dst[len + j] = '\0';
	return (ft_strlen(src) + len);
}
