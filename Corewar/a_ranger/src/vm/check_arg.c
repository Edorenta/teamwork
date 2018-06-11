
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
int		srch_nb_dump(int argc, char **argv)
{
	int ret;
	int nb;

	ret = 0;
	nb = 0;
	if ((ret = ft_strargv(argc, argv, "-d"))) //si l'option d existe
	{
		if (ft_strlen(argv[ret]) > 2) //si la longueur de l'argument est > a 2, error
			error("Bad argument\n");
		if ((ret + 1) < argc && ft_str_isdigit(argv[ret + 1])) //si on a bien un param apres -d ET si il ne contient que de chiffres
			return (ft_atoi(argv[ret + 1])); //on retourne ce chiffre
		else //sinon error
			error("Dump bad number\n");
	}
	return (-1); //si l'option -d n'existe pas
}

//
int		check_arg(t_vm *vm, int argc, char **argv)
{
	if (argc == 1) //si argc = 1, pas assez d'argument donc => usage()
		usage();
	vm->dump = search_nb_dump(argc, argv); //return la taille a mettre dans vm->dump si -d existe
}
