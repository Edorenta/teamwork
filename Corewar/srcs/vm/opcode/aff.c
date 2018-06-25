#include "corewar.h"

void	aff(t_vm *vm, t_proc *proc)
{
	// int reg;

	if (!check_params(&proc->op))
		return ;
	//+ de checks?
	//modulo 256?
	// reg = proc->op.ar[0];
	if (0x04 & vm->verbosity)
	{
		show_operations(proc);
		printf("\n");//
	}
}
