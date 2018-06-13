/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 15:50:00 by jjourne           #+#    #+#             */
/*   Updated: 2018/04/30 15:50:13 by jjourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

int			my_read(t_fd_lst *lst)
{
	char		*tmp;
	ssize_t		ret;
	char		buff[BUFF_SIZE + 1];

	while ((ret = read(lst->fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		tmp = lst->content;
		if (lst->content)
		{
			if (!(lst->content = ft_strjoin(lst->content, buff)))
				return (-1);
			free(tmp);
		}
		else
		{
			lst->content = ft_strnew(ft_strlen(buff));
			ft_strcpy(lst->content, buff);
		}
		if (ft_strchr(lst->content, '\n'))
			return (1);
	}
	return (ret);
}

int			punchline(t_fd_lst *lst, char **line)
{
	char	*tmp;
	char	*cut;
	int		size;

	if ((cut = ft_strchr(lst->content, '\n')))
	{
		tmp = lst->content;
		size = cut - lst->content;
		if (!(*line = ft_strnew(sizeof(char) * size)))
			return (-1);
		ft_memcpy((void*)*line, (void*)lst->content, size);
		if (!(lst->content = ft_strsub(lst->content, size + 1, ft_strlen(cut))))
			return (-1);
		free(tmp);
		return (1);
	}
	else if (*(lst->content) != 0)
	{
		if (!(*line = ft_strnew(sizeof(char) * ft_strlen(lst->content))))
			return (-1);
		ft_memcpy((void*)*line, (void*)lst->content, ft_strlen(lst->content));
		ft_memdel((void**)&lst->content);
		return (1);
	}
	return (0);
}

t_fd_lst	*check_fd(t_fd_lst **lst, int fd)
{
	t_fd_lst	*tmp;

	if (fd < 0)
		return (NULL);
	tmp = *lst;
	while (tmp)
	{
		if (tmp->fd == fd)
			return (tmp);
		tmp = tmp->next;
	}
	if (!(tmp = (t_fd_lst*)ft_memalloc(sizeof(t_fd_lst))))
		return (NULL);
	tmp->fd = fd;
	if (lst)
		tmp->next = *lst;
	*lst = tmp;
	return (tmp);
}

int			get_next_line(int fd, char **line)
{
	int					ret;
	static t_fd_lst		*lst = NULL;
	t_fd_lst			*tmp;

	ret = 1;
	if (!line)
		return (-1);
	if (!(tmp = check_fd(&lst, fd)))
		return (-1);
	if ((ret = my_read(tmp)) < 1 && !tmp->content)
		return (ret);
	ret = punchline(tmp, line);
	if (ret == 0)
		ft_memdel((void**)&tmp->content);
	return (ret);
}
