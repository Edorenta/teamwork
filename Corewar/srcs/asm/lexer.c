/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 11:12:05 by fmadura           #+#    #+#             */
/*   Updated: 2018/06/27 14:36:28 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_op	g_op_tab[17];

char	*lexer_head(unsigned int token)
{
	return ((token & 0x2) ? "HEAD_NAME" : "HEAD_COMMENT");
}

char	*lexer_label(unsigned int token)
{
	token >>= 4;
	if (token == TOKEN_COM)
		return "TOKEN_COMMENT";
	if (token == TOKEN_LAB)
		return "TOKEN_LABEL";
	if (token == TOKEN_HEA)
		return "TOKEN_HEAD";
	if (token == TOKEN_SPA)
		return "TOKEN_SPACE";
	return "TOKEN_ERROR";
}

static t_tok	*lexer_token(t_iter *iter)
{
	t_tok			*new;
	unsigned int	token;
	int 			lnb;
	int 			pos;

	token = iter->token;
	pos = iter->count;
	lnb = iter->lnb;
	new = NULL;
	if (!(token & 0x0F))
		new = tok_iter(iter, lexer_label(token));
	else
	{
		new = create_tok(token, lexer_label(token), lnb, 0);
		token = token & 0xF;
		new->list = tok_iter(iter, lexer_head(token));
	}
	return (new);
}

t_iter	*lexer(t_iter *iter, int fd)
{
	char			*line;
	int				ret;

	while ((ret = get_next_line(fd, &line)) > 0)
	{
		iter->line = line;
		iter->count = 0;
		iter->token = 0;
		//printf("\nline :{%s}\n", iter->line);
		if (!lexer_basics(iter))
			lexer_ins(iter);
		else if (!iter->first)
		{
			iter->first = lexer_token(iter);
			iter->iter = iter->first;
		}
		else
		{
			iter->iter->next = lexer_token(iter);
			iter->iter = iter->iter->next;
		}
		//tok_tostring(iter->iter);
		++(iter->lnb);
		free(line);
		iter->line = NULL;
		line = NULL;
	}
	return (iter);
}
