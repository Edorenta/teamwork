/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 12:36:47 by fmadura           #+#    #+#             */
/*   Updated: 2018/06/29 05:23:56 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_STRUCT_H
# define ASM_STRUCT_H

/*
 ** TOKENS
 */

typedef struct		s_lab
{
	char			*name;
	int				lnb;
	struct s_lab	*next;
}					t_lab;

typedef struct		s_tok
{
	int				type;
	unsigned int	token;
	char			*label;
	int				lnb;
	int				pos;
	struct s_tok	*list;
	struct s_tok	*next;
}					t_tok;


/*
** OPERATIONS
*/

typedef struct		s_op
{
	char			*name;
	int				nlen;
	int				nbarg;
	int				args[3];
	int				opcod;
	int				cycle;
	char			*desc;
	int				octal;
	int				label;
}					t_op;

typedef struct		s_ops
{
	int				type;
	int				len;
	int				lnb;
	int				opcode;
	long			args[3];
	long			argv[3];
	long			label[3];
	struct s_ops	*next;
}					t_ops;

/*
** ITERATION
*/

typedef struct		s_iter
{
	char			*line;
	int				count;
	int				lnb;
	int				error;
	t_tok			*first;
	t_tok			*iter;
	t_lab			*labels;
	t_header		header;
	unsigned int	token;
}					t_iter;

#endif
