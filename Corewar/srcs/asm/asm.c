/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 12:37:38 by fmadura           #+#    #+#             */
/*   Updated: 2018/06/13 13:42:50 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include <strings.h>

void	lex(int fd);

int main(int argc, char **argv)
{
	if (argc > 1)
	{
		int fd = open(argv[1], O_RDONLY);
		if (fd > 0)
		{
			lex(fd);
			close(fd);
		}
	}
	//write_head();
	return (0);
}
