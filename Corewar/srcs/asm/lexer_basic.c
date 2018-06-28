/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 11:12:05 by fmadura           #+#    #+#             */
/*   Updated: 2018/06/29 00:36:36 by jyildiz-         ###   ########.fr       */
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

int		check_head(t_iter *iter)
{
	if (ft_strnequ((iter->line), NAME_CMD_STRING, 5))
	{
		if (iter->line[5] && iter->line[5] != ' ')
		{
			iter->token |= HEAD_ERR1;
			iter->count = 6;
			return (-1);
		}
		else
		{
			iter->token |= HEAD_NAME;
			increment_num(iter, 5);
		}
	}
	else if (ft_strnequ((iter->line), COMMENT_CMD_STRING, 8))
	{
		if (iter->line[8] && iter->line[8] != ' ')
		{
			iter->token |= HEAD_ERR2;
			iter->count = 9;
			return (-1);
		}
		else
		{
			increment_num(iter, 8);
			iter->token |= HEAD_COMT;
		}
	}
	else
	{
		(iter->token) |= HEAD_ERR0;
		return (-1);
	}
	return (1);
}

int	check_name(t_iter *iter)
{
	int countchar;

	countchar = 1;
	while ((*(iter->line)) && *(iter->line) != '"')
	{
		if (iter->line[0] != ' ')
		{
			iter->token = HEAD_ERR3;
			return (-1);
		}	
		++(iter->count);
		++(iter->line);
	}
	++(iter->count);
	++(iter->line);
	while ((*(iter->line)) && *(iter->line) != '"')
	{
		++(iter->line);
		countchar++;
		if (iter->token == 0x02 && countchar == 129)
		{
			iter->token = NAME_ERR0;
			iter->count += countchar;
			return (-1);
		}
		else if (iter->token == 0x04 && countchar == 2049)
		{
			iter->token = COMT_ERR0;
			iter->count += countchar;
			return (-1);
		}
	}
	++(iter->line);
	while  ((*(iter->line)) && *(iter->line) == ' ')
	{
		++(iter->count);
		++(iter->line);
	}
	if (*(iter->line) != ';' && *(iter->line) != '#' && *(iter->line) != '\0')
	{
		iter->token = ENDLI_ERR;
		return (-1);
	}
	return (0);
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
		if (check_head(iter) == -1)
			return (-1);
		if (check_name(iter) == -1)
			return (-1);
		return (iter->token);
	}
	else if ((iter->line) && token_wsp(iter->line, &(iter->count)))
		(iter->token) |= TOKEN_SPA;
	(iter->token) <<= 4;
	return (iter->token);
}
