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
	// Set error here
	if (lseek(fd, 0, SEEK_SET) < 0)
		return;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		printf("%s\n", line);
		free(line);
		line = NULL;
	}
}
