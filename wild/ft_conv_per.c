/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_%.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyildiz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 15:28:13 by jyildiz-          #+#    #+#             */
/*   Updated: 2018/02/15 18:55:35 by jyildiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_wdth(t_arg *tmp, t_buf **buf, int nbc)
{
	int	i;

	i = 0;
	while (i < tmp->width - nbc)
	{
		if (tmp->zero == 0)
			ft_strnconcat(buf, " ", 1);
		else
			ft_strnconcat(buf, "0", 1);
		i++;
	}
}

void			ft_conv_per(t_arg *tmp, t_buf **buf)
{
	if (tmp->minus == 1)
	{
		ft_strnconcat(buf, "%", 1);
		ft_wdth(tmp, buf, 1);
	}
	else
	{
		ft_wdth(tmp, buf, 1);
		ft_strnconcat(buf, "%", 1);
	}
}
