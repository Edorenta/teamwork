/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 12:37:38 by fmadura           #+#    #+#             */
/*   Updated: 2018/06/13 09:59:38 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include <strings.h>

void	lex(int fd);
void	write_head(void)
{
	int 		fd;
	t_header	head;
	
	fd = open("exe.cor", O_WRONLY | O_CREAT, S_IRWXG | S_IRWXU | S_IRWXO);
	
	const char	header[4] = {0, 0xea, 0x83, 0xf3};

	write(fd, header, 4);
	write(fd, head.prog_name, PROG_NAME_LENGTH);
	write(fd, head.comment, COMMENT_LENGTH);
	close(fd);
}

int main(void)
{
	int fd = open("../../rsrc/examples/bee_gees.s", O_RDONLY);
	lex(fd);
	close(fd);
	//write_head();
	return (0);
}
