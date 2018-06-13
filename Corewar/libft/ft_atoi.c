/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourne <jjourne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 02:40:20 by jjourne           #+#    #+#             */
/*   Updated: 2017/01/30 19:24:29 by jjourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *nptr)
{
	int	i;
	int	r;
	int	signe;

	i = 0;
	r = 0;
	signe = 1;
	while (ft_isspace(nptr[i]))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			signe = -1;
		i++;
	}
	while (nptr[i] && ft_isdigit(nptr[i]))
	{
		r = (r * 10) + (nptr[i] - '0');
		i++;
	}
	return (r * signe);
}
