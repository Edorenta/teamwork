/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 14:20:50 by fmadura           #+#    #+#             */
/*   Updated: 2018/07/03 06:56:56 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static long		get_index(t_iter *iter, char *line)
{
	char		*label;
	long		ret;

	label = lab_parse_ins(line);
	ret = 0;
	ret = lab_get(iter, label);
	free(label);
	label = NULL;
	return (ret);
}

static void		parse_dir(t_ops *ops, t_tok *iter, char *line, int argc)
{
	int			len;

	len = ft_strlen(line);
	if (iter->type == 0x4 || iter->type == 0x6)
	{
		if (iter->pos > 0 && ft_isdigit(line(iter->pos - 1))
			|| line[iter->pos - 1] == '-')
			--iter->pos;
		while (iter->pos >= len)
			--iter->pos;
		if (iter->pos > 0 && (ft_isdigit(line[iter->pos - 1])
					|| line[iter->pos - 1] == '-'))
			--iter->pos;
		ops->argv[argc] = ft_atol(&line[iter->pos]);
	}
}

static long		get_num(t_iter *iter, char *line, int type, int pos)
{
	if (type == 0x1)
	{
		while (pos > 0 && line[pos] != 'r')
			--pos;
		if (line[pos] == 'r')
			pos++;
		return (ft_atol(&line[pos]));
	}
	else if (type == 0x05)
	{
		while (pos > 0 && line[pos] != ':')
			--pos;
		if (line[pos] == ':')
			pos++;
		return (get_index(iter, &line[pos]));
	}
	return (0);
}

t_ops			*parse_sub(t_iter *itera, t_tok *token, char *line, int argc)
{
	t_ops		*new;
	t_tok		*iter;

	iter = token->list;
	new = ops_new();
	new->type = (token->type & 0xFF);
	while (iter && argc < 3)
	{
		if ((iter->type & 0x0F) <= 0x6)
		{
			new->args[argc] = (iter->type >> 1);
			if (new->args[argc] == 0x1)
				new->argv[argc] = get_num(itera, line, 0x1, iter->pos);
			else if (iter->type == 0x5)
				new->label[argc] = get_num(itera, line, 0x5, iter->pos);
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

t_ops			*parser(t_iter *iter, int fd, int ret)
{
	char		*line;
	t_ops		*first;
	t_ops		*itera;

	line = NULL;
	first = NULL;
	itera = NULL;
	iter->iter = iter->first;
	if (lseek(fd, 0, SEEK_SET) < 0)
		return (NULL);
	while ((ret = get_next_line(fd, &line)) > 0 && iter->iter)
	{
		if ((TYPE & 0x600) == 0x600)
			if_parse(&iter, &line, &itera, &first);
		else if (TYPE == 0x82 || TYPE == 0x84)
			iter_head(line, iter, TYPE);
		else if (TYPE == (TOKEN_LAB << 4) && itera)
			els_parse(&iter, line, &itera);
		free(line);
		line = NULL;
		iter->iter ? iter->iter = iter->iter->next : 0;
	}
	free(line);
	line = NULL;
	return (ret == -1 ? NULL : first);
}
