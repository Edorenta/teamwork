/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 12:36:47 by fmadura           #+#    #+#             */
/*   Updated: 2018/06/27 16:15:34 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H
# include <stdio.h>
# include "libft.h"
# include "asm_def.h"
# include "asm_struct.h"
# include "libft.h"
# include "op.h"

int					token_wsp(char *line);
int					token_lab(char *line);
int					token_ins(char *line);

int					check_op(unsigned int value);

t_tok				*new_tok(void);
t_tok				*create_tok(int type, char *label, int nbl, int pos);
t_tok				*tok_iter(t_iter *iter, char *label);
void				tok_tostring(t_tok *tok);
void				del_tok(t_tok *tok);

int					ft_asm(char **argv);
t_iter				*lexer(t_iter *iter, int fd);
void				parser(t_iter *iter, int fd);

void				lexer_ins_sub(t_iter *iter);
void				lexer_ins(t_iter *iter);
int					lexer_basics(t_iter *iter);

t_iter				*iter_add_list(t_iter *iter, char *label, int type);
t_iter				*iter_new(void);
void				iter_del(t_iter *iter);

void				clear_wsp(t_iter *iter);
void				increment(t_iter *iter);
void				end_line(t_iter *iter);

t_ops				*ops_new(void);
void				ops_tostring(t_ops *ops);
void				ops_debug(t_ops *ops);
#endif
