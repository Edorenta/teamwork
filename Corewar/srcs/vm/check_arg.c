/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourne <jjourne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 13:29:46 by jjourne           #+#    #+#             */
/*   Updated: 2018/06/27 22:35:39 by jjourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

//check si toutes la chaine correspond bien a des chiffres
int		ft_str_isdigit(char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

//parcours chaques arguments, et regarde si l'argument correspond a l'option demandé (vérifie si une option existe)
int		ft_strargv(int argc, char **argv, char *str)
{
	int i;

	i = 1;
	while (i < argc) //parcours les arguments
	{
		if (ft_strstr(argv[i], str)) //check si il contient l'option demandé
			return (i); //si oui retourne cette argument
		i++;
	}
	return (0);
}

//recherche de l'option nb_dump ( -d )
int		search_nb_dump(int argc, char **argv)
{
	int ret;
	int nb;

	ret = 0;
	nb = 0;
	if ((ret = ft_strargv(argc, argv, "-d"))) //si l'option d existe dans argv
	{
		if (ft_strlen(argv[ret]) > 2) //si la longueur de l'argument est > a 2, error
			exit_error("Bad argument\n");
		if ((ret + 1) < argc && ft_str_isdigit(argv[ret + 1])) //si on a bien un param apres -d ET si il ne contient que de chiffres
			return (ft_atoi(argv[ret + 1])); //on retourne ce chiffre
		else //sinon error
			exit_error("Dump bad number\n");
	}
	return (-1); //si l'option -d n'existe pas
}

//recherche de l'option ncurses
int		search_ncurses(int argc, char **argv)
{
	if(ft_strargv(argc, argv, "-ncurses")) //check si l'option ncurses existe dans argv (-n / -ncurses)
		return (1);
	return (0);
}

//search de l'option -v, meme principe
int		srch_verbose(int argc, char **argv)
{
	int ret;
	int nb;

	ret = 0;
	nb = 0;
	if ((ret = ft_strargv(argc, argv, "-v")))
	{
		if ((ret + 1) < argc && ft_str_isdigit(argv[ret + 1]))
			return (ft_atoi(argv[ret + 1]));
		else
			exit_error("Verbosity bad number\n");
	}
	return (0);
}

//check que les arguments soit valid ou pas, si il y a des options, et verifie qu'il y a des players (0 si pas de player)
int		check_arg(t_vm *vm, int argc, char **argv)
{
	if (argc == 1) //si argc = 1, pas assez d'argument donc => usage()
		usage();
	vm->dump = search_nb_dump(argc, argv); //return la taille a mettre dans vm->dump si -d existe
	if (!vm->dump) //si on a pas d'option dump, on la passe a zero
		vm->dump++;
	// vm->ncurses = search_ncurses(argc, argv); //return 1 ou 0 si il y a l'option ncurses ou pas
	//add Fnct pour mode verbose?
	vm->verbosity = srch_verbose(argc, argv); //en fonction du chiffre return, pas le meme mode de verbose
	if(search_players(vm, argc, argv))//check si il y a un/des player(s) ou pas
		return (1);
	return (0);
}
