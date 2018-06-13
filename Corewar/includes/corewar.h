/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <fmadura@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 12:36:01 by fmadura           #+#    #+#             */
/*   Updated: 2018/06/13 21:24:27 by jjourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <stdarg.h>
# include <limits.h>

# include "../libft/include/libft.h"//
# include "../libft/include/ft_printf.h"//
# include "op.h"

#include <stdio.h>//

# define PROG_NAME 		128 + 4//
# define PROG_COMS 		2048 + 4//

typedef struct			s_player
{
	int					active;
	int					last_live;
	int					read_ret; //retour de read
	char				*file_name;
	char				name[PROG_NAME];
	char				comments[PROG_COMS];
}						t_player;

typedef struct			s_mem //une case de la memoire
{
	char				mem;
	int					num;//du joueur
	int					live;
	int					pc;
}						t_mem;

typedef struct			s_op //pour les operations
{
	int					active;
	char				code;
	unsigned char		ocp;
	int					ar[3];
	int					ar_typ[3];
}						t_op;

typedef struct			s_vm
{
	int					nb_player; //nombre de joueurs
	int					ctd; //cycle to die
	int					cycle; //cycle
	int					ctd_check;
	int					dump; //a quel cycle dump la memoire
	int					lives_in_cycle; //
	int					ncurses;//si l'option ncurses est active
	t_mem				ram[MEM_SIZE]; //la memoire (l'arene)
	char				*files_name[5];
	t_player			player[5];
	t_player			*last_one;
}						t_vm;

void					exit_error(const char *s);
void 					usage(void);
void					init_vm(t_vm *vm);
int						check_arg(t_vm *vm, int argc, char **argv);
int						search_nb_dump(int argc, char **argv);
int						search_ncurses(int argc, char **argv);
int						ft_strargv(int argc, char **argv, char *str);
int						ft_str_isdigit(char *str);
int						search_players(t_vm *vm, int argc, char **argv);
int						get_nb_player(t_vm *vm, char **argv, int arg_num);
int						search_nb_player(char **argv, int arg_num);
int						is_free_nb_player(t_vm *vm, int nb);
int						first_free_nb_player(t_vm *vm);
void					new_player(t_vm *vm, int nb, char *str);

#endif
