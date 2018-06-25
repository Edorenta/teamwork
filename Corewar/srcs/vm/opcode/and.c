#include "corewar.h"

void	and(t_vm *vm, t_proc *proc)
{
	unsigned int arg1;
	unsigned int arg2;

	if (!check_params(&proc->op)) //check si les registres sont conformes
		return ;

//---------------arg1---------------
//voir pour le changement de ar_ype en DIR_CODE pour un registre sur l'affichage du dump
	if (proc->op.ar_typ[0] == REG_CODE) //ar_type fill dans find_args
		arg1 = proc->reg[proc->op.ar[0]]; //si registre, on get l'info du registre
	else if (proc->op.ar_typ[0] == IND_CODE) //prendre la value de l'adresse pointe
		arg1 = get_indirect(vm, &proc->op, 0); //0 pour le premier arg
	else //sinon si direct on get la value de l'arg
		arg1 = proc->op.ar[0];

//------------arg2------------------
	if (proc->op.ar_typ[1] == REG_CODE) //ar_type fill dans find_args
		arg2 = proc->reg[proc->op.ar[1]]; //si registre, on get l'info du registre
	else if (proc->op.ar_typ[1] == IND_CODE) //prendre la value de l'adresse pointe
		arg2 = get_indirect(vm, &proc->op, 1); //0 pour le 2eme arg
	else //sinon si direct on get la value de l'arg
		arg2 = proc->op.ar[1];
	proc->reg[proc->op.ar[2]] = arg1 & arg2;
	proc->carry = (proc->reg[proc->op.ar[2]] == 0) ? 1 : 0;

	if (4 & vm->verbosity)//afficher les operation (P player | l'instruction)
	{
		show_operations(proc);
		printf("\n");//
	}
}
