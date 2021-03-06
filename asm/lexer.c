/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 11:12:05 by fmadura           #+#    #+#             */
/*   Updated: 2018/07/03 06:07:39 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_op	g_op_tab[17];

char			*lexer_label(unsigned int token)
{
	token >>= 4;
	if (token == TOKEN_COM)
		return ("TOKEN_COMMENT");
	if (token == TOKEN_LAB)
		return ("TOKEN_LABEL");
	if (token == TOKEN_HEA)
		return ("TOKEN_HEAD");
	if (token == TOKEN_SPA)
		return ("TOKEN_SPACE");
	return ("TOKEN_ERROR");
}

static t_tok	*lexer_token(t_iter *iter, char *line)
{
	t_tok			*new;
	unsigned int	token;
	int				lnb;
	int				pos;

	token = iter->token;
	pos = iter->count;
	lnb = iter->lnb;
	new = NULL;
	if (!(token & 0x0F))
	{
		new = token_iter(iter, lexer_label(token));
		if ((new->type >> 4) == TOKEN_LAB)
			if (lab_create(iter, line) == -1)
				return (NULL);
	}
	else
	{
		new = token_create(token, lexer_label(token), lnb, 0);
		token = token & 0xF;
		new->list = token_iter(iter, lexer_head(token));
	}
	return (new);
}

void			if_lab(t_iter **iter, char *line, int lab)
{
	if (!(*iter)->first)
	{
		(*iter)->first = lexer_token(*iter, line);
		(*iter)->iter = (*iter)->first;
	}
	else
	{
		if (((*iter)->iter->next = lexer_token(*iter, line)) == NULL)
			put_error(*iter, line);
		(*iter)->iter = (*iter)->iter->next;
	}
	if (lab == 1)
	{
		(*iter)->token = 0;
		(lexer_ins(*iter, 0, 0) == -1) ? put_error(*iter, line) : 0;
	}
}

t_iter			*lexer(t_iter *iter, int fd)
{
	char			*line;
	int				ret;
	long			basic;

	while ((ret = get_next_line(fd, &line)) > 0)
	{
		iter->line = line;
		iter->count = 0;
		iter->token = 0;
		basic = lexer_basics(iter);
		if (basic == (TOKEN_LAB << 4))
			if_lab(&iter, line, 1);
		else if (basic == 0)
			(lexer_ins(iter, 0, 0) == -1) ? put_error(iter, line) : 0;
		else if (basic == -1)
			put_error(iter, line);
		else
			if_lab(&iter, line, 0);
		end_while(&iter, line);
	}
	ret == -1 ? err_read(iter) : 0;
	return (iter);
}
