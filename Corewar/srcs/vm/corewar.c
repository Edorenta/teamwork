/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourne <jjourne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 17:12:22 by jjourne           #+#    #+#             */
/*   Updated: 2018/06/13 21:37:36 by jjourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	exit_error(const char *s)
{
	ft_putendl_fd(s, 2);
	exit(EXIT_FAILURE);
}

void 	usage(void)
{
	ft_printf("Usage: ./corewar [-d N | -ncurses ] <[-n N] ");
	ft_printf("champion1.cor> <...>\n");
	ft_printf("  -d N\t\t: Dumps memory after N cycles then exits\n");
	ft_printf("  -v N\t\t: pas encore implémenter, a faire? ");
	ft_printf("  -ncurses\t: Ncurses output mode\n");
	ft_printf("  -n N\t\t: Champion number (position at initalisation of ");
	ft_printf("memory)\n");
	exit(EXIT_FAILURE);
}

void	init_vm(t_vm *vm)
{
	vm->ctd = CYCLE_TO_DIE;
	vm->next_ctd = CYCLE_TO_DIE;
	vm->dump = -1;//option dump de la memoire (option -d cycle) => inactive par defaut
	ft_bzero(vm->player, sizeof(t_player) * 5);
	ft_bzero(vm->ram, sizeof(t_mem) * MEM_SIZE);
}

int		main(int argc, char *argv[])
{
	t_vm vm;

	ft_bzero(&vm, sizeof(t_vm)); //initialise toutes la structure vm a 0 (je fais tjr ca directement)
	init_vm(&vm);
	if(check_arg(&vm, argc, argv)) //si check_args return 1, error
		exit_error("Error: arguments invalide");
	create_players(&vm);

	//init_ncurses et check ici

	run()

	//get_winner()
	//affichage (ncurses)
	//free

	return (0);
}
