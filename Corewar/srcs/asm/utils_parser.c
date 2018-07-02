/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 23:25:12 by fmadura           #+#    #+#             */
/*   Updated: 2018/07/02 23:34:49 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		if_parse(t_iter **it, char **line, t_ops **itera, t_ops **fst)
{
	if (!(*fst))
	{
		*fst = parse_sub(*it, (*it)->iter, *line, 0);
		*itera = *fst;
	}
	else
	{
		(*itera)->next = parse_sub(*it, (*it)->iter, *line, 0);
		*(itera) = (*itera)->next;
	}
}

void		els_parse(t_iter **iter, char *line, t_ops **itera)
{
	if ((*iter)->iter->next && (*iter)->iter->lnb == (*iter)->iter->next->lnb)
	{
		(*iter)->iter = (*iter)->iter->next;
		(*itera)->next = parse_sub(*iter, (*iter)->iter,
				&line[(*iter)->iter->pos], 0);
		(*itera) = (*itera)->next;
	}
}
