/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 13:03:28 by fmadura           #+#    #+#             */
/*   Updated: 2018/07/02 19:34:11 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	token_tostring(t_tok *tok)
{
	t_tok	*list;

	if (tok)
	{
		printf("[LINE %d][TYPE %#.3x][LABEL %-13s][POS %-4d]\n",
				tok->lnb, tok->type, tok->label, tok->pos);
		list = tok->list;
		while (list)
		{
			printf("[LINE %d][TYPE %#.3x][LABEL %-13s][POS %-4d]\n",
					list->lnb, list->type, list->label, list->pos);
			list = list->next;
		}
	}
}

void	token_del(t_tok *tok)
{
	t_tok	*list;

	if (tok)
	{
		if (tok->label)
			free(tok->label);
		while (tok->list)
		{
			list = tok->list;
			tok->list = tok->list->next;
			token_del(list);
			list = NULL;
		}
		free(tok);
		tok = NULL;
	}
}

/*
** error here 
*/

t_tok	*token_new(void)
{
	t_tok	*new;

	if ((new = (t_tok *)malloc(sizeof(t_tok))) == NULL)
		return (NULL);
	new->type = -1;
	new->token = 0;
	new->label = NULL;
	new->lnb = -1;
	new->pos = 0;
	new->list = NULL;
	new->next = NULL;
	return (new);
}

/*
** error here 
*/

t_tok	*token_create(int type, char *label, int lnb, int pos)
{
	t_tok	*tok;

	if ((tok = token_new()) == NULL)
		return (NULL);
	tok->type = type;
	tok->label = ft_strdup(label);
	tok->lnb = lnb;
	tok->pos = pos;
	return (tok);
}

t_tok	*token_iter(t_iter *iter, char *label)
{
	t_tok	*tok;

	tok = NULL;
	return (token_create(iter->token, label, iter->lnb, iter->count));
}
