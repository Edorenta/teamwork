/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyildiz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 18:25:31 by jyildiz-          #+#    #+#             */
/*   Updated: 2018/05/14 14:36:26 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int			full_digits(const char *str)
{
	return (ft_atol(str) != NONE ? 1 : 0);
}

int			is_int(char *av)
{
	return (av && (ft_atol(av) >= -2147483648 && ft_atol(av) <= 2147483647));
}

long		ft_atol(const char *str)
{
	long		nb;
	long		sign;

	nb = NONE;
	while (is_space(*str))
		++str;
	if (!(*str))
		return (NONE);
	sign = *str == '-' ? -1 : 1;
	if (*str == '+' || *str == '-')
		++str;
	nb = 0;
	while (*str && is_digit(*str))
		nb = 10 * nb + (*(str++) - '0');
	return (*str == '\0' ? nb * sign : NONE);
}
