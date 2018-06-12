/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 19:20:18 by pde-rent          #+#    #+#             */
/*   Updated: 2018/06/07 19:20:20 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long int g_next = -1;

/*
** RAND_MAX assumed to be 32767, as with rand() srand()
*/

static int		rnd_calc(int seed, int increment, int modulus, int multiplier)
{
	return ((multiplier * seed + increment) % modulus);
}

static int		rnd_(int seed)
{
	return (rnd_calc(seed, 1013904223, INT_MAX, 1664525));
}

int				rnd(void)
{
	if (g_next == -1)
		g_next = (size_t)rnd_((size_t)&g_next);
	g_next = rnd_(g_next);
	return (g_next);
}
