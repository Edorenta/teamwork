/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourne <jjourne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 23:26:12 by jjourne           #+#    #+#             */
/*   Updated: 2018/06/29 05:18:40 by jjourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		is_opcode(char data)
{
	if (data > 0 && data < 17)
		return (1);
	return (0);
}

void	dump(t_vm *vm)
{
	if (vm->cycle == vm->dump)
	{
		show_mem(vm);
		//du coup free ou pas? :p
		exit(EXIT_SUCCESS);
	}
}

void	exec_proc(t_vm *vm, t_proc *proc)
{
	vm->ram[proc->pc % MEM_SIZE].pc = 0;
	if (!proc->op.active)
	{
		if (is_opcode(vm->ram[proc->pc % MEM_SIZE].mem))
			create_op(proc, vm->ram[proc->pc % MEM_SIZE].mem);
		else
			proc->pc = (proc->pc + 1) % MEM_SIZE;
	}
	else
	{
		proc->op.loadtime--;
		if (proc->op.loadtime <= 0)
		{
			if (fill_cur_op(vm, proc))
				g_op_tab[proc->op.code - 1].func(vm, proc);
			if (proc->op.code != 9 ||
				(proc->op.code == 9 && !proc->carry))
				proc->pc += move_pc(proc);
			delete_op(proc);
		}
	}
	vm->ram[proc->pc % MEM_SIZE].pc = proc->num;
}

void	run(t_vm *vm)
{
	t_proc	*proc;
	int i = 0;//

	while (process_living(vm))
	{
		if (!((vm->cycle + 1) % vm->ctd))
			reset_live(vm);
		if (2 & vm->verbosity)
			ft_printf("It is now cycle %d\n", vm->cycle + 1);
		proc = vm->proc;
		while (proc != NULL)
		{
			if (proc->active)
				exec_proc(vm, proc);
			proc->last_pc = proc->pc;
			proc = proc->next;
		}
		vm->cycle++;
		if (vm->dump != -1)
			dump(vm);
		send_mem(vm);
	printf("cycle = %d\n", vm->cycle);
		send_num_player(vm);
	}
	if (vm->last_one)
		ft_printf("Last_one => %s\n", vm->last_one->file_name);
	if (vm->vizu)
		send_to_socket(vm, "<end>", 5);
}
