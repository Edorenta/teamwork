#include "corewar.h"

//soit sur 2 soit sur 4,, recupere la value d'un direct
void				get_dir(t_vm *vm, t_proc *proc, int num, int pos)
{
	unsigned int	value;

	value = 0x0; //juste 0
	value = (unsigned char)vm->ram[(pos + 1) % MEM_SIZE].mem; //le cast pour pas avoir de probleme avec la memoire
	value = value << 8;// on decale de 8 la value, ex 1 => 0000 0001 => 0000 0001 0000 0000
	value = value | (unsigned char)vm->ram[(pos + 2) % MEM_SIZE].mem;
	if (g_op_tab[proc->op.code - 1].direct_size)//si c'est un short
	{
		if ((value & 0x8000) == 0x8000)//si le bit de signe est 1 ==> 1000 0000 0000 0000
			value = (value - USHRT_MAX) - 1;//valeur max - value, pour recuperer la val en signed
		proc->op.ar[num] = value; //stock la value dans l'argument qui faut de l'op
		return ;
	}
	value = value << 8;
	value = value | (unsigned char)vm->ram[(pos + 3) % MEM_SIZE].mem;
	value = value << 8;
	value = value | (unsigned char)vm->ram[(pos + 4) % MEM_SIZE].mem;
	proc->op.ar[num] = value;
}

//recupere la value d'un registre
void				get_reg(t_vm *vm, t_proc *proc, int num, int pos)
{
	unsigned char	value;

	// value = (unsigned char)vm->ram[(pos + REG_SIZE) % MEM_SIZE].mem;//recupere le num du registre //+1 ou +reg_size?
	value = (unsigned char)vm->ram[(pos + 1) % MEM_SIZE].mem;//recupere le num du registre
	proc->op.ar[num] = value;
}

//recupere la value d'un indirecte
void				get_ind(t_vm *vm, t_proc *proc, int num, int pos) //dans le parsing
{
	unsigned int	value;

	value = 0;
	value = value | (unsigned char)vm->ram[(pos + 1) % MEM_SIZE].mem;
	value = value << 8;
	value = value | (unsigned char)vm->ram[(pos + 2) % MEM_SIZE].mem;
	proc->op.ar[num] = value;
	if ((value & 0x8000) == 0x8000) //bit de signe (voir plus haut)
		proc->op.ar[num] = (value - USHRT_MAX) - 1;
}

int					get_indirect(t_vm *vm, t_op *op, int nb_arg) //pour les instructions
{
	int	value;
	int	pos;

	value = 0x0;
	pos = op->pos_opcode + (op->ar[nb_arg] % IDX_MOD); //zone memoire de 'adresse pointé / pas de - pour allez en arriere?
	value |= (unsigned char)vm->ram[modulo(pos, MEM_SIZE)].mem;
	value = value << 8;
	value |= (unsigned char)vm->ram[modulo(pos + 1, MEM_SIZE)].mem;
	value = value << 8;
	value |= (unsigned char)vm->ram[modulo(pos + 2, MEM_SIZE)].mem;
	value = value << 8;
	value |= (unsigned char)vm->ram[modulo(pos + 3, MEM_SIZE)].mem;

	return (value);
}
