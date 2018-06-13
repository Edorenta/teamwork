/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 11:12:05 by fmadura           #+#    #+#             */
/*   Updated: 2018/06/13 17:24:22 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
t_op	g_op_tab[17];

int		token_wsp(char *line)
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
	int ret;

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
