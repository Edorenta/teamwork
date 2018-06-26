/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 11:12:05 by fmadura           #+#    #+#             */
/*   Updated: 2018/06/26 13:55:34 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_op	g_op_tab[17];

void	end_line(t_iter *iter)
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

int		lexer_basics(t_iter *iter)
{
	if (iter->line && *(iter->line) == COMMENT_CHAR)
		(iter->token) |= TOKEN_COM;
	else if (iter->line && token_lab(iter->line))
		(iter->token) |= TOKEN_LAB;
	else if (iter->line && *(iter->line) == '.')
	{
		(iter->token) |= TOKEN_HEA;
		(iter->token) <<= 4; 
		if (ft_strnequ((iter->line), NAME_CMD_STRING, 5))
			(iter->token) |= HEAD_NAME;
		else if (ft_strnequ((iter->line), COMMENT_CMD_STRING, 8))
			(iter->token) |= HEAD_COMT;
		else
			(iter->token) |= HEAD_ERRR;
		while ((*(iter->line)) && *(iter->line) != '"')
		{
			++(iter->count);
			++(iter->line);
		}
		return (iter->token);
	}
	else if ((iter->line) && token_wsp((iter->line)))
		(iter->token) |= TOKEN_SPA;
	(iter->token) <<= 4;
	return (iter->token);
}
