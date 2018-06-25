/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 11:12:05 by fmadura           #+#    #+#             */
/*   Updated: 2018/06/24 21:25:32 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_op	g_op_tab[17];

void	lexer_sub_dir(t_iter *iter)
{
	++(iter->count);
	++(iter->line);
	if (*iter->line == ':')
	{
		iter->token <<= 4;
		iter->token |= INS_DIR;
		printf("[INS_DIR][%d]", iter->count);
		++(iter->count);
		++(iter->line);
	}
	else if (ft_isdigit(*iter->line) || *iter->line == '-')
	{
		iter->token <<= 4;
		iter->token |= INS_DIR;
		printf("[INS_DIR][%d]", iter->count);
	}
}

void	lexer_ins_sub(t_iter *iter) 
{
	int sep;

	sep = 0;
	clear_wsp(iter);
	while (sep < 3)
	{
		if (*iter->line == '%')
			lexer_sub_dir(iter);
		else if (*iter->line == 'r')
		{
			++(iter->count);
			++(iter->line);
			iter->token <<= 4;
			iter->token |= INS_REG;
			printf("[INS_REG][%d]", iter->count);
		}
		else if (ft_isdigit(*iter->line) || *iter->line == '-')
		{
			iter->token <<= 4;
			iter->token |= INS_REG;	
			printf("[INS_IND][%d]", iter->count);
		}
		else
			break;
		while (*iter->line && (ft_isdigit(*iter->line) ||
			ft_isalpha(*iter->line) || *iter->line == '_' || *iter->line == '-'))
		{
			++(iter->count);
			++(iter->line);
		}
		if (*iter->line && *iter->line == ',')
		{
			iter->token <<= 4;
			iter->token |= INS_SEP;
			printf("[INS_SEP][%d]", iter->count);
			++(iter->count);
			++(iter->line);
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

	len = 0;
	op = 0;
	if (iter->line && iter->token == 0)
	{
		iter->token |= TOKEN_INS;
		iter->token <<= 4;
		if ((op = token_ins(iter->line)) > -1)
		{
			iter->token <<= 4;
			iter->token |= op + 1;
			printf("[GOT_INS][%s]\n", g_op_tab[op].name);
			len = g_op_tab[op].nlen;
			clear_wsp(iter);
			while (--len > -1)
			{
				++(iter->count);
				++(iter->line);
			}
			lexer_ins_sub(iter);
			end_line(iter);
		}
	}
}
