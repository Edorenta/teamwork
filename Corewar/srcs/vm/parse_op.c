#include "corewar.h"

//
int			is_opcode(char data)
{
	if (data > 0 && data < 17) //si c'est une instruction
		return (1);
	return (0);
}

//initialise tous a 0, (utiliser + de bzero?, fusionner avec delete?)
void		init_op(t_op *op)
{
	op->active = 0;
	op->code = 0;
	op->ocp = 0;
	op->ar[0] = 0;
	op->ar[1] = 0;
	op->ar[2] = 0;
	op->ar_typ[0] = 0;
	op->ar_typ[1] = 0;
	op->ar_typ[2] = 0;
	op->loadtime = 0;
	op->pos_opcode = 0;
}

//
void		create_op(t_proc *proc, char data)
{
	int		i;

	i = 0;
	if (!is_opcode(data))
		return ;
	init_op(&proc->op);//directement un bzero
	proc->op.active = 1;
	proc->op.code = data; //code = value
	proc->op.loadtime = g_op_tab[data - 1].loadtime - 1; //cycle du process
	proc->op.pos_opcode = proc->pc; //position de l'opcode = program counter
}

//remet tous a zero pour l'op
void		delete_op(t_proc *proc)
{
	proc->op.code = 0;
	proc->op.ocp = 0;
	ft_bzero(proc->op.ar, 3);
	ft_bzero(proc->op.ar_typ, 3);
	proc->op.loadtime = 0;
	proc->op.pos_opcode = 0;
	proc->op.active = 0;
}

//retourne la taille que prennent les arguments de l'op, et recupere et stock les info dans la structure
int			find_args(t_vm *vm, t_proc *proc, int num, int pos)//num = num arg
{
	unsigned char	type;
	unsigned char	mask;

	type = proc->op.ocp;
	mask = 0xC0;//on part du premier
	mask = mask >> (2 * num);//on decale de 2 a chaque fois, en fnct de arg 1, 2, ou 3
	type = type & mask;
	type = type >> (6 - 2 * num);// d'abord => 110000 puis 001100 puis 000011, et la met au bon endroit
	proc->op.ar_typ[num] = type;
	if (type == REG_CODE)
	{
		get_reg(vm, proc, num, pos);
		// ft_printf("\n find_args: get_registre => %d\n", proc->op.ar[0]);
		// return (REG_SIZE);
		return (1);
	}
	if (type == DIR_CODE)
	{
		get_dir(vm, proc, num, pos);
		// ft_printf("\n find_args: get_dir => %d\n", proc->op.ar[1]);
		// ft_printf("\n find_args: get_dir => %d\n", proc->op.ar[2]);
		return ((g_op_tab[proc->op.code - 1].direct_size) ? 2 : 4);
	}
	if (type == IND_CODE)
	{
		get_ind(vm, proc, num, pos);
		return (IND_SIZE);
	}
	return (0);
}

//arg_available => mettre le mask t_IND a +1
int			fill_cur_op(t_vm *vm, t_proc *proc)
{
	int			i;
	int			pos;
	t_optab		*optab_ref;

	i = 0;
	pos = proc->pc;
	optab_ref = &g_op_tab[proc->op.code - 1]; //ptr sur le global_op_tab
	if (optab_ref->need_ocp)// seulement si l'op a besoin d'un ocp
	{
		pos++;//position du pc du proc
		proc->op.ocp = (unsigned char)vm->ram[pos % MEM_SIZE].mem;//contenu de la case memoire de l'ocp
		if (check_ocp(proc->op.ocp, proc->op.code))//si l'ocp est pas bon, on jump quand meme de sa valeur(?)
		{
			while (i < g_op_tab[proc->op.code - 1].nb_arg) //pour tous les arguments de l'op
			{
				//recupre et stocks les info des args pui:
				pos += find_args(vm, proc, i, pos);//retourne la taille de l'argument, et l'ajoute dans pc pour avancer le curseur
				i++;
			}
		}
		else //si check_ocp ==0, on return 0 (on appel pas l'op)
			return (0);
	}
	else //si il n'y a pas d'ocp, c'est forcement que le param est un direct (voir tableau)
	{
		get_dir(vm, proc, 0, pos);
		//-----D E B U G----
		// if (proc->op.ocp == 1) {
			// printf("\n----------live---------\n");
		// }
		//------------------
	}
	return (1);
}
