#include "corewar.h"

void	exit_error(const char *s)
{
	ft_putendl_fd(s, 2);
	exit(EXIT_FAILURE);
}

void 	usage(void)
{
	ft_printf("Usage: ./corewar champion1.cor champion2.cor");
	exit(EXIT_FAILURE);
}

void	init_vm(t_vm *vm)
{
	vm->ctd = CYCLE_TO_DIE;
	vm->pause = 1;//?
	vm->delay = NCURSES_DELAY;
	vm->next_ctd = CYCLE_TO_DIE;
	vm->dump = -1;
	ft_bzero(vm->player, sizeof(t_player) * 5);
	ft_bzero(vm->ram, sizeof(t_mem) * MEM_SIZE);
}

int		main(int argc, char *argv[])
{
	t_vm vm;

	ft_bzero(&vm, sizeof(t_vm)); //initialise toutes la structure vm a 0 (je fais tjr ca)
	init_vm(&vm);
	if(check_args(&vm, argc, argv))
		exit_error("Error: arguments invalide");

	//create_players()

	//run()

	//get_winner()
	//affichage (ncurses)
	//free

	return (0);
}
