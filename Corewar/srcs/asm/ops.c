/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 15:21:32 by fmadura           #+#    #+#             */
/*   Updated: 2018/06/26 16:35:18 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_ops	*ops_new(void)
{
	t_ops	*new;

	if ((new = (t_ops *)malloc(sizeof(t_ops))) == NULL)
		return (NULL);
	new->op = NULL;
	new->next = NULL;
	new->type = 0;
	new->opcode = 0;
	new->args[0] = -1;
	new->args[1] = -1;
	new->args[2] = -1;
	new->label_id[0] = -1;
	new->label_id[1] = -1;
	new->label_id[2] = -1;
	return (new);
}
