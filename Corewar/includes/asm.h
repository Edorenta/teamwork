/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 12:36:47 by fmadura           #+#    #+#             */
/*   Updated: 2018/06/29 05:24:10 by fmadura          ###   ########.fr       */
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

int					token_wsp(char *line, int *count);
int					token_lab(t_iter *itr);
int					token_ins(char *line);
int					token_com(char *line, int *count);

int					check_op(unsigned int value);

t_tok				*token_new(void);
t_tok				*token_create(int type, char *label, int nbl, int pos);
t_tok				*token_iter(t_iter *iter, char *label);
void				token_tostring(t_tok *tok);
void				token_del(t_tok *tok);

int					ft_asm(char **argv);
t_iter				*lexer(t_iter *iter, int fd);
t_ops				*parser(t_iter *iter, int fd);

void				lexer_ins_sub(t_iter *iter);
void				lexer_ins(t_iter *iter);
int					lexer_basics(t_iter *iter);

t_iter				*iter_add_list(t_iter *iter, char *label, int type);
t_iter				*iter_new(void);
void				iter_del(t_iter *iter);

void				clear_wsp(t_iter *iter);
void				increment(t_iter *iter);
void				increment_num(t_iter *iter, int num);
void				end_line(t_iter *iter);

t_ops				*ops_new(void);
void				ops_del(t_ops *ops);
void				ops_tostring(t_ops *ops);
void				ops_debug(t_ops *ops);
int					ops_get_ocp(t_ops *ops);

void				write_ops(char *filename, t_ops *ops);
void				write_head(char *filename, t_header head);

t_lab				*lab_new(void);
long				lab_get(t_iter *iter, char *name);
int					lab_exist(t_lab *lab, char *name);
void				lab_add(t_iter *iter, char *name);
void				lab_del(t_lab *lab);
void				lab_create(t_iter *iter);
void				lab_tostring(t_iter *iter);
char				*lab_parse(char *line);
char				*lab_parse_ins(char *line);
#endif
