/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 12:37:38 by fmadura           #+#    #+#             */
/*   Updated: 2018/06/29 02:44:42 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include <strings.h>

int		ft_asm(char **argv)
{
	int		fd; 
	t_iter		*iter;
	t_ops		*ops;
	t_header	head;

	//error handling here
	iter = iter_new();
	if (iter == NULL)
		return (1);
	else
	{
		fd = open(argv[1], O_RDONLY);
		if (fd > 0)
		{
			iter = lexer(iter, fd);
			ops = parser(iter, fd);
			head = iter_head(iter);
			iter_del(iter);
			write_ops("test.cor", ops, &head);
			ops_del(ops);
			close(fd);
		}
	}
	return (0);
}
