/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_create_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyildiz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 07:03:24 by jyildiz-          #+#    #+#             */
/*   Updated: 2018/07/03 07:05:02 by jyildiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include <fcntl.h>
#include <unistd.h>

void		cw_create_file(t_asm *comp)
{
	comp->fd = open(comp->cor_file, O_CREAT | O_TRUNC | O_WRONLY, 00644);
	if (comp->fd == -1)
		cw_error(comp, "Error when creating .cor\n");
	write(comp->fd, comp->data, comp->i);
	ft_printf("File %s created\n", comp->cor_file);
	close(comp->fd);
}
