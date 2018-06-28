/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_lab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 14:47:34 by fmadura           #+#    #+#             */
/*   Updated: 2018/06/28 17:31:01 by fmadura          ###   ########.fr       */
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

	iter = lab;
	if (!iter)
		return (0);;
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

	iter = lab;
	if (!iter)
		lab = new;
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
