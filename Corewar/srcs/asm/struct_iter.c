/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 12:27:51 by fmadura           #+#    #+#             */
/*   Updated: 2018/06/28 15:04:03 by jyildiz-         ###   ########.fr       */
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
			node->next = token_create(type, label, iter->lnb, iter->count);
		}
		else
		{
			iter->iter->list = token_create(type, label, iter->lnb, iter->count);
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
	while (iter->first)
	{
		token = iter->first;
		iter->first = iter->first->next;
		token_del(token);
	}
	free(iter);
	iter = NULL;
}
