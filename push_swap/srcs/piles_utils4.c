/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piles_utils4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 19:20:11 by pde-rent          #+#    #+#             */
/*   Updated: 2018/06/07 19:20:13 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_sort_precheck(long *pile, int start, int end)
{
	int		i;

	i = start - 1;
	while (++i < end)
		if (pile[i] > pile[i + 1])
			return (0);
	return (1);
}
