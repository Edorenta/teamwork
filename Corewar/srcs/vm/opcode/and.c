#include "corewar.h"

void	and(t_vm *vm, t_proc *proc)
{
	unsigned int arg1;
	unsigned int arg2;

	if (!check_params(&proc->op)) //check si les registres sont conformes
		return ;

//---------------arg1---------------
//voir pour le changement de ar_ype en DIR_CODE pour un registre sur l'affichage du dump
	printf("\n-------argument AND before if-------\n");
	printf("ar_type = %d, T_REG = %d\n", proc->op.ar_typ[0], T_REG);
	if (proc->op.ar_typ[0] == REG_CODE) //ar_type fill dans find_args
	{
		arg1 = proc->reg[proc->op.ar[0]]; //si registre, on get l'info du registre
		printf("\nregistre\n");
		printf("arg1 value : %u, proc->op.ar[0] = %d\n", arg1, proc->op.ar[0]);
	}
	else if (proc->op.ar_typ[0] == IND_CODE) //prendre la value de l'adresse pointe
	{
		arg1 = get_indirect(vm, &proc->op, 0); //0 pour le premier arg
		printf("\nindirecte\n");
		printf("arg1 value : %u, proc->op.ar[0] = %d\n", arg1, proc->op.ar[0]);
	}
	else //sinon si direct on get la value de l'arg
	{
		arg1 = proc->op.ar[0];
		printf("\ndirect\n");
		printf("arg1 value : %u, proc->op.ar[0] = %d\n", arg1, proc->op.ar[0]);
	}

//------------arg2------------------
	if (proc->op.ar_typ[1] == REG_CODE) //ar_type fill dans find_args
	{
		arg2 = proc->reg[proc->op.ar[1]]; //si registre, on get l'info du registre
		printf("\nregistre\n");
		printf("arg2 value : %u, proc->op.ar[0] = %d\n", arg2, proc->op.ar[1]);
	}
	else if (proc->op.ar_typ[1] == IND_CODE) //prendre la value de l'adresse pointe
	{
		arg2 = get_indirect(vm, &proc->op, 1); //0 pour le 2eme arg
		printf("\nindirecte\n");
		printf("arg2 value : %u, proc->op.ar[0] = %d\n", arg2, proc->op.ar[1]);
	}
	else //sinon si direct on get la value de l'arg
	{
		arg2 = proc->op.ar[1];
		printf("\ndirect\n");
		printf("arg2 value : %u, proc->op.ar[0] = %d\n", arg2, proc->op.ar[1]);
	}

//-----affectation des values

	proc->reg[proc->op.ar[2]] = arg1 & arg2;
	proc->carry = (proc->reg[proc->op.ar[2]] == 0) ? 1 : 0;
	printf("reg[r2] = %d, carry = %d\n", proc->reg[proc->op.ar[2]], proc->carry);

	if (4 & vm->verbosity)//afficher les operation (P player | l'instruction)
	{
		show_operations(proc);
		printf("\n");//
	}
}
