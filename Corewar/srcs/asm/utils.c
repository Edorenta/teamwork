/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 20:15:25 by fmadura           #+#    #+#             */
/*   Updated: 2018/07/02 23:06:51 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		lab_ischar(char c)
{
	return (ft_isdigit(c) || ft_isalpha(c) || c == '_' || c == '-');
}

void	clear_wsp(t_iter *iter)
{
	while (*iter->line && ft_isspace(*iter->line))
	{
		++(iter->count);
		++(iter->line);
	}
}

void	increment_num(t_iter *iter, int num)
{
	while (--num >= 0)
	{
		++(iter->count);
		++(iter->line);
	}
}

void	increment(t_iter *iter)
{
	++(iter->count);
	++(iter->line);
}
