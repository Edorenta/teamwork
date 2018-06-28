/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourne <jjourne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 23:27:40 by jjourne           #+#    #+#             */
/*   Updated: 2018/06/28 20:36:45 by jjourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		show_mem(t_vm *vm)
{
	int		i;

	i = 0;
	ft_printf("0x0000 : ");
	while (i < MEM_SIZE)
	{
		if (!(i % 64) && i)
			ft_printf("%#.4x : ", i);
		ft_printf("%02x ", (unsigned char)vm->ram[i].mem);
		if (i / 64 != (i + 1) / 64)
			ft_printf("\n");
		i++;
	}
	ft_printf("\n\n");
}

void		send_mem(t_vm *vm)
{
	int		i;
	char	s1[8258];
	char	s2[130];

	i = 0;
	ft_bzero(s1, 8258);
	if (vm->vizu)
	{
		while (i < MEM_SIZE)
		{
			ft_bzero(s2, 130);
			ft_sprintf(s2, "%02x", (unsigned char)vm->ram[i].mem);
			s1[0] ? ft_strcat(s1, s2) : ft_strcpy(s1, s2);
			if (i / 64 != (i + 1) / 64)
				ft_strcat(s1, "\n");
			i++;
		}
		ft_strcat(s1, "\n");
		send_to_socket(vm, s1);
	}
}

void		send_num_player(t_vm *vm)
{
	int		i;
	char	s1[4098];
	char	c;

	i = 0;
	ft_bzero(s1, 4098);
	if (vm->vizu)
	{
		while (i < MEM_SIZE)
		{
			c = (char)('0' + ft_iabs(vm->ram[i].num));
			s1[i] = c;
			i++;
		}
		s1[i] = '\n';
		s1[i + 1] = '\0';
		send_to_socket(vm, s1);
	}
}

static void	display_args(t_proc *proc, int n)
{
	if (proc->op.ar_typ[n] == REG_CODE)
		ft_printf("r");
	ft_printf("%d", proc->op.ar[n]);
}

void		show_operations(t_proc *proc)
{
	int		nb_arg;
	int		i;

	i = 0;
	nb_arg = g_op_tab[proc->op.code - 1].nb_arg;
	ft_printf("P%5d | %s", proc->id + 1, g_op_tab[proc->op.code - 1].inst);
	while (i < nb_arg)
	{
		ft_printf(" ");
		display_args(proc, i);
		i++;
	}
}
