/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 11:12:05 by fmadura           #+#    #+#             */
/*   Updated: 2018/06/22 14:20:02 by fmadura          ###   ########.fr       */
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

static int	lexer_token(t_iter *iter)
{
	t_tok	*new;
	unsigned int token;
	int lnb;
	int pos;

	token = iter->token;
	pos = iter->count;
	lnb = iter->lnb;
	new = NULL;
	if (token <= 0xA0)
	{
		if (!(token & 0x0F))
		{
			token >>= 4;
			new = create_tok(token, lexer_label(token), lnb, 0);
		}
		else
		{
			new = create_tok(token >> 4, lexer_label((token >> 4)), lnb, 0);
			token = token & 0xF;
			new->list = create_tok(token, lexer_head(token), lnb, pos);
		}
		tok_tostring(new);
		tok_tostring(new->list);
		return (0);
	}
	printf("token true : %d\n", check_op(token));
	return (1);
}

void	lex(int fd)
{
	t_iter			iter;
	char			*line;
	int			ret;

	iter.lnb = 0;
	iter.line = NULL;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		iter.line = line;
		iter.count = 0;
		iter.token = 0;
		printf("\nline :{%s}\n", iter.line);
		lexer_basics(&iter);
		lexer_ins(&iter);
		lexer_token(&iter);
		++(iter.lnb);
		free(line);
		line = NULL;
	}
}
