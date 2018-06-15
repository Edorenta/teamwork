#include "corewar.h"

//ocp_chunk valeur du morceaux recup par le mask
int		arg_available(int ocp_chunk, int opcode, int num_arg)//est appelé pour chaque argument, check la value
{
	if (ocp_chunk < 1 || ocp_chunk > 3) //si ce n'est pas entre 2 et 3 arguments, error
		return (0);
	if (ocp_chunk == 3) //permet d'utiliser les masks plus facilement, chaque arg est egale a un 1
		ocp_chunk += 1; //voir define t_ind +1 pour le mask binaire 0100 a la place de 0011
	if (ocp_chunk & g_op_tab[opcode - 1].ocp[num_arg]) //si l'ocp get correspond bien a l'ocp de l'instruction dans le tab global
		return (1); //alors l'ocp est correct
	return (0); //sinon error
}

int		check_ocp(int ocp, int opcode)
{
	int		nb_arg;

	nb_arg = g_op_tab[opcode - 1].nb_arg;

	// le dernier parametre de arg available: 0 = 1er arg, 1 = 2em arg, 2 = 3em arg
	// en fonction du nombre d'argument, passe dans tous les if necessaires
	if (nb_arg >= 1 && !arg_available((ocp & 0xC0) >> 6, opcode, 0))//prend que la value necessaire et l'envoi a droite
		return (0);
	if (nb_arg >= 2 && !arg_available((ocp & 0x30) >> 4, opcode, 1))
		return (0);
	if (nb_arg >= 3 && !arg_available((ocp & 0xC) >> 2, opcode, 2))
		return (0);
	return (1);
}
