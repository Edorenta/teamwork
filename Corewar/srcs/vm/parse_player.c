/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourne <jjourne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 13:34:27 by jjourne           #+#    #+#             */
/*   Updated: 2018/06/12 14:06:49 by jjourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ----------------------------autre file pour player ?-------------------------------
//F: nombre de joueur?
//

int		get_nb_player(t_vm *vm, char **argv, int arg_num)
{
	int ret;

	ret = 0;
	if (srch_nb_player(argv, arg_num))//pas encore faite
	{
		ret = ft_atoi(argv[arg_num - 1]); //
	}
	return (0);
}

//F: new player
void	new_player(t_vm *vm, int nb, char *str)
{
	vm->player[nb].active = 1;
	vm->player[nb].file_name = str;
}

int		search_players(t_vm *vm, int argc, char **argv)
{
	int i;
	char *tmp;

	i = 1;
	tmp = NULL;
	//add vm->player = 0?
	while (i < argc) //parcours tous les arguments
	{
		//si l'argument contient .cor (strstr dans tmp) ET si tmp != 4 || .cor en millieu de nom?
		if ((tmp = ft_strstr(argv[i], ".cor")) && !tmp[4])
		{
			vm->nb_player++; //apres les errors?
			//si vm->nb_player est superieur au max de champion possible, error
			if (vm->nb_player > MAX_PLAYERS)
				error("trop de champions") //message a mettre en anglais
			get_player(vm, argv, i);
			new_player(vm, /*res de get_player*/, /*nom du player, avec le path?*/argv[i] ); //si toutes les conditions sont bonnes on ajoute le player
		}
		++i;
	}
	//si il y a des joueurs return 0, sinon return  1 (1 = error)
	if(vm->nb_player)
		return (0)
	return (1);
}
