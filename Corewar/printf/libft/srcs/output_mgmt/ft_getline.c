/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 14:30:58 by pde-rent          #+#    #+#             */
/*   Updated: 2017/11/27 14:51:52 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		store_line(char **dst, char *src)
{
	int		i;
	int		j;
	char	*tmp;

	j = 0;
	i = 0;
	while (src[i] != '\n')
		i++;
	IS((tmp = (char*)malloc(sizeof(char) * i + 1)));
	i = -1;
	while (src[++i] != '\n')
		tmp[i] = src[i];
	tmp[i] = '\0';
	*dst = tmp;
	while (src[++i])
	{
		src[j] = src[i];
		++j;
	}
	src[j] = '\0';
	return (1);
}

int				get_next_line(int fd, char **line)
{
	static char	*str[OPEN_MAX];
	char		buf[BUFF_SIZE + 1];
	size_t		found;

	if (fd < 0 || line == (void *)0 || read(fd, (void *)0, 0) || fd > OPEN_MAX)
		return (-1);
	str[fd] = (str[fd] == (void *)0 ? (char *)malloc(sizeof(char)) : str[fd]);
	if (str[fd] && (ft_strchr(str[fd], '\n') != 0))
		return (store_line(line, str[fd]));
	while ((found = read(fd, buf, BUFF_SIZE)))
	{
		while (buf[found])
			buf[found++] = '\0';
		str[fd] = ft_strjoinfree(str[fd], buf, &str[fd]);
		if (ft_strchr(str[fd], '\n') != 0)
			return (store_line(line, str[fd]));
	}
	if (str[fd][0] != '\0')
	{
		IS((*line = (char *)malloc(ft_strlen(str[fd]))));
		*line = ft_strcpy(*line, str[fd]);
		ft_bzero(str[fd], ft_strlen(str[fd]));
		return (1);
	}
	return (0);
}
