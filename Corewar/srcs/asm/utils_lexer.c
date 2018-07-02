/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 11:12:05 by fmadura           #+#    #+#             */
/*   Updated: 2018/07/02 23:31:49 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_op	g_op_tab[17];

void		end_while(t_iter **iter, char *line)
{
	++((*iter)->lnb);
	free(line);
	(*iter)->line = NULL;
	line = NULL;
}

void		err_read(t_iter *iter)
{
	iter->token = READ_ERR;
	put_error(iter, NULL);
}
