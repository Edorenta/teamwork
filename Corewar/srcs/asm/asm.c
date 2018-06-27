/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 12:37:38 by fmadura           #+#    #+#             */
/*   Updated: 2018/06/26 18:28:48 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include <strings.h>

int		ft_asm(char **argv)
{
	int		fd; 
	t_iter	*iter;

	//error handling here
	iter = NULL;
	if ((iter = iter_new()) != NULL)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd > 0)
		{
			iter = lexer(iter, fd);
			parser(iter, fd);
			close(fd);
		}
	}
	iter_del(iter);
	return (0);
}
