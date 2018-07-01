/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 11:12:05 by fmadura           #+#    #+#             */
/*   Updated: 2018/06/28 16:49:58 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		write_head(int fd, t_header head)
{
	const char	header[4] = {0, 0xea, 0x83, 0xf3};

	write(fd, header, 4);
	write(fd, head.prog_name, PROG_NAME_LENGTH);
	write(fd, head.comment, COMMENT_LENGTH);
}

static int	write_args(int fd, t_ops *ops)
{
	int		count;
	int		num;

	count = -1;
	num = 0;
	while (++count < 3)
	{
		num = (ops->args[count]);
		if (num == -1)
			break;
		else if (num == 1)
			write(fd, (const char *)ops->argv[count], 1);
		else if (num == 2)
		{
			if (ops->label[count] == -1)
				write(fd, (const char *)ops->argv[count], 2);
			else
				write(fd, (const char *)ops->label[count], 4);
			
		}
		else if (num == 3)
			write(fd, (const char *)ops->argv[count], 2);
		else
			break;
	}
	return (1);
}

void		write_ops(char *filename, t_ops *ops, t_header *head)
{
	int		fd;
	t_ops		*iter;
	
	fd = open(filename, O_WRONLY | O_CREAT, S_IRWXG | S_IRWXU | S_IRWXO);
	write_head(fd, *head);
	iter = ops;
	while (iter)
	{
		write(fd, (const char *)&iter->type, 1);
		write(fd, (const char *)&iter->opcode, 1);
		write_args(fd, ops);
		iter = iter->next;
	}
	close(fd);
}
