/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyildiz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/01 23:25:55 by jyildiz-          #+#    #+#             */
/*   Updated: 2018/07/02 19:48:57 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_op	g_op_tab[17];

static int	two_param(t_iter *iter)
{
	t_tok	*list;

	list = iter->iter->list;
	if (TYPE == 0x60D || TYPE == 0x602)
	{
		if (list->type != INS_DIR && list->type != INS_DIL
				&& list->type != INS_IND)
			return (-1);
		list = list->next->next;
		if (list->type != INS_REG)
			return (-1);
	}
	else
	{
		if (list->type != INS_REG)
			return (-1);
		list = list->next->next;
		if (list->type != INS_REG && list->type != INS_IND)
			return (-1);
	}
	return (0);
}

static int	one_param(t_iter *iter)
{
	t_tok	*list;

	list = iter->iter->list;
	if (TYPE == 0x610)
	{
		if (list->type != INS_REG)
			return (-1);
	}
	else
	{
		if (list->type != INS_DIR && list->type != INS_DIL)
			return (-1);
	}
	return (1);
}

int			test_param(t_iter *iter)
{
	if (TYPE == 0x601 || TYPE == 0x609
			|| TYPE == 0x60C || TYPE == 0x60F
			|| TYPE == 0x610)
		return (one_param(iter));
	else if (TYPE == 0x602 || TYPE == 0x603
			|| TYPE == 0x60D)
		return (two_param(iter));
	else
		return (three_param(iter));
}
