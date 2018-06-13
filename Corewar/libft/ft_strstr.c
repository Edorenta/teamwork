/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 17:39:45 by jjourne           #+#    #+#             */
/*   Updated: 2017/01/25 17:39:47 by jjourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (*little == '\0')
		return ((char*)big);
	while (big[i])
	{
		if (big[i] == little[j])
		{
			while (little[j] && big[j + i] == little[j])
				++j;
			if (little[j] == '\0')
				return ((char*)big + i);
			j = 0;
		}
		++i;
	}
	return (NULL);
}
