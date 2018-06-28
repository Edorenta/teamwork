/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourne <jjourne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 19:33:51 by jjourne           #+#    #+#             */
/*   Updated: 2018/06/27 23:13:39 by jjourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

//
void	reset_live(t_vm *vm)
{
	int				i;

	i = 1;
	while (i <= vm->nb_player) //pour tous les joueurs
	{
		vm->player[i].life_signal = 0; //pour plus tard
		++i;
	}
}

//F: init new player
void	new_player(t_vm *vm, int nb, char *str)
{
	vm->player[nb].active = 1;
	vm->player[nb].file_name = str;
}

//ouvre et lit le fichier du champion en question
char	*get_data(t_player *player, char *buff)
{
	int		fd;
	int		ret;

	fd = 0;
	ret = 0;
	fd = open(player->file_name, O_RDONLY);
	if (fd < 0)
		exit_error("File error");
	player->read_ret = read(fd, buff, sizeof(t_header) + CHAMP_MAX_SIZE);//
	if (player->read_ret < (int)sizeof(t_header))//je dois incure le header
		exit_error("File size error");
	return (buff);
}

//recupere la taille du champion (int dans le header du .cor)
int		get_prog_size(char *data)
{
	int ret;

	data += MAGIC_NB;
	data += PROG_NAME; //se place au bon endroit
	ret = 0x0;//juste 0 => lol
	ret = ret | (unsigned char)*data; //premiere partie (char)
	ret = ret << 8; //on le decale d'un octet
	ret = ret | (unsigned char)data[1];//2eme partie
	ret = ret << 8;//etc..
	ret = ret | (unsigned char)data[2];
	ret = ret << 8;
	ret = ret | (unsigned char)data[3];//fin de l'int
	if (ret > CHAMP_MAX_SIZE) //check la taille du champ
		exit_error("Champ is too big");
	return (ret);
}

//check et ajoute les infos d'un player (nom, comment), et met le champion en memoire
void 	write_player(t_vm *vm, int nb, int num)
{
	int i;
	char *data;
	int prog_size;
	char	buff[sizeof(t_header) + CHAMP_MAX_SIZE];//contient la taille max du champion
	char c[128] = {0};

	//pour set les champion au bon endroit dans la memoire
	i = (MEM_SIZE / vm->nb_player) * num;//pour placer la value de i au bon endroit en fonction du nombre de champions
	data = get_data(&vm->player[nb], buff);//on envoi le player et le buffer (renvoi le fichier du champion)
	ft_memcpy(vm->player[nb].name, data + MAGIC_NB, PROG_NAME);//copie le nom du champion dans vm->player[nb].name (le nom est apres le magic_number)
	ft_strlen(vm->player[nb].name) ? 0 : exit_error("Empty name"); //check si le nom est vide alors error

			(nb == vm->nb_player || vm->nb_player == 1) ? ft_sprintf(c, "%s", vm->player[nb].name) : ft_sprintf(c, "%s,", vm->player[nb].name);
			send_to_socket(vm, c, 0);

	ft_memcpy(vm->player[nb].comments, data + MAGIC_NB + PROG_NAME + PROG_SIZE, PROG_COMS); //copie le comments dans vm->player[nb].comments (apres le prog_size)
	ft_strlen(vm->player[nb].comments) ? 0 : exit_error("Empty comments");//check si le comment est vide alors error
	prog_size = get_prog_size(data); //recup la taille du prog
	/**/if (!prog_size/*si pas de taille*/ || vm->player[nb].read_ret != prog_size + sizeof(t_header)) //si le retour du read ne correspond pas a la taille du prog
		exit_error("Bad prog_size");
	ft_printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n", //on print toutes les informations recuperes !!!!!
		nb, prog_size, vm->player[nb].name, vm->player[nb].comments);
	prog_size += i;//place prog_size a la valeur de fin du programme du champion
	while (i < prog_size)//tant que i est < a la value de fin du prog, remplir la memory avec le champion
	{
		vm->ram[i % MEM_SIZE].mem = (unsigned char)*(data + SRC_BEGIN);
		vm->ram[i % MEM_SIZE].num = (num + 1) * -1;
		data++;
		i++;
	}
}

//parcours tous les joueurs possible et si actif, l'ecrit
void	create_players(t_vm *vm)
{
	int i;
	int j;

	i = 1;
	j = 0;
	ft_printf("Introducing contestants...\n");
	send_to_socket(vm, "[", 0);
	while (i <= MAX_PLAYERS)
	{
		if (vm->player[i].active)
		{
			write_player(vm, i, j); //j = player actif reel
			j++;
		}
		i++;
	}
	send_to_socket(vm, "]\n\n", 0);
	init_process(vm);
}
