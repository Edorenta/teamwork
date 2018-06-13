/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourne <jjourne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 19:33:51 by jjourne           #+#    #+#             */
/*   Updated: 2018/06/13 19:36:53 by jjourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

//F: init new player
void	new_player(t_vm *vm, int nb, char *str)
{
	vm->player[nb].active = 1;
	vm->player[nb].file_name = str;
}

//
void	create_players(t_vm *vm)
{
	int i;
	int j;

	i = 1;
	j = 0;
	ft_printf("Introducing contestants...\n");
	while (i <= MAX_PLAYERS)
	{
		if (vm->player[i].active)
		{
			write_player(vm, i, j);
			j++;
		}
		i++;
	}
	init_process(vm);
}
