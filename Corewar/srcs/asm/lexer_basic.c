/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 11:12:05 by fmadura           #+#    #+#             */
/*   Updated: 2018/06/22 14:05:53 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_op	g_op_tab[17];

void	end_line(int count, char **line)
{
	while (**line && ft_isspace(**line))
	{
		++count;
		++(*line);
	}
	if (**line == ';')
	{
		printf("[INS_COM][%d]", count);
		printf("[INS_END][%d]", count);
	}
	else if (!(**line))
		printf("[INS_END][%d]", count);
	else if (**line == '#')
		printf("[INS_COM][%d]", count);
	else
		printf("[INS_ERR][%d]", count);

}

void	lexer_ins_sub(char **line, unsigned int *token, int *count) 
{
	int sep;

	sep = 0;
	while (**line && ft_isspace(**line))
	{
		++(*count);
		++(*line);
	}
	while (sep < 3)
	{
		if (**line == '%')
		{
			++(*count);
			++(*line);
			if (**line == ':')
			{
				*token <<= 4;
				*token |= INS_DIR;
				printf("[INS_DIR][%d]", *count);
				++(*count);
				++(*line);
			}
			else if (ft_isdigit(**line) || **line == '-')
			{
				*token <<= 4;
				*token |= INS_DIR;
				printf("[INS_DIR][%d]", *count);
			}
		}
		else if (**line == 'r')
		{
			++(*count);
			++(*line);
			*token <<= 4;
			*token |= INS_REG;
			printf("[INS_REG][%d]", *count);
		}
		else if (ft_isdigit(**line) || **line == '-')
		{
			*token <<= 4;
			*token |= INS_REG;	
			printf("[INS_IND][%d]", *count);
		}
		else
			break;
		while (**line && (ft_isdigit(**line) ||
			ft_isalpha(**line) || **line == '_' || **line == '-'))
		{
			++(*count);
			++(*line);
		}
		if (**line && **line == ',')
		{
			*token <<= 4;
			*token |= INS_SEP;
			printf("[INS_SEP][%d]", *count);
			++(*count);
			++(*line);
		}
		else
			break;
		while (**line && ft_isspace(**line))
		{
			++(*count);
			++(*line);
		}
		sep++;
	}
}

void	lexer_ins(char **line, unsigned int *token, int lnb, int *count)
{
	int		len;
	int		op;

	len = 0;
	op = 0;
	if (line && *token == 0)
	{
		*token |= TOKEN_INS;
		*token <<= 4;
		printf("[TOKEN_INS][%d]\n", lnb);
		if ((op = token_ins(*line)) > -1)
		{
			*token <<= 4;
			*token |= op + 1;
			printf("[GOT_INS][%s]\n", g_op_tab[op].name);
			len = g_op_tab[op].nlen;
			while (**line && ft_isspace(**line))
			{
				++(*count);
				++(*line);
			}
			while (--len > -1)
			{
				++(*count);
				++(*line);
			}
			lexer_ins_sub(line, token, count);
			end_line(*count, line);
		}
	}
}

void	lexer_basics(char *line, unsigned int *token, int lnb, int *count)
{
	if (line && *line == COMMENT_CHAR)
		*token |= TOKEN_COM;
	else if (line && token_lab(line))
		*token |= TOKEN_LAB;
	else if (line && *line == '.')
	{
		*token |= TOKEN_HEA;
		*token <<= 4; 
		if (ft_strnequ(line, NAME_CMD_STRING, 5))
			*token |= HEAD_NAME;
		else if (ft_strnequ(line, COMMENT_CMD_STRING, 8))
			*token |= HEAD_COMT;
		else
			*token |= HEAD_ERRR;
		return;
	}
	else if (line && token_wsp(line))
		*token |= TOKEN_SPA;
	*token <<= 4; 
}
