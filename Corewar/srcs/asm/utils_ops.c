/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 12:53:33 by fmadura           #+#    #+#             */
/*   Updated: 2018/07/02 05:57:59 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_op	g_op_tab[17];

int		ops_get_ocp(t_ops *ops)
{
	int		opc;
	int		count;

	opc = 0;
	count = -1;
	if (!ops)
		return (0);
	while (++count < 3)
	{
		if (ops->args[count] == -1)
			break;
		opc <<= 2;
		opc += ops->args[count];
	}
	while (++count < 5)
		opc <<= 2;
	ops->opcode = opc;
	return (1);
}

static unsigned int	ops_getlen(t_ops *ops)
{
	unsigned int	len;
	int				count;
	long			num;

	count = -1;
	len = 1;
	while (++count < 3)
	{
		num = (ops->args[count]);
		if (num == -1)
			break;
		else if (num == 1)
			len++;
		else if (num == 2)
			len += g_op_tab[ops->type - 1].label ? 4 : 2;
		else if (num == 3)
			len += 2;	
		else
			//error here
			break;
	}
	len += g_op_tab[ops->type - 1].octal;
	return (len);
}

unsigned int		ops_get_len(t_ops *ops)
{
	t_ops			*iter;
	unsigned int	len;
	unsigned int	att;

	len = 0;
	if (ops)
	{
		iter = ops;
		while (iter)
		{
			att = 0;
			att = ops_getlen(iter);
			iter->len = att;
			len += att;
			iter = iter->next;
		}
	}
	else
		;//error here;	
	return (len);
}
static unsigned int	ops_diff(t_ops *ops, int labline, int opsline)
{
	unsigned int	len;
	t_ops		*hop;

	len = 0;
	hop = ops;
	if (opsline < labline)
	{
		while (hop && hop->lnb < opsline)
			hop = hop->next;
		while (hop && hop->lnb < labline)
		{
			len += hop->len;
			hop = hop->next;
		}
		printf("hal %#x\n", len);
	}
	else if (opsline > labline)
	{
		while (hop && hop->lnb < labline)
			hop = hop->next;
		while (hop && hop->lnb < opsline)
		{
			len += hop->len;
			hop = hop->next;
		}
		printf("hel %#x\n", (len = ~len + 1));
	}
	return (len);
}
unsigned int		ops_get_lab(t_iter *iter, t_ops *ops)
{
	t_lab	*label;
	t_ops	*hop;
	int		count;
	int		num;

	//error here
	if (!iter || !ops)
		return 0;
	else
	{
		hop = ops;
		while (hop)
		{
			label = iter->labels;
			count = -1;
			while (++count < 3)
			{
				num = (hop->args[count]);
				if (num == -1)
					break;
				else if (num == 2 && hop->label[count] != -1)
				{
					hop->label[count] = ops_diff(ops, hop->label[count], hop->lnb);
				}
			}
			hop = hop->next;
		}
	}
	return 1;
}
