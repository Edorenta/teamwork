/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 20:11:20 by msicot            #+#    #+#             */
/*   Updated: 2017/11/15 20:23:20 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (needle[0] == 0)
		return ((char*)(haystack));
	while (i < len && haystack[i])
	{
		j = 0;
		while (needle[j] == haystack[i + j] && haystack[i + j] && (i + j) < len)
			j++;
		if (needle[j] == 0)
			return ((char*)(haystack + i));
		i++;
	}
	return (NULL);
}
