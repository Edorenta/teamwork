/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 11:12:05 by fmadura           #+#    #+#             */
/*   Updated: 2018/06/25 17:41:18 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_op	g_op_tab[17];

void	end_line(t_iter *iter)
{
	clear_wsp(iter);
	if (*iter->line == ';')
	{
		printf("[INS_COM][%d]", iter->count);
		printf("[INS_END][%d]", iter->count);
	}
	else if (!(*iter->line))
		printf("[INS_END][%d]", iter->count);
	else if (*iter->line == '#')
		printf("[INS_COM][%d]", iter->count);
	else
		printf("[INS_ERR][%d]", iter->count);
}

int	lexer_basics(t_iter *iter)
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
