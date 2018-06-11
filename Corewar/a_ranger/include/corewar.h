#ifndef COREWAR_H
# define COREWAR_H

# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <stdarg.h>
# include <limits.h>
# include "../libft/include/libft.h"
# include "../libft/include/get_next_line.h"
# include "../libft/include/ft_printf.h"

# define BUF_SIZE 4096

typedef struct	s_vm
{
	int				nb_player; //nombre de joueurs
	int				ctd; //cycle to die
	int				cycle; //cycle
	int				boost;
	int				pause;
	int				ncurses;
	int				delay;
	int				next_ctd;
	int				ctd_check;
	int				dump; //
	int				debug;
	int				verbosity;
	int				winner;
	int				lives_in_cycle;
	t_mem			ram[MEM_SIZE]; //la memoire
	int				life_signal[4];
	char			*files_name[5];
	t_player		player[5];
	t_player		*last_one;
	t_proc			*proc;
}				t_vm;

#endif
