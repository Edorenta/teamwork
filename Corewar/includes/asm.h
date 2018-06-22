/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 12:36:47 by fmadura           #+#    #+#             */
/*   Updated: 2018/06/16 17:14:06 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H
# include <stdio.h>
# include "ft_printf.h"
# include "asm_def.h"
# include "libft.h"
# include "op.h"

typedef struct		s_op
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

/*
** TOKENS
*/

typedef struct		s_tok
{
	int		type;
	char		*label;
	int		nbl;
	int		pos;
	struct s_token	*list;
	struct s_token	*next;
}			t_tok;

int			token_wsp(char *line);
int			token_lab(char *line);
int			token_ins(char *line);

int			check_op(unsigned int value);
#endif
