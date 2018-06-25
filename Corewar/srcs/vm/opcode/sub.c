#include "corewar.h"

void	sub(t_vm *vm, t_proc *proc)
{
	int	n;

	if (!check_params(&proc->op))
		return ;
	//+ de check?
	n = proc->reg[proc->op.ar[0]] - proc->reg[proc->op.ar[1]];
	proc->reg[proc->op.ar[2]] = n;
	proc->carry = (n == 0) ? 1 : 0;
	if (0x4 & vm->verbosity)
	{
		show_operations(proc);
		printf("\n");//
	}
}
