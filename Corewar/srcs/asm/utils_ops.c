/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 12:53:33 by fmadura           #+#    #+#             */
/*   Updated: 2018/06/29 05:36:30 by fmadura          ###   ########.fr       */
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

int		ops_get_len(t_ops *ops)
{
	int		len;
	int		count;
	long		num;

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
			len += (ops->label[count] == -1) ? 2 : 4;
		else if (num == 3)
			len += 2;	
		else
			break;
	}
	return (len);
}
