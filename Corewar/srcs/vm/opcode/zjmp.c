#include "corewar.h"

void	zjmp(t_vm *vm, t_proc *proc)
{
	if (proc->carry)//zjmp saute en fonction du carry
	{
		proc->pc = modulo(proc->op.pos_opcode + (proc->op.ar[0] % IDX_MOD),
		MEM_SIZE);
		proc->last_pc = proc->pc;
	}
	if (0x4 & vm->verbosity)
	{
		show_operations(proc);
		if (proc->carry)//check le carry pour l'affichage
			printf(" OK");//
		else
			printf(" FAILED");//
		printf("\n");//
	}
}
