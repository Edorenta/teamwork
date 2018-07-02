/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_lab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 14:47:34 by fmadura           #+#    #+#             */
/*   Updated: 2018/07/02 04:29:14 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	lab_tostring(t_iter *iter)
{
	t_lab	*lab;

	if (iter->labels)
	{
		lab = iter->labels;
		while (lab)
		{
			printf("name : %s, lnb : %d\n", lab->name, lab->lnb);
			lab = lab->next;
		}
	}
}

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

void	lab_del(t_lab *lab)
{
	t_lab	*iter;

	while (lab)
	{
		iter = lab;
		lab = lab->next;
		if (iter->name)
			free(iter->name);
		iter->name = NULL;
		free(iter);
		iter = NULL;
	}
}

int	lab_create(t_iter *iter)
{
	char	*line;
	char	*label;

	line = iter->line;
	//ft_error here
	label = lab_parse(line);
	if (label == NULL || lab_exist(iter->labels, label))
	{
		label ? free(label) : 0;
		label = NULL;
		iter->token = LABEL_ERR3;
		return (-1);
	}
	label ? lab_add(iter, label) : 0;
	label ? free(label) : 0;
	label = NULL;
	return (1);
}
