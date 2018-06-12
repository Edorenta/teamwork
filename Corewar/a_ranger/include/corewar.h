#ifndef COREWAR_H
# define COREWAR_H

# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <stdarg.h>
# include <limits.h>
# include "../libft/include/libft.h"//avec ma lib
# include "../libft/include/get_next_line.h"//avec ma lib
# include "../libft/include/ft_printf.h"//avec ma lib

# define BUF_SIZE 4096

typedef struct	s_vm
{
	int				nb_player; //nombre de joueurs
	int				ctd; //cycle to die
	int				cycle; //cycle
	int				ctd_check;
	int				dump; //
	int				lives_in_cycle;
	t_mem			ram[MEM_SIZE]; //la memoire (l'arene)
	char			*files_name[5];
	t_player		player[5];
	t_player		*last_one;
}				t_vm;

typedef struct		s_player
{
	int				active;
	int				last_live;
	char			*file_name;
	char			name[PROG_NAME];
	char			comments[PROG_COMS];
}					t_player;

#endif
