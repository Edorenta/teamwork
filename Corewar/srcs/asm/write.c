/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 11:12:05 by fmadura           #+#    #+#             */
/*   Updated: 2018/06/14 14:17:24 by fmadura          ###   ########.fr       */
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

void	token_binary(t_tok *tok)
{
	return;
}

void	write_ins(char *filename, t_tok *tokens)
{
	int		fd;
	
	fd = open(filename, O_WRONLY | O_CREAT, S_IRWXG | S_IRWXU | S_IRWXO);
	while (tokens)
	{
		token_binary()
		tokens = tokens->next;
	}
}
