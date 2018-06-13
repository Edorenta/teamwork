/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 12:36:47 by fmadura           #+#    #+#             */
/*   Updated: 2018/06/12 21:04:52 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H
# include "ft_printf.h"
# include "libft.h"
# include "op.h"
typedef struct s_op
{
	char	*name;
	int		nlen;
	int		nbarg;
	int		args[3];
	int		opcod;
	int		cycle;
	char	*desc;
	int		octal;
	int		label;
}			t_op;
#endif
