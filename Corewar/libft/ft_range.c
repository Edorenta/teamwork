/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourne <jjourne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 18:23:55 by jjourne           #+#    #+#             */
/*   Updated: 2017/01/30 18:33:09 by jjourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*ft_range(int min, int max)
{
	int c;
	int *t;

	if (max < min || max == min)
		return (0);
	c = 0;
	t = malloc((max - min) * sizeof(int));
	if (t == NULL)
		return (0);
	while (min < max)
	{
		t[c] = min;
		c++;
		min++;
	}
	return (t);
}
