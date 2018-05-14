/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyildiz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 18:25:31 by jyildiz-          #+#    #+#             */
/*   Updated: 2018/05/14 11:51:03 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	if (*str)
	{
		sign = *str == '-' ? -1 : 1;
		if (*str == '+' || *str == '-')
			++str;
		nb = 0;
		while (*str && is_digit(*str))
			nb = 10 * nb + (*(str++) - '0');
	}
	return (*str == '\0' ? nb * sign : NONE);
}
