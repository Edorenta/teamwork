/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 12:37:38 by fmadura           #+#    #+#             */
/*   Updated: 2018/07/03 04:35:25 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include <strings.h>

static int	ft_filename(char *filename, char file[2052])
{
	int		len;

	len = ft_strlen(filename);
	if (len > 2 && len < 2047)
	{
		len -= 2;
		if (filename[len] != '.')
		{
			printf("Invalid file, please use an '.s' extension \n");
			return (0);
		}
		if (filename[++len] != 's')
		{
			printf("Invalid file, please use an '.s' extension \n");
			return (0);
		}
		ft_strncpy(file, filename, --len);
		ft_strncpy(&file[len], ".cor", 4);
		return (1);
	}
	else
		printf("Invalid file size\n");
	return (0);
}

int			ft_asm(char **argv)
{
	int		fd;
	char	filename[2052];
	t_iter	*iter;
	t_ops	*ops;

	iter = iter_new();
	if (iter != NULL && ft_filename(argv[1], filename))
	{
		fd = open(argv[1], O_RDONLY);
		if (fd > 0)
		{
			iter = lexer(iter, fd);
			ops = parser(iter, fd, 0);
			iter->header.prog_size = ops_get_len(ops);
			ops_get_lab(iter, ops);
			write_all(filename, ops, iter->header);
			iter_del(iter);
			ops_del(ops);
		}
		else
			printf("File descriptor invalid, file is missing\n");
		close(fd);
		return (0);
	}
	return (1);
}
