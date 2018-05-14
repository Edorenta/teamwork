/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyildiz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 19:05:32 by jyildiz-          #+#    #+#             */
/*   Updated: 2018/05/14 14:38:18 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define NONE 2200000000

# include <unistd.h>
# include <stdlib.h>

typedef struct		s_env
{
	long			*a;
	long			*b;
	int				a1;
	int 			b1;
	int				size;
	int				pivot;
	int				opt;
}					t_env;

/*
 * BASICS
 */

int					slen(char *s);
int					pstr(const char *s);
int					is_space(const char c);
int					is_digit(const char c);

/*
 * PARSER
 */

int 				arg_to_piles(t_env *env, int ac, char **av);
int					no_duplicates(long *pile, int size);
int					full_digits(const char *str);
int					spaces_in(const char *str);
long				ft_atol(const char *str);
int					is_int(char *av);

/*
 * PILES MANAGEMENT
 */

int					alloc_piles(t_env *env);
void				free_piles(t_env *env);

/*
 * CHECKS & ERRORS
 */

void				put_error(t_env *env, const char *err_msg);

/*
 * MOVE OPERATIONS
 */

long				*swap(long *pile, int size, int felem);
long				*rotate(long *pile,int size, int felem);
long				*reverse_rotate(long *pile, int nb);
t_env				*push(t_env *env, char to);

/*
 * LOGIC (ALL)
 */

#endif
