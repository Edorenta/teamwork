/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_basic.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyildiz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 03:11:49 by jyildiz-          #+#    #+#             */
/*   Updated: 2018/07/03 02:01:33 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_op	g_op_tab[17];

static int	check_err(t_iter *iter, int token, int count)
{
	iter->token = token;
	iter->count = count;
	return (-1);
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

int			check_head(t_iter *iter)
{
	if (ft_strnequ((iter->line), NAME_CMD_STRING, 5))
	{
		if (iter->line[5] && !ft_isspace(iter->line[5]))
			return (check_err(iter, HEAD_ERR1, 6));
		else
		{
			iter->token |= HEAD_NAME;
			increment_num(iter, 5);
		}
	}
	else if (ft_strnequ((iter->line), COMMENT_CMD_STRING, 8))
	{
		if (iter->line[8] && !ft_isspace(iter->line[8]))
			return (check_err(iter, HEAD_ERR2, 9));
		else
		{
			increment_num(iter, 8);
			iter->token |= HEAD_COMT;
		}
	}
	else
		return (check_err(iter, HEAD_ERR0, 1));
	return (1);
}

int			while_check(t_iter **iter, int cpt)
{
	++((*iter)->line);
	++cpt;
	if ((*iter)->token == 0x82 && cpt == 129)
		return (check_err(*iter, NAME_ERR0, (*iter)->count + cpt));
	else if ((*iter)->token == 0x84 && cpt == 2049)
		return (check_err(*iter, COMT_ERR0, (*iter)->count + cpt));
	return (cpt);
}

int			check_name(t_iter *iter)
{
	int countchar;

	countchar = 1;
	while ((*(iter->line)) && *(iter->line) != '"')
	{
		if (!ft_isspace(*iter->line))
			return (check_err(iter, HEAD_ERR3, iter->count));
		increment(iter);
	}
	increment(iter);
	if ((*(iter->line)) && *(iter->line) == '"')
		return (check_err(iter, NAME_ERR1, iter->count));
	while ((*(iter->line)) && *(iter->line) != '"')
		if ((countchar = while_check(&iter, countchar)) == -1)
			return (-1);
	++(iter->line);
	while ((*(iter->line)) && *(iter->line) == ' ')
	{
		++(countchar);
		++(iter->line);
	}
	if (*(iter->line) != ';' && *(iter->line) != '#' && *(iter->line) != '\0')
		return (check_err(iter, ENDLI_ERR, iter->count + countchar));
	return (0);
}

int			lexer_basics(t_iter *iter)
{
	int	i;

	i = token_lab(iter);
	if (iter->line && *(iter->line) == COMMENT_CHAR)
		(iter->token) |= TOKEN_COM;
	else if (iter->line && i == 1)
		(iter->token) |= TOKEN_LAB;
	else if (iter->line && i == -1)
		return (-1);
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
