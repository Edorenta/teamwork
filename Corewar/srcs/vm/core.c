#include "corewar.h"

//si option -d
void		dump(t_vm *vm)
{
	if (vm->cycle == vm->dump) //seuement si le cycle correspond au num demandé
	{
		show_mem(vm);// on affiche  la memoire
		exit(1);
	}
}

//fonction principale du core: run tous les process
//
//	tmp pour moi: life_signal, 64, calcul, tot, last_one
void			run(t_vm *vm)
{
	t_proc			*proc;

	while (process_living(vm))//tant qu'il y a des process en vie
	{
		if (!((vm->cycle + 1) % vm->ctd)) //si le cycle arrive au cycle to die
			reset_live(vm); //on reset les lives

		//verbosity pour les cycles
		//call_ncurses ?

		proc = vm->proc;
		while (proc != NULL)//on parcours tous les process, (liste chainee)
		{
			//if (proc->active)
			//	exec_proc(vm, proc);//execute le process => pas encore cree
			proc->last_pc = proc->pc; //la derniere operation est mise a jour
			proc = proc->next;//et on next la current
		}
		vm->cycle++; //quand chaque process est terminé, on augmente le nb de cycle ecoulé
		if (vm->dump != -1) //ne pas appeler dump si ncurses est activé
			dump(vm);//si on a l'option -d => dump
	}
	if (vm->last_one) //test avec la vm
		ft_printf("Last_one => %s\n", vm->last_one->file_name);
}
