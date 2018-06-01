/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rnd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 17:17:01 by fmadura           #+#    #+#             */
/*   Updated: 2018/05/29 17:18:39 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static unsigned long int next = 1; 

/*
 * RAND_MAX assumed to be 32767, as with rand() srand()
 */

int		rnd(void)
{ 
    next = next * 1103515245 + 12345; 
    return (unsigned int)(next/65536) % 32768; 
} 

void	srnd(unsigned int seed) 
{ 
    next = seed;
}
