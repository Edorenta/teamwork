/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 20:21:46 by fmadura           #+#    #+#             */
/*   Updated: 2018/07/03 05:43:20 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

inline static void	jump(int x, char c)
{
	char	s[x];
	int		i;

	i = -1;
	while (++i < x - 1)
		s[i] = ' ';
	s[i] = c;
	ft_putnstr(s, x);
}

inline static char	*strpl(char *src, char from, char to)
{
	int		i;

	i = -1;
	while (++i < ft_strlen(src))
		src[i] == from ? src[i] = to : 0;
	return (src);
}

inline static void	jump_print(const char *msg, char *line, int x, char c)
{
	line = strpl(line, '\t', ' ');
	ft_printf("%s\n", line);
	jump(x + 1, c);
	ft_putstr(msg);
}

void				put_error_first(t_iter *iter, char *line)
{
	if (iter->token == LABEL_ERR2)
		jump_print("\nNeed space here\n", line, iter->count + 1, '^');
	else if (iter->token == HEAD_ERR1)
		jump_print("\nSpace after name.\n", line, iter->count, '^');
	else if (iter->token == HEAD_ERR2)
		jump_print("\nSpace after comment.\n", line, iter->count, '^');
	else if (iter->token == HEAD_ERR0)
		jump_print("\nIncorrect word\n", line, iter->count + 1, '^');
	else if (iter->token == NAME_ERR0)
		jump_print("\nName over 128 char.\n", line, iter->count, '^');
	else if (iter->token == COMT_ERR0)
		jump_print("\nComment over 2048 char\n", line, iter->count, '^');
	else if (iter->token == ENDLI_ERR)
		jump_print("\nEndline must be empty.\n", line, ++iter->count, '^');
	iter_del(iter);
	exit(0);
}

void				put_error(t_iter *iter, char *line)
{
	if (iter->token == INS_ERR0)
		jump_print("\nUndefined Instruction.\n", line, iter->count, '^');
	else if (iter->token == PAR_ERR0)
		jump_print("\nIncorrect parameter.\n", line, iter->count, '^');
	else if (iter->token == PAR_ERR1)
		jump_print("\nInvalid number of args.\n", line, iter->count, '^');
	else if (iter->token == PAR_ERR2)
		jump_print("\nInvalid type of parameter.\n", line, iter->count, '^');
	else if (iter->token == NAME_ERR1)
		jump_print("\nCan't be empty\n", line, iter->count, '^');
	else if (iter->token == LABEL_ERR3)
		jump_print("\nRedefinition of label.\n", line, ++iter->count, '^');
	else if (iter->token == LABEL_ERR4)
		jump_print("\nSpace after label.\n", line, ++iter->count, '^');
	else if (iter->token == 0)
		ft_printf("%s\nNo name & comment.\n", line);
	if (iter->token == READ_ERR)
	{
		ft_putstr("Read error\n");
		exit(0);
	}
	put_error_first(iter, line);
}
