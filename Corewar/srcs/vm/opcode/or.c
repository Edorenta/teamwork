#include "corewar.h"

void	or(t_vm *vm, t_proc *proc)
{
	unsigned int arg1;
	unsigned int arg2;

	if (!check_params(&proc->op)) //check si les registres sont conformes
		return ;

	if (proc->op.ar_typ[0] == T_REG) //ar_type fill dans find_args
		arg1 = proc->reg[proc->op.ar[0]]; //si registre, on get l'info du registre
	else //sinon de la memoire a cet endroit
		arg1 = proc->op.ar[0];

	if (proc->op.ar_typ[1] == T_REG)
		arg2 = proc->reg[proc->op.ar[1]];
	else
		arg2 = proc->op.ar[1];

	num = arg1 | arg2;
	proc->reg[proc->op.ar[2]] = num;
	proc->carry = (num) ? 0 : 1;

	if (4 & vm->verbosity)//afficher les operation (P player | l'instruction)
	{
		show_operations(proc);
		printf("\n");//
	}
}
