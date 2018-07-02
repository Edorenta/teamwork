/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 11:12:05 by fmadura           #+#    #+#             */
/*   Updated: 2018/07/02 04:15:52 by jyildiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_op	g_op_tab[17];

char	*lexer_head(unsigned int token)
{
	return ((token & 0x2) ? "HEAD_NAME" : "HEAD_COMMENT");
}

char	*lexer_label(unsigned int token)
{
	token >>= 4;
	if (token == TOKEN_COM)
		return "TOKEN_COMMENT";
	if (token == TOKEN_LAB)
		return "TOKEN_LABEL";
	if (token == TOKEN_HEA)
		return "TOKEN_HEAD";
	if (token == TOKEN_SPA)
		return "TOKEN_SPACE";
	return "TOKEN_ERROR";
}

static t_tok	*lexer_token(t_iter *iter)
{
	t_tok			*new;
	unsigned int	token;
	int 			lnb;
	int 			pos;

	token = iter->token;
	pos = iter->count;
	lnb = iter->lnb;
	new = NULL;
	if (!(token & 0x0F))
	{
		new = token_iter(iter, lexer_label(token));
		if ((new->type >> 4) == TOKEN_LAB)
			lab_create(iter);
		//exist here;
	}
	else
	{
		new = token_create(token, lexer_label(token), lnb, 0);
		token = token & 0xF;
		new->list = token_iter(iter, lexer_head(token));
	}
	return (new);
}

void	put_error(t_iter *iter, char *line)
{
	//iter_del(iter);
	//printf("iter->token : %x\n", iter->token);
	if (iter->token == LABEL_ERR2)
		printf("%s\n%*c\nApres les deux points il faut un espace.\n", line, iter->count + 1 , '^');
	else if (iter->token == HEAD_ERR1)
		printf("%s\n%*c\nIl faut un espace apres name.\n", line, iter->count, '^');
	else if (iter->token == HEAD_ERR2)
		printf("%s\n%*c\nIl faut un espace apres comment.\n", line, iter->count , '^');
	else if (iter->token == HEAD_ERR0)
		printf("%s\n%*c\nCe n'est pas un mot correct (name ou comment).\n", line, iter->count + 1 , '^');
	else if (iter->token == NAME_ERR0)
		printf("%s\n%*c\nLe nom ne peut pas depasser les 128 caracteres.\n", line, iter->count, '^');
	else if (iter->token == COMT_ERR0)
		printf("%s\n%*c\nLes commentaires ne peuvent pas depasser les 2048 caracteres.\n", line, iter->count , '^');
	else if (iter->token == ENDLI_ERR)
		printf("%s\n%*c\nLa ligne se termine soit par un commentaire soit par rien.\n", line, iter->count + 1 , '^');
	else if (iter->token == INS_ERR0)
		printf("%s\n%*c\nInstruction non defini.\n", line, iter->count, '^');
	else if (iter->token == PAR_ERR0)
		printf("%s\n%*c\nCela n'est pas un parametre valable.\n", line, iter->count, '^');
	else if (iter->token == PAR_ERR1)
		printf("%s\n%*c\nPas le bon nombre de parametre.\n", line, iter->count, '^');
	else if (iter->token == PAR_ERR2)
		printf("%s\n%*c\nPas le bon type de parametre.\n", line, iter->count, '^');
	else if (iter->token == NAME_ERR1)
		printf("%s\n%*c\nLe nom/commentaire, ne peut pas etre vide.\n", line, iter->count, '^');
	exit (0);
}

t_iter	*lexer(t_iter *iter, int fd)
{
	char			*line;
	int				ret;
	long			basic;

	while ((ret = get_next_line(fd, &line)) > 0)
	{
		iter->line = line;
		iter->count = 0;
		iter->token = 0;
		basic = lexer_basics(iter);
		if (basic == (TOKEN_LAB << 4))
		{
			if (!iter->first)
			{
				iter->first = lexer_token(iter);
				iter->iter = iter->first;
			}
			else
			{
				iter->iter->next = lexer_token(iter);
				iter->iter = iter->iter->next;
			}
			iter->token = 0;
			if (lexer_ins(iter) == -1)
				put_error(iter, line);
		}
		else if (basic == 0)
		{
			if (lexer_ins(iter) == -1)
				put_error(iter, line);
		}
		else if (basic == -1)
			put_error(iter, line);
		else if (!iter->first)
		{
			iter->first = lexer_token(iter);
			iter->iter = iter->first;
		}
		else
		{
			iter->iter->next = lexer_token(iter);
			iter->iter = iter->iter->next;
		}
		++(iter->lnb);
		free(line);
		iter->line = NULL;
		line = NULL;
	}
	return (iter);
}
