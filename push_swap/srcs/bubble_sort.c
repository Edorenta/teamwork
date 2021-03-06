/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 19:16:47 by pde-rent          #+#    #+#             */
/*   Updated: 2018/06/07 19:17:56 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		bb_sort(long *pile, int start, int end)
{
	int		i;
	int		j;
	int		min;
	int		tmp;

	i = start - 1;
	while (++i < end)
	{
		min = pile[i];
		tmp = i;
		j = i + 1;
		while (j <= end)
		{
			if (min > pile[j])
			{
				min = pile[j];
				tmp = j;
			}
			j++;
		}
		pile[tmp] = pile[i];
		pile[i] = min;
	}
	return (is_sort(pile, start, end) ? 1 : 0);
}
