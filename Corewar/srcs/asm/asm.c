/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 12:37:38 by fmadura           #+#    #+#             */
/*   Updated: 2018/06/11 19:30:06 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include <strings.h>

void	write_head(header_t)

int main(void)
{
	int fd;
	
	fd = open("exe.cor", O_WRONLY | O_CREAT, S_IRWXG | S_IRWXU | S_IRWXO);
	write_head(fd);
	close(fd);
	return (0);
}
