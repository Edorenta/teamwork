/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_lab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 14:47:34 by fmadura           #+#    #+#             */
/*   Updated: 2018/06/28 19:20:32 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_lab	*lab_new(void)
{
	t_lab	*new;

	if ((new = (t_lab *)malloc(sizeof(t_lab))) == NULL)
		return (NULL);
	new->next = NULL;
	new->name = NULL;
	new->lnb = 0;
	return (new);
}

int		lab_exist(t_lab *lab, char *name)
{
	t_lab	*iter;

	if (!lab)
		return (0);
	iter = lab;
	while (iter)
	{
		if (!ft_strcmp(lab->name, name))
			return (1);
		iter = iter->next;
	}
	return (0);
}

void	lab_add(t_lab *lab, t_lab *new)
{
	t_lab	*iter;

	if (!lab)
	{
		lab = new;
		return;
	}
	iter = lab;
	while (iter->next)
		iter = iter->next;
	iter->next = new;
}

void	lab_del(t_lab *lab)
{
	t_lab	*iter;

	while (lab)
	{
		iter = lab;
		lab = lab->next;
		free(iter);
		iter = NULL;
	}
}

void	lab_create(t_iter *iter)
{
	char	*line;
	char	*label;
	t_lab	*lab;
	int		count;

	line = iter->line;
	count = 0;
	while (line[count] && line[count] != ':')
		count++;
	//ft_error here
	if ((lab = lab_new()) == NULL)
		return ;
	label = lab_parse(line);
	if (label == NULL || lab_exist(iter->labels, label))
	{
		label ? free(label) : 0;
		//token error here
	}
	lab->lnb = iter->lnb;
	lab->name = ft_strdup(label);
	free(label);
	label = NULL;
	lab_add(iter->labels, lab);
	printf("%s %d\n", lab->name, lab->lnb);
}
