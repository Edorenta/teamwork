/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 15:21:32 by fmadura           #+#    #+#             */
/*   Updated: 2018/06/27 16:13:54 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	ops_debug(t_ops *ops)
{
	printf("type : %d, opcode: %d\n", ops->type, ops->opcode);
	printf("args : %ld, %ld, %ld\n", ops->args[0], ops->args[1], ops->args[2]);
	printf("argv : %ld, %ld, %ld\n", ops->argv[0], ops->argv[1], ops->argv[2]);
}

void	ops_tostring(t_ops *ops)
{
	printf("[TYPE :%#x][OPCODE %#x]\n", ops->type, ops->opcode);
}

static inline void	set_arr(long arr[3])
{
	int count;

	count = -1;
	while (++count < 3)
		arr[count] = -1;
}

t_ops	*ops_new(void)
{
	t_ops	*new;

	if ((new = (t_ops *)malloc(sizeof(t_ops))) == NULL)
		return (NULL);
	new->next = NULL;
	new->type = 0;
	new->opcode = 0;
	set_arr(new->args);
	set_arr(new->argv);
	set_arr(new->label_id);
	return (new);
}
