/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 12:27:51 by fmadura           #+#    #+#             */
/*   Updated: 2018/06/26 18:25:19 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_iter	*iter_new(void)
{
	t_iter	*iter;

	if ((iter = (t_iter *)malloc(sizeof(t_iter))) == NULL)
		return (NULL);
	iter->lnb = 0;
	iter->line = NULL;
	iter->first = NULL;
	iter->iter = NULL;
	iter->token = 0;
	return (iter);
}

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

void 	iter_del(t_iter *iter)
{
	t_tok	*token;

	token = NULL;
	if (iter->line)
	{
		free(iter->line);
		iter->line = NULL;
	}
	if (iter->first)
	{
		token = iter->first;
		iter->first = iter->first->next;
		del_tok(token);
	}
	free(iter);
}
