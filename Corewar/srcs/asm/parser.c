/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 14:20:50 by fmadura           #+#    #+#             */
/*   Updated: 2018/06/26 18:20:17 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static t_ops	*parse_sub(t_iter *iter, char *line)
{
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
		if (!first)
		{
			first = parse_sub(iter, line);
			itera = first;
		}
		else
		{
			itera->next = parse_sub(iter->line);
			itera = itera->next;
		}
		printf("%s\n", line);
		free(line);
		line = NULL;
		iter->iter = iter->iter->next;
	}
	free(line);
}
