/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 17:39:54 by jjourne           #+#    #+#             */
/*   Updated: 2017/01/25 17:39:56 by jjourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	char		*ns;

	if (!s)
		return (0);
	i = 0;
	ns = ft_strnew(len);
	if (ns == NULL)
		return (NULL);
	while (i < len)
	{
		ns[i] = s[i + start];
		++i;
	}
	ns[i] = '\0';
	return (ns);
}
