#include "corewar.h"

void	add(t_vm *vm, t_proc *proc)
{
	int sum;

	if (!check_params(&proc->op))
		return ;
	//+ de checks?
	sum = proc->reg[proc->op.ar[0]] + proc->reg[proc->op.ar[1]];
	proc->reg[proc->op.ar[2]] = sum;
	proc->carry = (sum == 0) ? 1 : 0;
	if (0x4 & vm->verbosity)
	{
		show_operations(proc);
		printf("\n");//
	}
}
