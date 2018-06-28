/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 11:12:05 by fmadura           #+#    #+#             */
/*   Updated: 2018/06/28 18:35:22 by jyildiz-         ###   ########.fr       */
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

void	check_head(t_iter *iter)
{
	if (ft_strnequ((iter->line), NAME_CMD_STRING, 5))
	{
		if (iter->line[5] != ' ')
		{
			iter->token |= HEAD_ERR1;
			iter->count = 6;
		}
		else
			iter->token |= HEAD_NAME;
	}
	else if (ft_strnequ((iter->line), COMMENT_CMD_STRING, 8))
	{
		if (iter->line[8] != ' ')
		{
			iter->token |= HEAD_ERR2;
			iter->count = 9;
		}
		else
			iter->token |= HEAD_COMT;
	}
	else
		(iter->token) |= HEAD_ERR0;
}

int		lexer_basics(t_iter *iter)
{
	if (iter->line && *(iter->line) == COMMENT_CHAR)
		(iter->token) |= TOKEN_COM;
	else if (iter->line && token_lab(iter))
		(iter->token) |= TOKEN_LAB;
	else if (iter->line && *(iter->line) == '.')
	{
		(iter->token) |= TOKEN_HEA;
		(iter->token) <<= 4; 
		/*if (ft_strnequ((iter->line), NAME_CMD_STRING, 5))
		{
			(iter->token) |= HEAD_NAME;
		else if (ft_strnequ((iter->line), COMMENT_CMD_STRING, 8))
			(iter->token) |= HEAD_COMT;
		else
			(iter->token) |= HEAD_ERR0;*/
		check_head(iter);
		while ((*(iter->line)) && *(iter->line) != '"')
		{
			++(iter->count);
			++(iter->line);
		}
		return (iter->token);
	}
	else if ((iter->line) && token_wsp(iter->line, 0))
		(iter->token) |= TOKEN_SPA;
	(iter->token) <<= 4;
	return (iter->token);
}
