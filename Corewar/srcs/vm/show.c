#include "corewar.h"

void		show_mem(t_vm *vm)
{
	int		i;

	i = 0;
	ft_printf("0x0000 : ");
	while (i < MEM_SIZE) //on parcours toutes la memoire
	{
		if (!(i % 64) && i)
			ft_printf("%#.4x : ", i); //affichage de l'adresse (precision de 4, avec l'hexa)
		ft_printf("%02x ", (unsigned char)vm->ram[i].mem); //affiche le contenu de cette case mem = contenu
		if (i / 64 != (i + 1) / 64)
			ft_printf("\n");
		i++;
	}
	ft_printf("\n\n");
}

void		send_mem(t_vm *vm)
{
	int		i;
	char c[20000];

	i = 0;
	while (i < MEM_SIZE)
	{
		!((i + 1) % 64) ? ft_sprintf(c, "%02x", (unsigned char)vm->ram[i].mem)
		: ft_sprintf(c, "%02x ", (unsigned char)vm->ram[i].mem);
		send_to_socket(vm, c, 0);
		if (i / 64 != (i + 1) / 64)
			send_to_socket(vm, "\n", 0);
		i++;
	}
	send_to_socket(vm, "\n", 0);
}

void		send_num_player(t_vm *vm)
{
	int		i;
	char c[20000];

	i = 0;

	while (i < MEM_SIZE)
	{
		i == MEM_SIZE - 1 ? ft_sprintf(c, "%d", ft_iabs(vm->ram[i].num)) : ft_sprintf(c, "%d,", ft_iabs(vm->ram[i].num));
		send_to_socket(vm, c, 0);
		i++;
	}
	send_to_socket(vm, "\n\n", 0);
}
