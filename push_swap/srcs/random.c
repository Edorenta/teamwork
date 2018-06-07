/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 19:40:01 by fmadura           #+#    #+#             */
/*   Updated: 2018/06/07 17:47:56 by fmadura          ###   ########.fr       */
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
		g_next = (unsigned int)rnd_((int)&g_next);
	g_next = rnd_(g_next);
	return (g_next);
}
