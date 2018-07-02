/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 20:21:46 by fmadura           #+#    #+#             */
/*   Updated: 2018/07/03 01:24:58 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	put_error_first(t_iter *iter, char *line)
{
	if (iter->token == LABEL_ERR2)
		printf("%s\n%*c\nNeed space here\n", line, iter->count + 1, '^');
	else if (iter->token == HEAD_ERR1)
		printf("%s\n%*c\nSpace after name.\n", line, iter->count, '^');
	else if (iter->token == HEAD_ERR2)
		printf("%s\n%*c\nSpace after comment.\n", line, iter->count, '^');
	else if (iter->token == HEAD_ERR0)
		printf("%s\n%*c\nIncorrect word\n", line, iter->count + 1, '^');
	else if (iter->token == NAME_ERR0)
		printf("%s\n%*c\nName over 128 char.\n", line, iter->count, '^');
	else if (iter->token == COMT_ERR0)
		printf("%s\n%*c\nComment over 2048 char\n", line, iter->count, '^');
	else if (iter->token == ENDLI_ERR)
		printf("%s\n%*c\nEndline must be empty.\n", line, ++iter->count, '^');
	line ? free(line) : 0;
	iter_del(iter);
	exit(0);
}

void	put_error(t_iter *iter, char *line)
{
	if (iter->token == INS_ERR0)
		printf("%s\n%*c\nUndefined Instruction.\n", line, iter->count, '^');
	else if (iter->token == PAR_ERR0)
		printf("%s\n%*c\nIncorrect parameter.\n", line, iter->count, '^');
	else if (iter->token == PAR_ERR1)
		printf("%s\n%*c\nInvalid number of args.\n", line, iter->count, '^');
	else if (iter->token == PAR_ERR2)
		printf("%s\n%*c\nInvalid type of parameter.\n", line, iter->count, '^');
	else if (iter->token == NAME_ERR1)
		printf("%s\n%*c\nCan't be empty\n", line, iter->count, '^');
	else if (iter->token == LABEL_ERR3)
		printf("%s\n%*c\nRedefinition of label.\n", line, ++iter->count, '^');
	else if (iter->token == LABEL_ERR4)
		printf("%s\n%*c\nSpace after label.\n", line, ++iter->count, '^');
	if (iter->token == READ_ERR)
	{
		printf("Read error\n");
		exit(0);
	}
	put_error_first(iter, line);
}
