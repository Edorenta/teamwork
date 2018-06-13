/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 15:50:24 by jjourne           #+#    #+#             */
/*   Updated: 2018/04/30 15:50:27 by jjourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 1

typedef struct s_fd_lst		t_fd_lst;
struct	s_fd_lst
{
	int			fd;
	char		*content;
	t_fd_lst	*next;
};
int		get_next_line(int fd, char **line);
#endif
