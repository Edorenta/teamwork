/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 11:12:05 by fmadura           #+#    #+#             */
/*   Updated: 2018/06/13 19:45:28 by fmadura          ###   ########.fr       */
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
