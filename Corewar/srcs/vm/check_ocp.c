/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ocp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourne <jjourne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 23:25:55 by jjourne           #+#    #+#             */
/*   Updated: 2018/06/28 15:51:02 by jjourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		arg_available(int ocp_chunk, int opcode, int num_arg)
{
	if (ocp_chunk < 1 || ocp_chunk > 3)
		return (0);
	if (ocp_chunk == 3)
		ocp_chunk += 1;
	if (ocp_chunk & g_op_tab[opcode - 1].ocp[num_arg])
		return (1);
	return (0);
}

int		check_ocp(int ocp, int opcode)
{
	int		nb_arg;

	nb_arg = g_op_tab[opcode - 1].nb_arg;
	if (nb_arg >= 1 && !arg_available((ocp & 0xC0) >> 6, opcode, 0))
		return (0);
	if (nb_arg >= 2 && !arg_available((ocp & 0x30) >> 4, opcode, 1))
		return (0);
	if (nb_arg >= 3 && !arg_available((ocp & 0xC) >> 2, opcode, 2))
		return (0);
	return (1);
}
