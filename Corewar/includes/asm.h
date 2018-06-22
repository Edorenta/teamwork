/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 12:36:47 by fmadura           #+#    #+#             */
/*   Updated: 2018/06/22 14:09:15 by fmadura          ###   ########.fr       */
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
}					t_op;

/*
 ** TOKENS
 */

typedef struct		s_tok
{
	int				type;
	char			*label;
	int				lnb;
	int				pos;
	struct s_tok	*list;
	struct s_tok	*next;
}					t_tok;

int					token_wsp(char *line);
int					token_lab(char *line);
int					token_ins(char *line);

int					check_op(unsigned int value);

t_tok				*new_tok(void);
t_tok				*create_tok(int type, char *label, int nbl, int pos);
void				tok_tostring(t_tok *tok);


void				end_line(int count, char **line);
void				lexer_ins_sub(char **line, unsigned int *tok, int *c);
void				lexer_ins(char **line, unsigned int *tok, int lnb, int *c);
void				lexer_basics(char *line, unsigned int *tok, int lnb, int *c);

#endif
