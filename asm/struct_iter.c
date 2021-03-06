/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 12:27:51 by fmadura           #+#    #+#             */
/*   Updated: 2018/07/03 03:41:39 by fmadura          ###   ########.fr       */
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
	iter->labels = NULL;
	iter->token = 0;
	iter->head_ok = 0;
	return (iter);
}

t_iter	*iter_add_list(t_iter *iter, char *label, int typ)
{
	t_tok	*node;

	if (iter && iter->iter)
	{
		node = iter->iter->list;
		if (node)
		{
			while (node->next)
				node = node->next;
			node->next = token_create(typ, label, iter->lnb, iter->count);
		}
		else
			iter->iter->list = token_create(typ, label, iter->lnb, iter->count);
	}
	return (iter);
}

void	iter_del(t_iter *iter)
{
	t_tok	*token;

	token = NULL;
	if (iter->line)
		iter->line = NULL;
	while (iter->first)
	{
		token = iter->first;
		iter->first = iter->first->next;
		token_del(token);
	}
	lab_del(iter->labels);
	free(iter);
	iter = NULL;
}
