/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/16 15:02:01 by fmadura           #+#    #+#             */
/*   Updated: 2018/06/28 22:05:28 by jyildiz-         ###   ########.fr       */
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

int		check_op(unsigned int value)
{
	unsigned int	frst;
	unsigned int	scnd;
	unsigned int	last;
	unsigned int	op;

	frst = value & 0xF8080;
	scnd = value & 0x08F80;
	last = value & 0x0808F;
	if (value > 0x60000000)
		op = (value & 0x0FF00000) >> 20;
	else if (value > 0x600000)
		op = (value & 0x00F000) >> 12;
	else
		op = (value & 0x00F0) >> 4;
	if (A_LIVE(op) || A_ZJMP(op) || A_FORK(op) || A_LFORK(op))
		return (value == (0x6002 | (op << 4)));
	if (A_LD(op) || A_LLD(op))
		return ((value & 0xFFF) == 0x286 || (value & 0xFFF) == 0x486);
	if (A_ST(op))
		return (value == 0x603684 || value == 0x603686);
	if (A_ADD(op) || A_SUB(op))
		return ((value & 0xFFFFF) == 0x68686);
	if (A_AND(op) || A_OR(op) || A_XOR(op))
		return ((frst == 0x28080 || frst == 0x48080 || frst == 0x68080)
		&& (scnd == 0x08280 || scnd == 0x08480 || scnd == 0x08680)
		&& (last == 0x68082 || last == 0x08084 || last == 0x08086));
	if (A_LDI(op) || A_LLDI(op))
		return ((frst == 0x28080 || frst == 0x48080 || frst == 0x68080)
		&& (scnd == 0x08280 || scnd == 0x08680)
		&& (last == 0x08086));
	if (A_STI(op))
		return ((frst == 0x68080)
		&& (scnd == 0x08280 || scnd == 0x08480 || scnd == 0x08680)
		&& (last == 0x08082 || last == 0x08086));
	if (A_AFF(op))
		return (value == 0x6106);
	return (0);
}

int		token_com(char *line, int *count)
{
	char	*iter;

	iter = line;
	if (!(iter))
		return (0);
	while (*iter && ft_isspace(*iter))
	{
		(*count)++;
		++iter;
	}
	return (*iter == '#' || *iter == ';');
}

int		token_wsp(char *line, int *count)
{
	char	*iter;

	iter = line;
	if (!(iter))
		return (0);
	while (*iter && ft_isspace(*iter))
	{
		(*count)++;
		++iter;
	}
	return (!(*line));
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
		if ((*iter) && (token_wsp(iter, &count) == 0 || token_com(iter, &count) == 0))
		{
			itr->token |= LABEL_ERR2;
			itr->count = count;
			return(-1);
		}
		return(1);
	}
}

int		token_ins(char *line)
{
	int	i;
	int	len;
	int	ret;

	ret = -1;
	i = 0;
	while (*line && ft_isspace(*line))
		++line;
	while (i < 16)
	{
		len = ft_strlen(g_op_tab[i].name);
		if (ft_strnequ(line, g_op_tab[i].name, len) == 1)
			ret = i;
		i++;
	}
	return (ret);
}
