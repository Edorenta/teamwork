/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 11:12:05 by fmadura           #+#    #+#             */
/*   Updated: 2018/06/13 10:56:12 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
# define LX_LIVE	0x01
# define LX_LD		0x02
# define LX_ST		0x03
# define LX_ADD		0x04
# define LX_SUB		0x05
# define LX_AND		0x06
# define LX_OR		0x07
# define LX_XOR		0x08
# define LX_ZJMP	0x09
# define LX_LDI		0x0A
# define LX_STI		0x0B
# define LX_FORK	0x0C
# define LX_LLD		0x0D
# define LX_LLDI	0x0E
# define LX_LFORK	0x0F
# define LX_AFF		0x10

# define TOKEN_COM	0b001
# define TOKEN_LAB	0b010
# define TOKEN_INS	0b011
# define TOKEN_NAM	0b100

t_op	g_op_tab[17];

int		token_wspace(char *line)
{
	if (line)
	{
		while (ft_isspace(*line))
			++line;
		return (!(*line));
	}
	return (1);
}
int		token_lab(char *line)
{
	if (!(line))
		return (0);
	while (*line && (ft_isalpha(*line) || ft_isdigit(*line)))
		++line;	
	return (*line == ':');
}

int		token_ins(char *line)
{
	int i;
	int len;

	i = 0;
	while (*line && ft_isspace(*line))
		++line;
	while (i < 16)
	{
		len = ft_strlen(g_op_tab[i].name);
		if (ft_strnequ(line, g_op_tab[i].name, len) == 1)
			return (i);
		i++;
	}
	return (-1);
}

void	lex(int fd)
{
	char	*line;
	int		ret;
	int		op;
	int		len;

	line = NULL;
	while ((ret = get_next_line(fd,&line)) > 0)
	{
		if (line && line[0] == COMMENT_CHAR)
			printf("[TOKEN_COM] %s \n\n", line);
		else if (line && token_lab(line))
			printf("[TOKEN_LAB] %s \n\n", line);
		else if (line && line[0] == '.')
			printf("[TOKEN_HEA] %s \n\n", line);
		else if (line && token_wspace(line))
			printf("[TOKEN_SPA] %s \n\n", line);
		else if (line)
		{
			printf("[TOKEN_INS] %s \n", line);
			if ((op = token_ins(line)) > -1)
			{
				printf("\t[GOT_INS] %s\n", g_op_tab[op].name);
				len = g_op_tab[op].nlen;
				while (--len > -1)
					++line;
				int sep = 0;
				while (*line && ft_isspace(*line))
					++line;
				while (sep < 3)
				{
					if (*line == '%')
					{
						++line;
						if (*line == ':')
						{
							printf("\t\t[INS_IND] %%%s\n", line);
							++line;
						}
						else if (ft_isdigit(*line))
							printf("\t\t[INS_DIR] %%%d\n", ft_atoi(line));
					}
					else if (*line == 'r')
					{
						++line;
						printf("\t\t[INS_REG] r%d\n", ft_atoi(line));
					}
					while (*line && (ft_isdigit(*line) || ft_isalpha(*line)))
						++line;
					if (*line && *line == ',')
					{
						printf("\t\t[GOT_SEP] %c\n", *line);
						++line;
					}
					else
						break;
					if (*line == ' ')
						++line;
					else
						break;
					sep++;
				}
			}
			printf("\n");
		}
	}
}
