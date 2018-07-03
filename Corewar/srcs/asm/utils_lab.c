/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_lab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 17:38:08 by fmadura           #+#    #+#             */
/*   Updated: 2018/07/03 04:23:00 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char	*lab_parse_ins(char *line)
{
	int		count;
	char	*label;
	char	c;

	if (!line)
		return (NULL);
	count = 0;
	label = NULL;
	if (line[count] == ':')
	{
		++count;
		c = line[count];
		while (c && (ft_isalpha(c) || ft_isdigit(c) || c == '_'))
		{
			count++;
			c = line[count];
		}
		label = ft_strsub(line, 1, count - 1);
	}
	else
		return (NULL);
	return (label);
}

char	*lab_parse(char *line)
{
	int		count;
	char	*label;

	if (!line)
		return (NULL);
	count = 0;
	label = NULL;
	while (line[count] && line[count] != ':')
		count++;
	if (line[count] == ':')
		label = ft_strsub(line, 0, count);
	else
		return (NULL);
	return (label);
}

int		lab_exist(t_lab *lab, char *name)
{
	t_lab	*iter;

	if (!lab || !name || !lab->name)
		return (0);
	iter = lab;
	while (iter)
	{
		if (ft_strequ(lab->name, name))
			return (1);
		iter = iter->next;
	}
	return (0);
}

long	lab_get(t_iter *iter, char *name)
{
	t_lab	*lab;

	if (!iter || !name || !iter->labels)
		return (-1);
	lab = iter->labels;
	while (lab)
	{
		if (ft_strequ(lab->name, name))
			return (lab->lnb);
		lab = lab->next;
	}
	return (-1);
}

void	lab_add(t_iter *iter, char *name)
{
	t_lab	*lab;

	lab = NULL;
	if (!iter->labels)
	{
		iter->labels = lab_new();
		lab = iter->labels;
	}
	else
	{
		lab = iter->labels;
		while (lab->next)
			lab = lab->next;
		lab->next = lab_new();
		lab = lab->next;
	}
	lab->name = ft_strdup(name);
	lab->lnb = iter->lnb;
}
