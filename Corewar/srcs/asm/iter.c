/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 12:27:51 by fmadura           #+#    #+#             */
/*   Updated: 2018/06/26 14:04:52 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_iter	*iter_add_list(t_iter *iter, char *label, int type)
{
	t_tok	*node;

	if (iter && iter->iter)
	{
		node = iter->iter->list;
		if (node)
		{
			while (node->next)
				node = node->next;
			node->next = create_tok(type, label, iter->lnb, iter->count);
		}
		else
		{
			iter->iter->list = create_tok(type, label, iter->lnb, iter->count);
		}
	}
	return (iter);
}
