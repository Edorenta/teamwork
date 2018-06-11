/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 12:37:38 by fmadura           #+#    #+#             */
/*   Updated: 2018/06/11 20:04:16 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include <strings.h>

void	write_head(int fd,t_header *head)
{
	write(fd, head->magic, 4);
	write(fd, head->prog_name, PROG_NAME_LENGTH);
	write(fd, head->comment, COMMENT_LENGTH);
}

int main(void)
{
	int 		fd;
	t_header	head;
	
	fd = open("exe.cor", O_WRONLY | O_CREAT, S_IRWXG | S_IRWXU | S_IRWXO);
	write_head(fd, &head);
	close(fd);
	return (0);
}
