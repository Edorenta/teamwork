#include "corewar.h"

//ouai bon xD
void		show_mem(t_vm *vm)
{
	int		i;

	i = 0;
	ft_printf("0x0000 : "); //
	while (i < MEM_SIZE) //on parcours toutes la memoire
	{
		if (!(i % 64) && i) //seulement si i existe, et ..........
			ft_printf("%#.4x : ", i); //affichage de l'adresse (precision de 4, avec l'hexa)
		ft_printf("%02x ", (unsigned char)vm->ram[i].mem); //affiche le contenu de cette case mem = contenu
		if (i / 64 != (i + 1) / 64)//
			ft_printf("\n");
		i++;
	}
	ft_printf("\n\n");
}
