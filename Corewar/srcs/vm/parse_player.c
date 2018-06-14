/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourne <jjourne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 13:34:27 by jjourne           #+#    #+#             */
/*   Updated: 2018/06/13 19:35:35 by jjourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

//retourne la premiere place dipo pour un champion
int		first_free_nb_player(t_vm *vm)
{
	int i;

	i = 1;
	while (i <= MAX_PLAYERS)
	{
		if (!vm->player[i].active)
			return (i);
		i++;
	}
	return (0);
}

//si l'emplacement dem par -n est libre
int		is_free_nb_player(t_vm *vm, int nb)
{
	if (!vm->nb_player) //si il n'y a pas encore de joueur(?)
		return (1);
	if (vm->player[nb].active) //si le player dem est actif, return 0 (emplacement no  disp)
		return (0);
	return (1);
}

//recherche si l'option -n est presente
int		search_nb_player(char **argv, int arg_num)
{
	if (arg_num - 2 > 0) //si on ne depasse pas la limite
		if (ft_strstr(argv[arg_num - 2], "-n")) //si l'option -n est presente
			return (1);
	return (0);
}

//get le num du joueur (sont emplacement), et fais les checks
int		get_nb_player(t_vm *vm, char **argv, int arg_num)
{
	int ret;

	ret = 0;
	if (search_nb_player(argv, arg_num)) //si l'option -n est presente
	{
		ret = ft_atoi(argv[arg_num - 1]); //
		if (ret > 0 && ret < 5 && is_free_nb_player(vm, ret))//check si on depasse pas les limites, et si l'emplacement est dispo
			return (ret);
		else
			return (first_free_nb_player(vm));//sinon le premier dispo
	}
	else
		return (first_free_nb_player(vm)); //sinon retourne le premier emplacement dispo
	return (0);
}

//recherche du/des champion(s) passé en arguments
int		search_players(t_vm *vm, int argc, char **argv)
{
	int i;
	int res; //supr, et appeler directement dans new player
	char *tmp;

	i = 1;
	res = 0;
	tmp = NULL;
	//add vm->player = 0?
	while (i < argc) //parcours tous les arguments
	{
		//si l'argument contient .cor (strstr dans tmp) ET si tmp != 4 || .cor en millieu de nom?
		if ((tmp = ft_strstr(argv[i], ".cor")) && !tmp[4])
		{
			vm->nb_player++; //apres les errors? (+ de check?)
			//si vm->nb_player est superieur au max de champion possible, error
			if (vm->nb_player > MAX_PLAYERS)
				exit_error("trop de champions"); //message a mettre en anglais
			res = get_nb_player(vm, argv, i); //donne le bon num d'emplacement au champion
			new_player(vm, res, argv[i]/*path du file*/); //si toutes les conditions sont bonnes on ajoute le player
		}
		++i;
	}
	//si il y a des joueurs return 0, sinon return  1 (1 = error)
	if(vm->nb_player)
		return (0);
	return (1);
}
