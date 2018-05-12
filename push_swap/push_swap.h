/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyildiz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 19:05:32 by jyildiz-          #+#    #+#             */
/*   Updated: 2018/05/12 06:10:08 by jyildiz-         ###   ########.fr       */
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
long			ft_atol(const char *str)
int				is_digits(const char c);
int				is_space(const char c);
int				space_in(const char *str);
int				full_digits(const char *str);

void			swap(long *pile, int nb);
void			push(long *pile1, long pile2, int nb);
void			rotate(long *pile, int nb);
void			reverse_rotate(long *pile, int nb);


void			check_int(int ac, char **av);
void			check_same(int ac, char **av);
void			check_nb(int ac, char **av);

long			*stock_table(int ac, char **av);
long			*create_table(int ac);
void			free_pile(long *pile1, long *pile2);

int				is_sort(long *pile, int nb);

#endif
