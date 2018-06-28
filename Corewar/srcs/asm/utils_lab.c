/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_lab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 17:38:08 by fmadura           #+#    #+#             */
/*   Updated: 2018/06/28 19:52:19 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char	*lab_parse_ins(char *line)
{
	int		count;
	char	*label;

	if (!line)
		return (NULL);
	count = 0;
	label = NULL;
	while (line[count] && !(line[count] == ',' || ft_isspace(line[count])))
		count++;
	if (line[count] == ',' || ft_isspace(line[count]))
		label = ft_strsub(line, 0, count);
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
