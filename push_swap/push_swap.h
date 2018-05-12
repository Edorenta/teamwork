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
# define null 2200000000

# include <stdlib.h>

void			swap(long *pile, int nb);
void			push(long *pile1, long pile2, int nb);
void			rotate(long *pile, int nb);
void			reverse_rotate(long *pile, int nb);
void			free_pile(long *pile1, long *pile2);
void			check_int(int ac, char **av);
void			check_same(int ac, char **av);
void			check_nb(int ac, char **av);
long			*stock_table(int ac, char **av);
long			*create_table(int ac);
int				first_elem(long *pile, int nb);
int				is_sort(long *pile, int nb);


#endif
