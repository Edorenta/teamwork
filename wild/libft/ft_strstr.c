/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 18:49:41 by msicot            #+#    #+#             */
/*   Updated: 2017/11/15 11:52:05 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int	i;
	int	j;
	int	pos;

	i = 0;
	if (needle[0] == 0)
		return ((char*)(haystack));
	while (haystack[i] != 0)
	{
		j = 0;
		pos = i;
		while (needle[j] == haystack[pos] && needle[j] != 0)
		{
			if (needle[j + 1] == 0 && needle[j] == haystack[pos] && j >= 0)
			{
				return ((char*)(haystack + i));
			}
			j++;
			pos++;
		}
		i++;
	}
	return (NULL);
}
