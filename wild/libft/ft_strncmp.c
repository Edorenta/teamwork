/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 20:56:39 by msicot            #+#    #+#             */
/*   Updated: 2017/11/15 11:26:21 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		nb;

	i = 0;
	nb = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && i < n)
		i++;
	if (s1[i] != s2[i] && i < n)
		nb = (unsigned char)s1[i] - (unsigned char)s2[i];
	return (nb);
}
