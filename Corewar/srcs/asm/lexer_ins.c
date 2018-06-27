/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 11:12:05 by fmadura           #+#    #+#             */
/*   Updated: 2018/06/27 14:37:37 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_op	g_op_tab[17];

void	lexer_sub_dir(t_iter *iter)
{
	increment(iter);
	if (*iter->line == ':')
	{
		iter->token <<= 4;
		iter->token |= INS_DIR;
		iter_add_list(iter, "INS_DIR", INS_DIR);
		increment(iter);	
	}
	else if (ft_isdigit(*iter->line) || *iter->line == '-')
	{
		iter->token <<= 4;
		iter->token |= INS_DIR;
		iter_add_list(iter, "INS_DIR", INS_DIR);
	}
}
static int	lexer_ins_log(t_iter *iter)
{
	if (*iter->line == '%')
		lexer_sub_dir(iter);
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
		return (0);
	return (1);
}
void	lexer_ins_sub(t_iter *iter) 
{
	int sep;

	sep = 0;
	clear_wsp(iter);
	while (sep < 3)
	{
		if (!lexer_ins_log(iter))
			break;
		while (*iter->line && (ft_isdigit(*iter->line) ||
			ft_isalpha(*iter->line) || *iter->line == '_' || *iter->line == '-'))
			increment(iter);
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
}

void	lexer_ins(t_iter *iter)
{
	int		len;
	int		op;
	t_tok	*token;

	len = 0;
	op = 0;
	token = NULL;
	if (iter->line && iter->token == 0)
	{
		iter->token |= TOKEN_INS;
		iter->token <<= 4;
		if ((op = token_ins(iter->line)) > -1)
		{
			iter->token <<= 4;
			iter->token |= op + 1;
			iter->iter->next = create_tok(0x600 | (op + 1), g_op_tab[op].name, iter->lnb, iter->count);
			iter->iter = iter->iter->next;
			len = g_op_tab[op].nlen;
			clear_wsp(iter);
			while (--len > -1)
				increment(iter);
			lexer_ins_sub(iter);
			end_line(iter);
		}
	}
}
