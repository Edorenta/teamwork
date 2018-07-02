/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 14:20:50 by fmadura           #+#    #+#             */
/*   Updated: 2018/07/02 04:27:21 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static long		get_index(t_iter *iter, char *line)
{
	char	*label;
	long	ret;

	label = lab_parse_ins(line);
	ret = 0;
	ret = lab_get(iter, label);		
	free(label);
	label = NULL;
	return (ret);
}

static void		parse_dir(t_ops *ops, t_tok *iter, char *line, int argc)
{
	int		len;

	len = ft_strlen(line);
	while (iter->pos >= len)
		iter->pos--;		
	ops->argv[argc] = ft_atoi(&line[iter->pos]);
}

static t_ops	*parse_sub(t_iter *itera, t_tok *token, char *line)
{
	t_ops	*new;
	t_tok	*iter;
	int		argc;

	argc = 0;
	iter = token->list;
	new = ops_new();
	new->type = (token->type & 0xFF);
	while (iter)
	{
		if ((iter->type & 0x0F) <= 0x6)
		{
			new->args[argc] = (iter->type >> 1);
			if (iter->type == 0x1)
				new->argv[argc] = ft_atoi(&line++[iter->pos]);
			else if (iter->type == 0x5)	
				new->label[argc] = get_index(itera, &line[iter->pos]);	
			else
				parse_dir(new, iter, line, argc);
			argc++;
		}
		iter = iter->next;
	}
	new->lnb = token->lnb;
	ops_get_ocp(new);
	return (new);
}

t_ops	*parser(t_iter *iter, int fd)
{
	char		*line;
	int			ret;
	t_ops		*first;
	t_ops		*itera;
	t_header	*head;

	line = NULL;
	first = NULL;
	itera = NULL;
	head = NULL;
	ret = 0;
	iter->iter = iter->first;
	// Set error here
	if (lseek(fd, 0, SEEK_SET) < 0)
		return (NULL);
	while ((ret = get_next_line(fd, &line)) > 0 && iter->iter)
	{
		if ((iter->iter->type & 0x600) == 0x600)
		{
			if (!first)
			{
				first = parse_sub(iter, iter->iter, line);
				itera = first;
			}
			else
			{
				itera->next = parse_sub(iter, iter->iter, line);
				itera = itera->next;
			}
		}
		else if (iter->iter->type == 0x82 || iter->iter->type == 0x84)
			iter_head(line, iter, iter->iter->type);
		else if (iter->iter->type == (TOKEN_LAB << 4))
		{
			if (iter->iter->next && iter->iter->lnb == iter->iter->next->lnb)
			{
				iter->iter = iter->iter->next;
				itera->next = parse_sub(iter, iter->iter, &line[iter->iter->pos]);
				itera = itera->next;
			}
		}
		free(line);
		line = NULL;
		if (iter->iter)
			iter->iter = iter->iter->next;
	}
	free(line);
	line = NULL;
	return (ret == -1 ? NULL : first);
}
