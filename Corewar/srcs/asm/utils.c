/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 20:15:25 by fmadura           #+#    #+#             */
/*   Updated: 2018/07/02 20:16:11 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

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
