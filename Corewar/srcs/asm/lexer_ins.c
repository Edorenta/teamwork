/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 11:12:05 by fmadura           #+#    #+#             */
/*   Updated: 2018/07/02 00:42:28 by fmadura          ###   ########.fr       */
/*   Updated: 2018/07/01 23:19:30 by jyildiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_op	g_op_tab[17];

int		lexer_sub_dir(t_iter *iter)
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

static int	lexer_ins_log(t_iter *iter, int op, int para)
{
	if (*iter->line == '%')
	{
		if (lexer_sub_dir(iter) == -1)
		{
			iter->token = PAR_ERR0;
			return (-1);
		}
		else if (g_op_tab[op].arg[i] !=
	}
	else if (*iter->line == 'r')
	{
		increment(iter);
		iter->token <<= 4;
		iter->token |= INS_REG;
		iter_add_list(iter, "INS_REG", INS_REG);
	}
	else if (ft_isdigit(*iter->line) || *iter->line == '-')
	{
		iter->token <<= 4;
		iter->token |= INS_REG;	
		iter_add_list(iter, "INS_IND", INS_IND);
	}
	else
	{
		iter->token = PAR_ERR0;
		return (-1);
	}
	return (1);
}

int		lexer_ins_sub(t_iter *iter, int op) 
{
	int sep;

	sep = 0;
	clear_wsp(iter);
	while (sep < 3)
	{
		if (lexer_ins_log(iter, op, sep) == -1)
			return (-1);
		while (*iter->line && (ft_isdigit(*iter->line) ||
			ft_isalpha(*iter->line) || *iter->line == '_' || *iter->line == '-'))
			increment(iter);
		//clear_wsp(iter);
		if (*iter->line && *iter->line == ',')
		{
			iter->token <<= 4;
			iter->token |= INS_SEP;
			iter_add_list(iter, "INS_SEP", INS_SEP);
			increment(iter);
		}
		else
			break;
		clear_wsp(iter);
		sep++;
	}
	if (g_op_tab[op].nbarg != sep + 1)
	{
		iter->token = PAR_ERR1;
		return (-1);
	}
	return (1);
}

int		lexer_ins(t_iter *iter)
{
	int		len;
	int		op;
	t_tok	*token;

	len = 0;
	op = 0;
	token = NULL;
	if (iter->line && iter->token == 0)
	{
		if ((op = token_ins(iter, iter->line)) > -1)
		{
			iter->token = TOKEN_INS;
			iter->token <<= 4;
			iter->token |= op + 1;
			iter->iter->next = token_create(0x600 | (op + 1), g_op_tab[op].name, iter->lnb, iter->count);
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
