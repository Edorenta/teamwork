/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyildiz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 19:05:32 by jyildiz-          #+#    #+#             */
/*   Updated: 2018/05/23 18:01:02 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <signal.h>

/*
 * DEFINITIONS
 */

# define NONE			200000000

# define SA				swap(env, 'a')
# define SB				swap(env, 'b')
# define SS				combine(swap, env)
# define PA				push(env, 'a')
# define PB				push(env, 'b')
# define RA				rotate(env, 'a')
# define RB				rotate(env, 'b')
# define RR				combine(rotate, env)
# define RRA			reverse_rotate(env, 'a')
# define RRB			reverse_rotate(env, 'b')
# define RRR			combine(reverse_rotate, env)
# define RSA			swap_last(env, 'a')
# define RSB			swap_last(env, 'b')

# define A1				env->a[env->a1]
# define A2				env->b[env->a1 == env->size ? env->a1 + 1 : env->a1]
# define A3				env->a[env->size - 2]
# define A4				env->a[env->size - 1]
# define B1				env->b[env->b1]
# define B2				env->b[env->b1 == env->size ? env->b1 + 1 : env->b1]
# define B3				env->b[env->size - 2]
# define B4				env->b[env->size - 1]

# define MEAN_A			mean_value(env->a, env->a1, (env->size - 1))
# define MEAN_B			mean_value(env->b, env->b1, (env->size - 1))
# define MAX_A			pile_max(env->a, env->a1, env->size - 1)
# define MAX_B			pile_max(env->b, env->b1, env->size - 1)
# define MIN_A			pile_min(env->a, env->a1, env->size - 1)
# define MIN_B			pile_min(env->b, env->b1, env->size - 1)
# define LEN_A			(env->size - 1 - env->a1)
# define LEN_B			(env->size - 1 - env->b1)

# define IS_SET_V		(env->option & (1 << 0))
# define IS_SET_O		(env->option & (1 << 1))
# define IS_SET_S		(env->option & (1 << 2))
# define IS_SET_R		(env->option & (1 << 3))
# define SET_V			(env->option |= (1 << 0))
# define SET_O			(env->option |= (1 << 1))
# define SET_S			(env->option |= (1 << 2))
# define SET_R			(env->option |= (1 << 3))

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
	t_move		*first_move;
	t_move		*this_move;
	char		option;
	long		*a;
	long		*b;
	long		*c;
	int			a1;
	int			b1;
	int			size;
	int			pivot;
	int			mean;
	int			min;
	int			opt;
	
};

/*
 * BASICS
 */

int				slen(char *s);
int				scmp(const char *s1, const char *s2);
long			labs(long n);
int				is_space(const char c);
int				is_digit(const char c);
int				active_bits(char c);
int				plong(int fd, long n, char end);
int				pstr(int fd, const char *s, char end);
int				scat(char *dest, const char *src, char c);
void			init_env(t_env *env, int ac);
void			deinit_env(t_env *env);

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

void			duplicate_pile(long *src, long *dest, int start, int end);
void			index_pile(t_env *env);
void			put_piles(t_env *env);
int				alloc_piles(t_env *env);
void			free_piles(t_env *env);
double			mean_value(long *pile, int start, int stop);
int				pile_contains(long i, long *pile, int size);
void			pile_init(long *pile, int size);
long			pile_max(long *pile, int start, int end);
long			pile_min(long *pile, int start, int end);

/*
 * CHECKS & ERRORS
 */

void			put_error(t_env *env, const char *err_msg);
int				is_sort(long *pile, int start, int end);
int				all_sort(t_env *env);

/*
 * MOVE OPERATIONS
 */

t_env	 		*push(t_env *env, char to);
long			*swap(t_env *env, char which);
long			*rotate(t_env *env, char which);
long    		*reverse_rotate(t_env *env, char which);
int				swap_last(t_env *env, char which);
void			combine(long *(*move)(t_env *, char), t_env *env);
int				mass_push(t_env *env, char to, int start, int end);
void			move_push(t_env *env, char *p, int i);
void			move_swap(t_env *env, char *p, int i);
void			move_drot(t_env *env, char *p, int i);
void			move_rota(t_env *env, char *p, int i);

/*
 * MOVE CHAINED LIST
 */

int				archive_move(t_env *env, const char *id, char which, t_move *prev);
t_move			*new_move(const char *id, char which, t_move *prev);
void			del_move(t_move *mv);
void			del_moves(t_env *env);
void			put_move(t_move *mv, char end);
int				put_moves(t_move *start, int dir, char sep);
int				optimize(t_env *env);
int				count_moves(t_env *env);

/*
 * LOGIC (ALL)
 */

int				sort_pile(t_env *env);
int				bb_sort(long *pile, int start, int end);
int				quick_sort(t_env *env);
int				ladder_sort(t_env *env);
int 			quick_fix_a(t_env *env);
int 			quick_fix_b(t_env *env);
int				rot_or_revrot(t_env *env);
int				a_or_b(t_env *env);
int				rb_or_rrb(t_env *env, long higher, long lower);
int				ra_or_rra(t_env *env, long max);

#endif
