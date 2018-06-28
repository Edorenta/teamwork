#include "corewar.h"

//si option -d
void		dump(t_vm *vm)
{
	if (vm->cycle == vm->dump) //seuement si le cycle correspond au num demandé
	{
		show_mem(vm);// on affiche  la memoire
		//du coup free ou pas? :p
		exit(EXIT_SUCCESS);
	}
}

//	tmp: create => loadtime le calcul, signe, pc ram
void			exec_proc(t_vm *vm, t_proc *proc)//pc_move
{
	vm->ram[proc->pc % MEM_SIZE].pc = 0;
	if (!proc->op.active) //si le process n'est pas n'est  pas en train d'executer une instruction
	{
		if (is_opcode(vm->ram[proc->pc % MEM_SIZE].mem)) //on envoi la case memoire
			create_op(proc, vm->ram[proc->pc % MEM_SIZE].mem);//on met le proc actif et on initialise op
		else
			proc->pc = (proc->pc + 1) % MEM_SIZE;//si ce n'est pas un opcode on avance (tant pis si le champ est mal coder, on avance)
	}
	else //quand le loadtime es a zero, on prend les params et on execute l'op
	{
		proc->op.loadtime--;//cycle d'une op, on attend qu'il arrive a 0 pour l'executer
		if (proc->op.loadtime <= 0)
		{
			if (fill_cur_op(vm, proc)) //rempli opcode courant en fonction de ses params
				//en dessous => appel chaque fonction qui correspond a l'instruction (avec le proc correspondant)
				g_op_tab[proc->op.code - 1].func(vm, proc);//opcode.c => modif pour ptr sur fonction
			if (proc->op.code != 9 || //l'instruction zjump modifie le pc, donc on ne le refait pas ici
				(proc->op.code == 9 && !proc->carry))//zjump ne marche qu'avec le carry, sans carry pas de zjmp donc on move
				proc->pc += move_pc(proc);//on move le pc du process
			delete_op(proc);//remet a zero l'instruction en cours, avant la prochaine
		}
	}
	vm->ram[proc->pc % MEM_SIZE].pc = proc->num;//num joueur a l'endroit du program counter
}

//fonction principale du core: run tous les process
void			run(t_vm *vm) //reset_live
{
	t_proc			*proc;

	while (process_living(vm))//tant qu'il y a des process en vie (check avec le ctd)
	{
		if (!((vm->cycle + 1) % vm->ctd)) //si le cycle arrive au cycle to die
			reset_live(vm); //on reset les lives
		if (2 & vm->verbosity)
			ft_printf("It is now cycle %d\n", vm->cycle + 1);
		proc = vm->proc;
		while (proc != NULL)//on parcours tous les process, (liste chainee)
		{
			if (proc->active)
				exec_proc(vm, proc);//execute le process => pas encore cree
			proc->last_pc = proc->pc; //la derniere operation est mise a jour
			proc = proc->next;//et on next la current
		}
		vm->cycle++; //quand chaque process est terminé, on augmente le nb de cycle ecoulé
		if (vm->dump != -1) //ne pas appeler dump si ncurses est activé
			dump(vm);//si on a l'option -d => dump
		send_mem(vm);
		send_num_player(vm);
	}
	if (vm->last_one) //test avec la vm (le nom ou le fichier?)
		ft_printf("Last_one => %s\n", vm->last_one->file_name);
}
