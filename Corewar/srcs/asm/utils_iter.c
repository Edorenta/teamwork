/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_iter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 20:12:16 by fmadura           #+#    #+#             */
/*   Updated: 2018/07/02 20:15:38 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int		head_get(t_header *head, char *line, int boolean, int count)
{
	char	*dup;

	count = 0;
	dup = line;
	if (line)
	{
		while (*dup && *dup != '"')
			++dup;
		if (*dup == '"')
		{
			++dup;
			while (*dup && *dup != '"')
			{
				if (boolean)
					head->prog_name[count] = *dup;
				else
					head->comment[count] = *dup;
				++dup;
				++count;
			}
			if (*dup == '"')
				return (1);
		}
	}
	return (0);
}

/*
** error here
*/

void			iter_head(char *line, t_iter *iter, int token)
{
	t_tok		*tok;

	tok = NULL;
	if (iter)
	{
		tok = iter->first;
		while (tok)
		{
			if (tok->type == token)
				head_get(&iter->header, line, (token == 0x82), 0);
			tok = tok->next;
		}
	}
}
