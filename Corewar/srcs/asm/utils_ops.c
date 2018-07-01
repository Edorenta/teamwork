/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 12:53:33 by fmadura           #+#    #+#             */
/*   Updated: 2018/07/02 00:04:30 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

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
	len = 0;
	while (++count < 3)
	{
		num = (ops->args[count]);
		if (num == -1)
			break;
		else if (num == 1)
			len++;
		else if (num == 2)
			len += (ops->argv[count] == -1) ? 4 : 2;
		else if (num == 3)
			len += 2;	
		else
			//error here
			break;
	}
	return (len);
}

unsigned int		ops_get_len(t_ops *ops)
{
	t_ops			*iter;
	unsigned int	len;

	len = 0;
	if (ops)
	{
		iter = ops;
		while (iter)
		{
			len += ops_getlen(iter);
			iter = iter->next;
		}
	}
	else
		;//error here;	
	return (len);
}
