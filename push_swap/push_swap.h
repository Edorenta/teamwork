/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyildiz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 19:05:32 by jyildiz-          #+#    #+#             */
/*   Updated: 2018/05/13 19:52:06 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define NONE 2200000000

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

int				slen(char *s);
long			ft_atol(const char *str);
int				is_digits(const char c);
int				is_space(const char c);
int				space_in(const char *str);
int				full_digits(const char *str);

long			*swap(long *pile, int size, int felem);
long			*rotate(long *pile,int size, int felem);
long			*reverse_rotate(long *pile, int nb);
t_env			*push(t_env *env);


void			is_int(int ac, char **av);
void			check_same(int ac, char **av);
void			check_nb(int ac, char **av);

long			*stock_table(int ac, char **av);
long			*create_table(int ac);
void			free_pile(long *a, long *b);

int				is_sort(long *pile, int nb);

#endif
