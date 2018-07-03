/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 11:12:05 by fmadura           #+#    #+#             */
/*   Updated: 2018/07/02 23:07:11 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_op	g_op_tab[17];

static int	lexer_return_err(t_iter *iter, int token)
{
	iter->token = token;
	return (-1);
}

int			lexer_sub_dir(t_iter *iter)
{
	increment(iter);
	if (*iter->line == ':')
	{
		iter->token <<= 4;
		iter->token |= INS_DIR;
		iter_add_list(iter, "INS_DIL", INS_DIL);
		increment(iter);
	}
	else if (ft_isdigit(*iter->line) || *iter->line == '-')
	{
		iter->token <<= 4;
		iter->token |= INS_DIR;
		iter_add_list(iter, "INS_DIR", INS_DIR);
	}
	else
		return (-1);
	return (0);
}

static int	lexer_ins_log(t_iter *iter)
{
	if (*iter->line == '%')
	{
		if (lexer_sub_dir(iter) == -1)
			return (lexer_return_err(iter, PAR_ERR0));
	}
	else if (*iter->line == 'r')
	{
		increment(iter);
		iter->token = ((iter->token << 4) | INS_REG);
		iter_add_list(iter, "INS_REG", INS_REG);
	}
	else if (ft_isdigit(*iter->line) || *iter->line == '-')
	{
		iter->token = ((iter->token << 4) | INS_REG);
		iter_add_list(iter, "INS_IND", INS_IND);
	}
	else
		return (lexer_return_err(iter, PAR_ERR0));
	return (1);
}

int			lexer_ins_sub(t_iter *iter, int op)
{
	int sep;

	sep = -1;
	while (++sep < 3)
	{
		clear_wsp(iter);
		if (lexer_ins_log(iter) == -1)
			return (-1);
		while (*iter->line && lab_ischar(*iter->line))
			increment(iter);
		clear_wsp(iter);
		if (*iter->line && *iter->line == ',')
		{
			iter->token = ((iter->token << 4) | INS_SEP);
			iter_add_list(iter, "INS_SEP", INS_SEP);
			increment(iter);
		}
		else
			break ;
	}
	if (g_op_tab[op].nbarg != sep + 1)
		return (lexer_return_err(iter, PAR_ERR1));
	if (test_param(iter) == -1)
		return (lexer_return_err(iter, PAR_ERR2));
	return (1);
}

int			lexer_ins(t_iter *iter, int len, int op)
{
	t_tok	*token;

	token = NULL;
	if (iter->line && iter->token == 0)
	{
		if ((op = token_ins(iter, iter->line)) > -1)
		{
			iter->token = (TOKEN_INS << 4) | (op + 1);
			iter->iter->next = token_create(0x600 | (op + 1),
					g_op_tab[op].name, iter->lnb, iter->count);
			iter->iter = iter->iter->next;
			len = g_op_tab[op].nlen;
			clear_wsp(iter);
			while (--len > -1)
				increment(iter);
			if (lexer_ins_sub(iter, op) == -1)
				return (-1);
			end_line(iter);
			return (0);
		}
		else if (op == -1)
			return (-1);
	}
	return (1);
}
