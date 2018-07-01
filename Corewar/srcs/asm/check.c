/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/16 15:02:01 by fmadura           #+#    #+#             */
/*   Updated: 2018/07/01 20:54:15 by jyildiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

# define A_LIVE(x)	x == 0x01
# define A_LD(x)	x == 0x02
# define A_ST(x)	x == 0x03
# define A_ADD(x)	x == 0x04
# define A_SUB(x)	x == 0x05
# define A_AND(x)	x == 0x06
# define A_OR(x)	x == 0x07
# define A_XOR(x)	x == 0x08
# define A_ZJMP(x)	x == 0x09
# define A_LDI(x)	x == 0x0A
# define A_STI(x)	x == 0x0B
# define A_FORK(x)	x == 0x0C
# define A_LLD(x)	x == 0x0D
# define A_LLDI(x)	x == 0x0E
# define A_LFORK(x)	x == 0x0F
# define A_AFF(x)	x == 0x10

t_op	g_op_tab[17];

int		token_com(char *line, int *count)
{
	char	*iter;

	iter = line;
	if (!(iter))
		return (0);
	while (*iter && ft_isspace(*iter))
	{
		++(*count);
		++iter;
	}
	return (*iter == '#' || *iter == ';');
}

int		token_wsp(char *line, int *count)
{
	char	*iter;

	if (!(line))
		return (0);
	iter = line;
	while (*iter && ft_isspace(*iter))
	{
		++(*count);
		++iter;
	}
	return (!(*iter));
}

int		token_lab(t_iter *itr)
{
	char	*iter;
	int		count;

	count = 0;
	iter = itr->line;
	if (!(iter))
		return (0);
	while (*iter && (ft_isalpha(*iter) || ft_isdigit(*iter) || *iter == '_'))
	{
		++iter;
		count++;
	}
	if (*iter == ':')
	{
		++iter;
		count++;
		if ((*iter) && ((*iter) != ' ' && (*iter) != '\t'))
		{
			itr->token |= LABEL_ERR2;
			itr->count = count;
			return (-1);
		}
		itr->count = count;
		itr->line = iter;
		return (1);
	}
	return (0);
}

int		token_ins(t_iter *iter, char *line)
{
	int	i;
	int	len;
	int	ret;
	int count;

	ret = -1;
	i = 0;
	count = 0;
	while (*line && ft_isspace(*line))
	{
		count++;
		++line;
	}
	if (!(*line))
		ret = -2;
	while (i < 16)
	{
		len = ft_strlen(g_op_tab[i].name);
		if (ft_strnequ(line, g_op_tab[i].name, len) == 1)
		{
			if (ft_isspace(line[len]))
				ret = i;
			else
				count = count + len;
		}
		i++;
	}
	if (ret == -1)
	{
		iter->token = INS_ERR0;
		iter->count += count;
	}
	return (ret);
}
