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
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/fcntl.h>

# include "../libft/include/libft.h"//
# include "../libft/include/ft_printf.h"//
# include "op.h"

#include <stdio.h>//

# define MAGIC_NB 		4
# define PROG_NAME 		128 + 4//
# define PROG_SIZE 		4
# define PROG_COMS 		2048 + 4//
# define T_IND			4//0100

# define SRC_BEGIN MAGIC_NB + PROG_NAME + PROG_COMS + PROG_SIZE

typedef struct			s_op //pour les operations
{
	int					active;
	char				code; //value
	unsigned char		ocp;
	int					ar[3];
	int					ar_typ[3];
	int					loadtime;//par rpport au cycle
	int					pos_opcode;//par rapport au pc (voir parse_op.c)
}						t_op;

typedef struct			s_proc //liste chainee de process
{
	int					id;
	int					active;
	int					num;
	int					last_pc;
	int					pc;
	char				carry;
	int					reg[17];
	int					last_live;
	t_op				op;
	struct s_proc		*next;
}						t_proc;

typedef struct			s_player
{
	int					active;
	int					last_live;
	int		life_signal;
	int					read_ret; //retour de read
	char				*file_name;
	char				name[PROG_NAME];
	char				comments[PROG_COMS];
}						t_player;

typedef struct			s_mem //une case de la memoire
{
	char				mem; //contenu de cette case
	int					num;//du joueur
	int					live;
	int					pc;
}						t_mem;

typedef struct			s_vm
{
	int					nb_player; //nombre de joueurs
	int					ctd; //cycle to die
	int					cycle; //cycle
	int					ctd_check;
	int				next_ctd;
	int					dump; //a quel cycle dump la memoire
	int					lives_in_cycle; //
	int					ncurses;//si l'option ncurses est active
	t_mem				ram[MEM_SIZE]; //la memoire (l'arene)
	char				*files_name[5];
	t_player			player[5];
	t_player			*last_one;
	t_proc			*proc;
}						t_vm;

typedef struct			s_optab
{
	char				*inst;
	void				(*func)(t_vm *vm, t_proc *proc);//ptr sur fonction pour chaque instruction
	int					nb_arg;
	int					ocp[3];
	int					code;
	int					loadtime;
	char				*name;
	int					need_ocp;
	int					direct_size;
}				t_optab;

extern t_optab g_op_tab[];

void					exit_error(const char *s);
void 					usage(void);
void					init_vm(t_vm *vm);

int						check_arg(t_vm *vm, int argc, char **argv);
int						search_nb_dump(int argc, char **argv);
int						search_ncurses(int argc, char **argv);
int						search_players(t_vm *vm, int argc, char **argv);
int						search_nb_player(char **argv, int arg_num);
int						ft_strargv(int argc, char **argv, char *str);
int						ft_str_isdigit(char *str);
void					new_player(t_vm *vm, int nb, char *str);
int						get_nb_player(t_vm *vm, char **argv, int arg_num);
int						is_free_nb_player(t_vm *vm, int nb);
int						first_free_nb_player(t_vm *vm);

void					create_players(t_vm *vm);
void 					write_player(t_vm *vm, int nb, int num);
int						get_prog_size(char *data);
char					*get_data(t_player *player, char *buff);

void 					init_process(t_vm *vm);
t_proc					*create_process(t_vm *vm, int num);
int						process_living(t_vm *vm);
void					kill_proc(t_vm *vm);
void					set_ctd(t_vm *vm);
int						set_proc_id(t_vm *vm);
void					add_process(t_vm *vm, t_proc *proc);

void					run(t_vm *vm);
void					exec_proc(t_vm *vm, t_proc *proc);
void					dump(t_vm *vm);

int						fill_cur_op(t_vm *vm, t_proc *proc);
int						find_args(t_vm *vm, t_proc *proc, int num, int pos);//num = num arg
void					delete_op(t_proc *proc);
void					create_op(t_proc *proc, char data);
void					init_op(t_op *op);
int						is_opcode(char data);

int						check_ocp(int ocp, int opcode);
int						arg_available(int ocp_chunk, int opcode, int num_arg);//est appelé pour chaque argument, check la value
void					get_ind(t_vm *vm, t_proc *proc, int num, int pos);
void					get_reg(t_vm *vm, t_proc *proc, int num, int pos);
void					get_dir(t_vm *vm, t_proc *proc, int num, int pos);

void		show_mem(t_vm *vm);

void	live(t_vm *vm, t_proc *proc);

#endif
