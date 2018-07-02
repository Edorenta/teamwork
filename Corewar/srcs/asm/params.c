/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyildiz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/01 23:25:55 by jyildiz-          #+#    #+#             */
/*   Updated: 2018/07/02 03:55:22 by jyildiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_op	g_op_tab[17];

static int	three_param(t_iter *iter)
{
	t_tok	*list;

	list = iter->iter->list;
	if (iter->iter->type == 0x604 || iter->iter->type == 0x605)
	{
		if (list->type != INS_REG || list->next->next->type != INS_REG || list->next->next->next->next->type != INS_REG)
			return (-1);
	}
	else if (iter->iter->type == 0x606 || iter->iter->type == 0x607 || iter->iter->type == 0x608)
	{
		if (list->type != INS_REG && list->type != INS_DIR
				&& list->type != INS_DIL && list->type != INS_IND)
			return (-1);
		list = list->next->next;
		if (list->type != INS_REG && list->type != INS_DIR
				&& list->type != INS_DIL && list->type != INS_IND)
			return (-1);
		list = list->next->next;
		if (list->type != INS_REG)
			return (-1);
	}
	else if (iter->iter->type == 0x60A || iter->iter->type == 0x60E)
	{
		if (list->type != INS_REG && list->type != INS_DIR
				&& list->type != INS_DIL && list->type != INS_IND)
			return (-1);
		list = list->next->next;
		if (list->type != INS_DIR && list->type != INS_DIL && list->type != INS_REG)
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
		if (list->type != INS_REG && list->type != INS_DIR
				&& list->type != INS_DIL && list->type != INS_IND)
			return (-1);
		list = list->next->next;
		if (list->type != INS_DIR && list->type != INS_DIL && list->type != INS_REG)
			return (-1);
	}
	return (0);
}

static int	two_param(t_iter *iter)
{
	t_tok	*list;

	list = iter->iter->list;
	if (iter->iter->type == 0x60D || iter->iter->type == 0x602)
	{
		if (list->type != INS_DIR && list->type != INS_DIL && list->type != INS_IND)
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
	if (iter->iter->type == 0x610)
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
	if (iter->iter->type == 0x601 || iter->iter->type == 0x609
			|| iter->iter->type == 0x60C || iter->iter->type == 0x60F
			|| iter->iter->type == 0x610)
		return (one_param(iter));
	else if (iter->iter->type == 0x602 || iter->iter->type == 0x603
			|| iter->iter->type == 0x60D)
		return (two_param(iter));
	else
		return (three_param(iter));
}
