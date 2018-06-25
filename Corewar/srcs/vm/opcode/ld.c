#include "corewar.h"

void		proc_reg(t_vm *vm, t_proc *proc, int reg_nb)
{
	int		addr;

	addr = 0;
	addr = proc->op.ar[0] % IDX_MOD;
	proc->reg[reg_nb] = 0;//remet a zero le int de ce registre (remet au porpe)
	proc->reg[reg_nb] = (unsigned char)vm->ram[modulo(proc->op.pos_opcode
		+ addr, MEM_SIZE)].mem; //stock dans le registre la val de la memrory a cette emplacement
	proc->reg[reg_nb] <<= 8;// se decale lui meme de 8
	proc->reg[reg_nb] |= (unsigned char)vm->ram[modulo(proc->op.pos_opcode
		+ addr + 1, MEM_SIZE)].mem;//+1
	proc->reg[reg_nb] <<= 8;
	proc->reg[reg_nb] |= (unsigned char)vm->ram[modulo(proc->op.pos_opcode
		+ addr + 2, MEM_SIZE)].mem;//+2
	proc->reg[reg_nb] <<= 8;
	proc->reg[reg_nb] |= (unsigned char)vm->ram[modulo(proc->op.pos_opcode
		+ addr + 3, MEM_SIZE)].mem;//+3
}

void		ld(t_vm *vm, t_proc *proc)
{
	int		reg_nb;

	reg_nb = proc->op.ar[1];
	if (!check_params(&proc->op))
		return ;

	//si arg0 est un reg ?
	//

	if (proc->op.ar_typ[0] == IND_CODE)
		proc_reg(vm, proc, reg_nb);
	else//marche pour DIR
		proc->reg[reg_nb] = proc->op.ar[0];
	proc->carry = (proc->reg[reg_nb] == 0) ? 1 : 0;
	proc->op.ar[0] = proc->reg[reg_nb];//pour l'affichage dans display_args
	if (0x4 & vm->verbosity)
	{
		show_operations(proc);
		printf("\n");//
	}
}
