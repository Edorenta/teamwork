#include "corewar.h"

void	live(t_vm *vm, t_proc *proc)
{
	int num;

	//verifier que le premier arg est un registre valable?
	vm->lives_in_cycle++; //augmenter le live in cycle (nb de live dans un ctd)
	proc->last_live = vm->cycle + 1;
	num = proc->op.ar[0] * -1;//op.ar 0 pour l'argument 0, -1 car les joueur sont en negatif
	// printf("\nproc->op.ar[0] * -1 = %d\n", num);//

	if (4 & vm->verbosity)//afficher les operation (P player | l'instruction)
	{
		show_operations(proc);
		printf("\n");//
	}
	if (num >= 1 && num <= vm->nb_player) //si le num recup correspond bien a un joueur
	{
		//
		vm->player[num].life_signal++;//je m'en servais vraiment de ca? je sais plus
		vm->player[num].last_live = vm->cycle;
		//mode verbose, afficher que le player dise qu'il est en vie?
	}
}
