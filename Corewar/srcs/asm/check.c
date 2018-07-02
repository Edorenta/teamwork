/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/16 15:02:01 by fmadura           #+#    #+#             */
/*   Updated: 2018/07/02 21:02:32 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

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
	int		i;
	int		len;
	int		ret;

	(void)line;
	ret = -1;
	i = 0;
	clear_wsp(iter);
	if (!(*iter->line))
		ret = -2;
	while (i < 16)
	{
		len = ft_strlen(g_op_tab[i].name);
		if (ft_strnequ(iter->line, g_op_tab[i].name, len) == 1)
		{
			if (ft_isspace(iter->line[len]))
				ret = i;
		}
		i++;
	}
	if (ret == -1)
		iter->token = INS_ERR0;
	return (ret);
}
