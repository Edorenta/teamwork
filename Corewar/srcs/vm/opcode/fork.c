#include "corewar.h"

static void	registre_cpy(t_proc *proc, t_proc *new)//les memes reg que le proc cloné
{
	int i;

	i = 0;
	while (i <= REG_NUMBER)
	{
		new->reg[i] = proc->reg[i];
		i++;
	}
}

static void	clone_proc(t_proc *proc, t_proc *new)
{
	registre_cpy(proc, new);
	new->carry = proc->carry;
	new->last_live = proc->last_live;
	new->num = proc->num;
}

void	op_fork(t_vm *vm, t_proc *proc)
{
	t_proc	*new;

	new = create_process(vm, proc->num); //pour fork on cree et init un new process avec le bon pc
	init_op(&new->op);
	//test de l'ocp de l'argument?
	new->pc = modulo(proc->op.pos_opcode + (proc->op.ar[0] % IDX_MOD),
	MEM_SIZE);
	new->last_pc = new->pc;
	clone_proc(proc, new);
	add_process(vm, new);
	if (0x4 & vm->verbosity)
	{
		show_operations(proc);
		printf(" (%d)\n", new->pc);//
	}
}
