/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 11:12:05 by fmadura           #+#    #+#             */
/*   Updated: 2018/07/03 02:07:09 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_op	g_op_tab[17];

char		*lexer_head(unsigned int token)
{
	return ((token & 0x2) ? "HEAD_NAME" : "HEAD_COMMENT");
}

void		end_line(t_iter *iter)
{
	clear_wsp(iter);
	if (*iter->line == ';')
	{
		iter_add_list(iter, "INS_COM", INS_COM);
		iter_add_list(iter, "INS_END", INS_END);
	}
	else if (!(*iter->line))
		iter_add_list(iter, "INS_END", INS_END);
	else if (*iter->line == '#')
		iter_add_list(iter, "INS_END", INS_END);
	else
		iter_add_list(iter, "INS_ERR", INS_ERR);
}

void		end_while(t_iter **iter, char *line)
{
	++((*iter)->lnb);
	free(line);
	(*iter)->line = NULL;
	line = NULL;
}

void		err_read(t_iter *iter)
{
	iter->token = READ_ERR;
	put_error(iter, NULL);
}
