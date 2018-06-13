/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourne <jjourne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 03:20:52 by jjourne           #+#    #+#             */
/*   Updated: 2017/01/29 21:37:34 by jjourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	if (n == 0)
		return (0);
	i = 1;
	while (*s1 && *s1 == *s2 && i < n)
	{
		s1++;
		s2++;
		i++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
