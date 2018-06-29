/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_proc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourne <jjourne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 17:04:38 by jjourne           #+#    #+#             */
/*   Updated: 2018/06/29 03:55:50 by jjourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		move_pc(t_proc *proc)
{
	int				i;
	int				move;
	t_optab			*ref;

	i = 0;
	move = 1;
	ref = &g_op_tab[proc->op.code - 1];
	if (!ref->need_ocp)
		return ((ref->direct_size) ? move + 2 : move + 4);
	else
		move++;
	if (ref->nb_arg >= 1)
		move += count_octet((0xC0 & proc->op.ocp) >> 6, ref);
	if (ref->nb_arg >= 2)
		move += count_octet((0x30 & proc->op.ocp) >> 4, ref);
	if (ref->nb_arg >= 3)
		move += count_octet((0xC & proc->op.ocp) >> 2, ref);
	return (move);
}

void	set_ctd(t_vm *vm)
{
	if (vm->lives_in_cycle >= NBR_LIVE || vm->ctd_check >= MAX_CHECKS)
	{
		vm->ctd -= CYCLE_DELTA;
		vm->ctd_check = 0;
	}
	else
		vm->ctd_check++;
	vm->lives_in_cycle = 0;
}

int		set_proc_id(t_vm *vm)
{
	t_proc	*tmp;
	int		nb;

	nb = 0;
	tmp = vm->proc;
	if (!tmp)
		return (nb);
	while (tmp)
	{
		if (tmp->id > nb)
			nb = tmp->id;
		tmp = tmp->next;
	}
	return (nb + 1);
}
