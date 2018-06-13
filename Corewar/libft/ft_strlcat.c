/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourne <jjourne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 17:37:17 by jjourne           #+#    #+#             */
/*   Updated: 2017/01/29 20:35:36 by jjourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t i;
	size_t j;
	size_t lendest;

	lendest = 0;
	while (dest[lendest] && lendest < size)
		lendest++;
	j = 0;
	i = lendest;
	while (src[j] && (j + lendest + 1) < size)
	{
		dest[i] = src[j];
		++j;
		++i;
	}
	if (lendest - size > 0)
		dest[i] = '\0';
	return (lendest + ft_strlen(src));
}
