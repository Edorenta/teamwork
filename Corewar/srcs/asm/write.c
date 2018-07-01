/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 11:12:05 by fmadura           #+#    #+#             */
/*   Updated: 2018/07/01 21:34:23 by fmadura          ###   ########.fr       */
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

static int	write_fill(int fd, long value, int size, int type)
{
	char	print[4];

	if (type == 1)
		print[0] = (value);
	else if (type == 2)
	{
		print[0] = (value & 0xFF);
		print[1] = (value & 0xFF00);
	}
	else if (type == 3)
	{	
		print[0] = (value & 0xFF);
		print[1] = (value & 0xFF00);
		print[2] = (value & 0xFF0000);
		print[3] = (value & 0xFF000000);
	}
	return (write(fd, &print, size));
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
		{
			write_fill(fd, ops->argv[count], 1, 1);
		}
		else if (num == 2)
		{
			if (ops->label[count] == -1)
				write_fill(fd, ops->argv[count], 2, 2);
			else
				write_fill(fd, ops->label[count], 4, 3);		
		}
		else if (num == 3)
			write_fill(fd, ops->argv[count], 2, 2);
		else
			//error here;
			break;
	}
	return (1);
}

void		write_ops(int fd, t_ops *ops)
{
	t_ops		*iter;
	
	iter = ops;
	while (iter)
	{
		write(fd, (const char *)&iter->type, 1);
		write(fd, (const char *)&iter->opcode, 1);
		write_args(fd, ops);
		iter = iter->next;
	}
}

void		write_all(char *filename, t_ops *ops, t_header header)
{
	int			fd;
	
	fd = open(filename, O_WRONLY | O_CREAT, S_IRWXG | S_IRWXU | S_IRWXO);
	write_head(fd, header);
	write_ops(fd, ops);
	close(fd);
}
