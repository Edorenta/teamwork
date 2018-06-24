/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 13:03:28 by fmadura           #+#    #+#             */
/*   Updated: 2018/06/22 13:47:19 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	tok_tostring(t_tok *tok)
{
	if (tok)
		printf("[LINE %d][TYPE %#x][TOKEN %#x][LABEL %s][POS %d]\n",
		 tok->lnb, tok->type,tok->token, tok->label, tok->pos);
}

t_tok	*new_tok()
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

t_tok	*create_tok(int type, char *label, int lnb, int pos)
{
	t_tok	*tok;

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


