/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 11:12:05 by fmadura           #+#    #+#             */
/*   Updated: 2018/06/22 14:04:45 by fmadura          ###   ########.fr       */
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

void	lexer_token(unsigned int token, int lnb, int pos)
{
	t_tok	*new;

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
			new->list = create_tok(token, lexer_head(token), lnb, 0);
		}
	}
	else
		printf("token true : %d\n", check_op(token));
	tok_tostring(new);
	if (new)
		tok_tostring(new->list);
	return ;
}

void	lex(int fd)
{
	t_tok			*first;
	t_tok			*iter;
	char			*line;
	int				ret;
	int				lnb;
	int				count;
	unsigned int	token;

	lnb = 0;
	line = NULL;
	first = NULL;
	iter = NULL;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		count = 0;
		token = 0;
		printf("\nline :{%s}\n", line);
		lexer_basics(line, &token, lnb, &count);
		lexer_ins(&line, &token, lnb, &count);
		lexer_token(token, lnb, count);
		++lnb;
	}
}
