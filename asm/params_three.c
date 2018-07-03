/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyildiz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/01 23:25:55 by jyildiz-          #+#    #+#             */
/*   Updated: 2018/07/02 19:50:06 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_op	g_op_tab[17];

static int	first_type(t_tok *list)
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
	return (0);
}

static int	secnd_type(t_tok *list)
{
	if (list->type != INS_REG && list->type != INS_DIR
			&& list->type != INS_DIL && list->type != INS_IND)
		return (-1);
	list = list->next->next;
	if (list->type != INS_DIR && list->type != INS_DIL
			&& list->type != INS_REG)
		return (-1);
	list = list->next->next;
	if (list->type != INS_REG)
		return (-1);
	return (0);
}

static int	third_type(t_tok *list)
{
	if (list->type != INS_REG)
		return (-1);
	list = list->next->next;
	if (list->type != INS_REG && list->type != INS_DIR
			&& list->type != INS_DIL && list->type != INS_IND)
		return (-1);
	list = list->next->next;
	if (list->type != INS_DIR && list->type != INS_DIL
			&& list->type != INS_REG)
		return (-1);
	return (0);
}

int			three_param(t_iter *iter)
{
	t_tok	*list;

	list = iter->iter->list;
	if (TYPE == 0x604 || TYPE == 0x605)
	{
		if (list->type != INS_REG || list->next->next->type != INS_REG
				|| list->next->next->next->next->type != INS_REG)
			return (-1);
	}
	else if (TYPE == 0x606 || TYPE == 0x607 || TYPE == 0x608)
		return (first_type(list));
	else if (TYPE == 0x60A || TYPE == 0x60E)
		return (secnd_type(list));
	else
		return (third_type(list));
	return (0);
}
