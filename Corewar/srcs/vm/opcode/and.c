#include "corewar.h"

void	and(t_vm *vm, t_proc *proc)
{
	unsigned int arg1;
	unsigned int arg2;

	if (!check_params(&proc->op)) //check si les registres sont conformes
		return ;

//---------------arg1---------------
	if (proc->op.ar_typ[0] == T_REG) //ar_type fill dans find_args
		arg1 = proc->reg[proc->op.ar[0]]; //si registre, on get l'info du registre
	else if (proc->op.ar_typ[0] == T_IND) //prendre la value de l'adresse pointe
		arg1 = get_indirect(vm, &proc->op, 0); //0 pour le premier arg
	else //sinon si direct on get la value de l'arg
		arg1 = proc->op.ar[0];

//------------arg2------------------

	num = arg1 & arg2;
	proc->reg[proc->op.ar[2]] = num;
	proc->carry = (num) ? 0 : 1;

	if (4 & vm->verbosity)//afficher les operation (P player | l'instruction)
	{
		show_operations(proc);
		printf("\n");//
	}
}
