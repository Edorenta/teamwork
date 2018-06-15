#include "corewar.h"

//ajoute les maillons les uns a la suite des autres
void	add_process(t_vm *vm, t_proc *proc)
{
	if (vm->proc) //si des maillons existe deja, on ajoute ce nouveau a la suite
		proc->next = vm->proc;
	vm->proc = proc; //sinon c'est le premier maillon
}

int		set_proc_id(t_vm *vm)
{
	t_proc	*tmp;
	int		nb;

	nb = 0;
	tmp = vm->proc;
	if (!tmp)
		return (nb); //si id 0, c'est qu'il y a une erreur
	while (tmp) //parcours la list
	{
		if (tmp->id > nb) //ex: au 2eme tour, le 1er maillon = 1, donc on rentre dans le if
			nb = tmp->id;
		tmp = tmp->next;
	}
	return (nb + 1);//les id commence a 1, on envoi toujours +1 au nouveau
}

//initialise un maillon de la liste t_proc pour un joueur
t_proc	*create_process(t_vm *vm, int num)
{
	t_proc	*tmp;

	if (!(tmp = (t_proc*)ft_memalloc(sizeof(t_proc)))) //malloc de la node
		error("Malloc\n");
	tmp->id = set_proc_id(vm);
	tmp->num = num; //a quel joueur ca correspond
	tmp->pc = (MEM_SIZE / vm->nb_player) * ((num * (-1) - 1)); //
	tmp->last_pc = 0;
	ft_bzero(tmp->reg, sizeof(int) * (REG_NUMBER + 1)); //on met tous les registre a 0
	tmp->reg[1] = num;//on envoi le nom du joueur dans le registre 1
	tmp->carry = 0;
	tmp->last_live = 0;
	tmp->active = 1;
	tmp->op.active = 0;//pas sur une instruction par defaut (pour entrer dans le if)
	tmp->next = NULL;
	return (tmp);
}

//appel la creation de la list chainee de processus pour chaque player
void 	init_process(t_vm *vm)
{
	int i;

	i = 0;
	while (i <= MAX_PLAYERS)
	{
		if (vm->player[i].active)
			add_process(vm, create_process(vm, i * (-1))); //create_process => envoi du joueur
		i++;
	}
}

//
void	set_ctd(t_vm *vm)
{
	// SUJET: si trop de live dans un ctd OU tous les MAX_CHECKS
	if (vm->lives_in_cycle >= NBR_LIVE || vm->ctd_check >= MAX_CHECKS)
	{
		vm->ctd -= CYCLE_DELTA; //on decremente le ctd (de DELTA), => de - en - de temps pour live
		vm->ctd_check = 0;
		//
	}
	else
		vm->ctd_check++;
	vm->lives_in_cycle = 0; //reset nbr de live dans un ctd
}

//
void	kill_proc(t_vm *vm)
{
	t_proc *tmp;
	t_proc *t;

	tmp = vm->proc;
	while (tmp) //tant qu'il y a des process
	{
		//si actif ET si il n'y a pas eu de live durant le ctd
		if ((vm->cycle - tmp->last_live) >= vm->ctd && tmp->active) //?
		{
			tmp->active = 0; //on desactive le proc
			//verbosity pour les morts
		}

		//si le prochain proc est pas actif,
		if (tmp->next && !tmp->next->active)
		{
			t = tmp->next;
			tmp->next = tmp->next->next; //on le saute directement (utile?)
			free(t);
		}
		tmp = tmp->next;
	}
}

//
int		process_living(t_vm *vm)
{
	int		i;
	t_proc	*tmp;

	i = 0;
	tmp = vm->proc;
	if (vm->cycle < vm->next_ctd) //si on est pas a un ctd, on return 1 direct ==> process living
		return (1);
	kill_proc(vm);//on appel kill_proc qui test par rapport au dernier live et le ctd
	set_ctd(vm);//SUJET: decremente le ctd si besoin (tous les MAX_CHECKS)
	vm->next_ctd = vm->cycle + vm->ctd; //on set le prochain ctd,
	while (tmp) //si au moin 1 proc est actif on return 1
	{
		if (tmp->active)
			return (1);
		tmp = tmp->next;
	}
	return (0);//si aucun proc actif au ctd, return 0
}
