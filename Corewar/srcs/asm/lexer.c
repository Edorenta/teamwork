/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 11:12:05 by fmadura           #+#    #+#             */
/*   Updated: 2018/06/13 19:45:28 by fmadura          ###   ########.fr       */
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

void	lex(int fd)
{
	char	*line;
	int		ret;
	int		op;
	int		len;
	int		lnb;

	lnb = 0;
	line = NULL;
	while ((ret = get_next_line(fd,&line)) > 0)
	{
		printf("\n%s\n", line);
		int count = 0;
		if (line && line[0] == COMMENT_CHAR)
			printf("[TOKEN_COM][%d]\n", lnb);
		else if (line && token_lab(line))
			printf("[TOKEN_LAB][%d]\n", lnb);
		else if (line && line[0] == '.')
		{
			printf("[TOKEN_HEA][%d]", lnb);
			if (ft_strnequ(line, NAME_CMD_STRING, 5))
				printf("\t[HEAD_NAM]");
			else if (ft_strnequ(line, COMMENT_CMD_STRING, 8))
				printf("\t[HEAD_COM]");
			else
				printf("\t[HEAD_ERR]");
			printf("[TOKEN_END]\n");
		}
		else if (line && token_wsp(line))
			printf("[TOKEN_SPA][%d]\n\n",lnb);
		else if (line)
		{
			printf("[TOKEN_INS][%d]", lnb);
			if ((op = token_ins(line)) > -1)
			{
				printf("[GOT_INS][%s]", g_op_tab[op].name);
				len = g_op_tab[op].nlen;
				while (*line && ft_isspace(*line))
				{
					++count;
					++line;
				}
				while (--len > -1)
				{
					++count;
					++line;
				}
				int sep = 0;
				while (*line && ft_isspace(*line))
				{
					++count;
					++line;
				}
				while (sep < 3)
				{
					if (*line == '%')
					{
						++count;
						++line;
						if (*line == ':')
						{
							printf("[INS_IND][%d]", count);
							++count;
							++line;
						}
						else if (ft_isdigit(*line) || *line == '-')
							printf("[INS_IND][%d]", count);
					}
					else if (*line == 'r')
					{
						++count;
						++line;
						printf("[INS_REG][%d]", count);
					}
					else if (ft_isdigit(*line) || *line == '-')
					{	
						printf("\t\t[INS_DIR][%d]", count);
					}
					else
						break;
					while (*line && (ft_isdigit(*line) || ft_isalpha(*line) || *line == '_' || *line == '-'))
					{
						++count;
						++line;
					}
					if (*line && *line == ',')
					{
						printf("\t\t[GOT_SEP][%d] %c", count, *line);
						++count;
						++line;
					}
					else
						break;
					while (*line && ft_isspace(*line))
					{
						++count;
						++line;
					}
					sep++;
				}
				while (*line && ft_isspace(*line))
					++line;
				if (*line == ';')
				{
					printf("\t[INS_COM] %c", *line);
					printf("\t[INS_END] ");
				}
				else if (!(*line))
					printf("\t[INS_END] ");
				else if (*line == '#')
					printf("\t[INS_COM] %s", line);
				else
					printf("\t[INS_ERR] %c", *line);
			}
			printf("[TOKEN_END]\n");
		}
		++lnb;
	}
}
