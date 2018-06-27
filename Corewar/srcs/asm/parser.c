/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 14:20:50 by fmadura           #+#    #+#             */
/*   Updated: 2018/06/27 17:46:16 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static t_ops	*parse_sub(t_tok *token, char *line)
{
	t_ops	*new;
	t_tok	*iter;
	int		argc;

	argc = 0;
	iter = token->list;
	new = ops_new();
	new->type = (token->type & 0xFF);
	while (iter)
	{
		if ((iter->type & 0x0F) <= 0x6)
		{
			new->args[argc] = (iter->type >> 1);
			new->argv[argc] = ft_atoi(&line[iter->pos]);
			printf("argv %ld\n", new->argv[argc]);
			argc++;
		}
		iter = iter->next;
	}
	ops_debug(new);
	tok_tostring(token);
	return (new);
}

void	parser(t_iter *iter, int fd)
{
	char	*line;
	int		ret;
	t_ops	*first;
	t_ops	*itera;

	line = NULL;
	first = NULL;
	itera = NULL;
	ret = 0;
	iter->iter = iter->first;
	// Set error here
	if (lseek(fd, 0, SEEK_SET) < 0)
		return;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if ((iter->iter->type & 0x600))
		{
			printf("\nline{%s}\n", line);
			if (!first)
			{
				first = parse_sub(iter->iter, line);
				itera = first;
			}
			else
			{
				itera->next = parse_sub(iter->iter, line);
				itera = itera->next;
			}
		}
		free(line);
		line = NULL;
		iter->iter = iter->iter->next;
	}
	free(line);
}
