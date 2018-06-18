/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourne <jjourne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 17:12:22 by jjourne           #+#    #+#             */
/*   Updated: 2018/06/18 05:15:26 by jjourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int			modulo(int a, int b) //un peu spe, en gros on m'as explique que le modulo du c etait signe, pour la mem il faut pas
{
	if (a % b >= 0)
		return (a % b);
	else
		return ((a % b) + b);// le remet en positif
}

void	exit_error(const char *s)
{
	ft_putendl_fd(s, 2);
	exit(EXIT_FAILURE);
}

void 	usage(void)
{
	// ft_printf("Usage: ./corewar [-d N | -ncurses ] <[-n N] ");
	// ft_printf("champion1.cor> <...>\n");
	// ft_printf("  -d N\t\t: Dumps memory after N cycles then exits\n");
	// ft_printf("  -v N\t\t: pas encore implémenter, a faire? ");
	// ft_printf("  -ncurses\t: Ncurses output mode\n");
	// ft_printf("  -n N\t\t: Champion number (position at initalisation of ");
	// ft_printf("memory)\n");

	//temporaire, error si je met ft_printf.h et ncurses.h
	printf("Usage: ./corewar [-d N | -ncurses ] <[-n N] ");
	printf("champion1.cor> <...>\n");
	printf("  -d N\t\t: Dumps memory after N cycles then exits\n");
	printf("  -v N\t\t: pas encore implémenter, a faire? upd: --v 2 pour les cycles ");
	printf("  -ncurses\t: Ncurses output mode\n");
	printf("  -n N\t\t: Champion number (position at initalisation of ");
	printf("memory)\n");

	exit(EXIT_FAILURE);
}

//
void	get_winner(t_vm *vm)
{
	int i;
	int best;

	i = 1;
	best = 0;
	vm->player[best].last_live = 0;
	while (i <= MAX_PLAYERS)
	{
		if (vm->player[i].active)
		{
			//le last_live le + recent (le plus grand) gagne, on regarde tjr par rapport a celui d'avant
			if (vm->player[i].last_live > vm->player[best].last_live)
				best = i;
		}
		i++;
	}
	if (!best)//si aucun champ ne live le player 1 gagne?
		++best;
	vm->winner = best;
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
	t_vm		vm;
	T_WINDOW	*w; //pour ncurses

	ft_bzero(&vm, sizeof(t_vm)); //initialise toutes la structure vm a 0 (je fais tjr ca directement)
	init_vm(&vm);
	if(check_arg(&vm, argc, argv)) //si check_args return 1, error
		exit_error("Error: arguments invalide");
	create_players(&vm);

	if (vm.ncurses) //juste quelque tests avec ncurses
		init_ncurses(&w);

	run(&vm);
	get_winner(&vm);

	//affichage (ncurses)?

	printf("Contestant %d, \"%s\", has won !\n", vm.winner, //ncurses.h issue
		vm.player[vm.winner].name);
	//free

	return (0);
}
