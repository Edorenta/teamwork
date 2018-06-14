/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 12:37:38 by fmadura           #+#    #+#             */
/*   Updated: 2018/06/14 19:43:05 by fmadura          ###   ########.fr       */
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
			//lex(fd);
			close(fd);
		}
	}
	printf("test %x \n", CHK_LIVE(0x6012));
	printf("test %x \n", CHK_LD(0x602286));
	printf("test %x \n", CHK_LD(0x602486));
	printf("test %x \n", CHK_LD(0x602686));
	printf("test DIR %x \n", CHK_ST(0x603682));
	printf("test IND %x \n", CHK_ST(0x603684));
	printf("test REG %x \n", CHK_ST(0x603686));
	//write_head();
	return (0);
}
