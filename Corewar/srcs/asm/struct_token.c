/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 13:03:28 by fmadura           #+#    #+#             */
/*   Updated: 2018/06/27 14:38:55 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	tok_tostring(t_tok *tok)
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

void	del_tok(t_tok *tok)
{
	t_tok	*list;
	t_tok	*iter;

	if (tok)
	{
		list = tok->list;
		while (list)
		{
			iter = list;
			list = list->next;
			free(iter);
			iter = NULL;	
		}
		if (tok->label)
			free(tok->label);
		free(tok);
		tok = NULL;
	}
}

t_tok	*new_tok()
{
	t_tok	*new;

	//error here	
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

t_tok	*create_tok(int type, char *label, int lnb, int pos)
{
	t_tok	*tok;

	//error here	
	if ((tok = new_tok()) == NULL)
		return (NULL);
	tok->type = type;
	tok->label = ft_strdup(label);
	tok->lnb = lnb;
	tok->pos = pos;
	return (tok);
}

t_tok	*tok_iter(t_iter *iter, char *label)
{
	t_tok	*tok;

	tok = NULL;
	return (create_tok(iter->token, label, iter->lnb, iter->count));
}
