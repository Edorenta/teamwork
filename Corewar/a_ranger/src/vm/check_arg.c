
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

//pour tous les arguments,
int		ft_strargv(int argc, char **argv, char *str)
{
	int i;

	i = 1;
	while (i < argc)
	{
		if (ft_strstr(argv[i], str))
			return (i);
		i++;
	}
	return (0);
}

int		srch_nb_dump(int argc, char **argv)
{
	int ret;
	int nb;

	ret = 0;
	nb = 0;
	if ((ret = ft_strargv(argc, argv, "-d"))) //
	{
		if (ft_strlen(argv[ret]) > 2)
			error("Bad argument\n");
		if ((ret + 1) < argc && ft_str_isdigit(argv[ret + 1]))
			return (ft_atoi(argv[ret + 1]));
		else
			error("Dump bad number\n");
	}
	return (-1);
}

//
int		check_arg(t_vm *vm, int argc, char **argv)
{
	if (argc == 1) //si argc = 1, usage()
		usage();
	vm->dump = search_nb_dump(argc, argv); //return la taille a mettre dans vm->dump
}
