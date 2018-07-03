/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 11:12:05 by fmadura           #+#    #+#             */
/*   Updated: 2018/07/03 03:32:02 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_op		g_op_tab[17];

int			write_fill(int fd, long value, int size, int type)
{
	char	print[4];

	if (type == 1)
		print[0] = (value);
	else if (type == 2)
	{
		print[1] = (value & 0xFF);
		print[0] = ((value & 0xFF00) >> 8);
	}
	else if (type == 3)
	{
		print[3] = (value & 0xFF);
		print[2] = ((value & 0xFF00) >> 8);
		print[1] = ((value & 0xFF0000) >> 16);
		print[0] = ((value & 0xFF000000) >> 24);
	}
	else if (type == 4)
	{
		print[3] = (value & 0xFF);
		print[2] = (value & 0xFF00) >> 8;
		print[1] = (value & 0xFF0000) >> 16;
		print[0] = (value & 0xFF000000) >> 24;
	}
	return (write(fd, &print, size));
}

int			write_args(int fd, t_ops *ops)
{
	int		c;
	int		num;
	int		type;

	c = -1;
	while (++c < 3)
	{
		num = (ops->args[c]);
		if (num == -1 || num > 3)
			break ;
		else if (num == 1)
			write_fill(fd, ops->argv[c], 1, 1);
		else if (num == 2)
		{
			type = (ops->argv[c] == -1);
			if (g_op_tab[ops->type - 1].label)
				write_fill(fd, type ? ops->label[c] : ops->argv[c], 4, 3);
			else
				write_fill(fd, type ? ops->label[c] : ops->argv[c], 2, 2);
		}
		else if (num == 3)
			write_fill(fd, ops->argv[c], 2, 2);
	}
	return (1);
}

void		write_head(int fd, t_header head)
{
	const char	header[4] = {0, 0xea, 0x83, 0xf3};
	int			pad;

	pad = 0;
	write(fd, header, 4);
	write(fd, head.prog_name, PROG_NAME_LENGTH);
	write(fd, &pad, 4);
	write_fill(fd, head.prog_size, 4, 4);
	write(fd, head.comment, COMMENT_LENGTH);
	write(fd, &pad, 4);
}

void		write_ops(int fd, t_ops *ops)
{
	t_ops		*iter;

	iter = ops;
	while (iter)
	{
		write(fd, &iter->type, 1);
		if (g_op_tab[iter->type - 1].octal)
			write(fd, &iter->opcode, 1);
		write_args(fd, iter);
		iter = iter->next;
	}
}

void		write_all(char *filename, t_ops *ops, t_header header)
{
	int			fd;

	fd = open(filename, O_WRONLY | O_CREAT, S_IRWXG | S_IRWXU | S_IRWXO);
	header.prog_size = ops_get_len(ops);
	write_head(fd, header);
	write_ops(fd, ops);
	close(fd);
}
