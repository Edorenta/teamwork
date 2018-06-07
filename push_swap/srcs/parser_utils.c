/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 19:19:46 by pde-rent          #+#    #+#             */
/*   Updated: 2018/06/07 19:19:48 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ipow(int a, int power)
{
	int ret;

	ret = 1;
	while (power > 0)
	{
		if (power & 1)
			ret *= a;
		a *= a;
		power >>= 1;
	}
	return (ret);
}

int			no_duplicates(long *pile, int size)
{
	long *i;
	long *j;

	j = pile;
	while (j != (pile + size - 1))
	{
		i = j + 1;
		while (i != (pile + size))
		{
			if (i != j && *i == *j)
				return (0);
			++i;
		}
		++j;
	}
	return (1);
}

int			spaces_in(const char *str)
{
	const char	*p = str;
	int			i;
	int			prev;

	prev = 1;
	i = 0;
	while (*p)
	{
		(is_space(*p) && !prev) ? i++ : 0;
		prev = is_space(*p) ? 1 : 0;
		p++;
	}
	return (prev ? (i - 1) : i);
}
