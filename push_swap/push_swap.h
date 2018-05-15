/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyildiz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 19:05:32 by jyildiz-          #+#    #+#             */
/*   Updated: 2018/05/14 19:57:23 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

/*
 * DEFINITIONS
 */

# define NONE		200000000
# define SA			swap(env->a, env->size, env->a1)
# define SB			swap(env->b, env->size, env->b1)
# define SS			combine(swap, env)
# define PA			push(env, 'A')
# define PB			push(env, 'B')
# define RA			rotate(env->a, env->size, env->a1)
# define RB			rotate(env->b, env->size, env->b1)
# define RR			combine(rotate, env)
# define RRA		reverse_rotate(env->a, env->size, env->a1)
# define RRB		reverse_rotate(env->b, env->size, env->b1)
# define RRR		combine(reverse_rotate, env)

/*
 * SRUCTS
 */

typedef struct	s_move	t_move;
typedef struct	s_env	t_env;

struct			s_move
{
	char		id[3];
	t_move		*next;
	t_move		*prev;
};

struct			s_env
{
	long		*a;
	long		*b;
	long		*c;
	int			a1;
	int			b1;
	int			size;
	int			pivot;
	int			opt;
	
};

/*
 * BASICS
 */

int				slen(char *s);
int				pstr(const char *s);
int				is_space(const char c);
int				is_digit(const char c);
int				scpy(char *dest, const char *src);

/*
 * PARSER
 */

int 			arg_to_piles(t_env *env, int ac, char **av);
int				no_duplicates(long *pile, int size);
int				full_digits(const char *str);
int				spaces_in(const char *str);
long			ft_atol(const char *str);
int				is_int(char *av);

/*
 * PILES MANAGEMENT
 */

int				alloc_piles(t_env *env);
void			free_piles(t_env *env);

/*
 * CHECKS & ERRORS
 */

void			put_error(t_env *env, const char *err_msg);
int				is_sort(long *pile, int size, int felem);
int				all_sort(t_env *env);

/*
 * MOVE OPERATIONS
 */

long			*swap(long *pile, int size, int felem);
long			*rotate(long *pile,int size, int felem);
long    		*reverse_rotate(long *pile, int size, int felem);
t_env	 		*push(t_env *env, char to);
void			combine(long (*move)(long *, int, int), t_env *env);

/*
 * LOGIC (ALL)
 */
int				bb_sort(t_env *env);
int				ext_sort(t_env *env);

#endif
