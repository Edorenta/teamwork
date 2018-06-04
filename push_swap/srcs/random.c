/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 18:33:13 by fmadura           #+#    #+#             */
/*   Updated: 2018/06/04 18:33:14 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static unsigned long int g_next = 1;

/*
** RAND_MAX assumed to be 32767, as with rand() srand()
*/

void	seed(void)
{
	size_t *x;
	size_t a_seed;
	size_t seed;

	a_seed = (size_t)&x;
	seed = (a_seed %= 1111);
	srand(seed);
}

int		rnd(void)
{
	g_next = g_next * 1103515245 + 12345;
	return (unsigned int)(g_next / 65536) % 32768;
}

void	srnd(unsigned int seed)
{
	g_next = seed;
}
