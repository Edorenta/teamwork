/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 11:12:05 by fmadura           #+#    #+#             */
/*   Updated: 2018/06/28 14:35:40 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	write_head(char *filename, t_header head)
{
	int 		fd;
	const char	header[4] = {0, 0xea, 0x83, 0xf3};
	
	fd = open(filename, O_WRONLY | O_CREAT, S_IRWXG | S_IRWXU | S_IRWXO);
	write(fd, header, 4);
	write(fd, head.prog_name, PROG_NAME_LENGTH);
	write(fd, head.comment, COMMENT_LENGTH);
	close(fd);
}

void	write_ops(char *filename, t_ops *ops)
{
	int		fd;
	t_ops	*iter;
	
	fd = open(filename, O_WRONLY | O_CREAT, S_IRWXG | S_IRWXU | S_IRWXO);
	iter = ops;
	while (iter)
	{
		write(fd, (const char *)&iter->type, 1);
		write(fd, (const char *)&iter->opcode, 1);
		iter = iter->next;
	}
	close(fd);
}
