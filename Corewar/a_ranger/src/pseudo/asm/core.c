
//file_creation()
	//
	//

//--------store_cmd-------------------------------------------------------------
//appeler depuis new_cmd()
//valid_params() |void| |struc param, struct op, struc champ| => check le nb de param et les type en fnct de l'opcode
	//F: /
	//
	//on parcours tous les parametres de l'op (si le param existe && i < nb_param de la struct op)
		//SI tmp->code est un registre(REG_CODE) ET (permission pour i MASK T_REG == 0) => si l'ocp ne correspond pas a ce qui est demande en code
			//error, ce parametre ne peut pas etre un registre
		//SI on a un direct, mais que l'ocp ne correspond pas a un direct pour se parametre
			//error
		//SI (idem pour l'indirect)
		//++i;
		//next sur la liste chainee de param
		//=> i = 0 pour le 1er param, i = 2, pour le 2eme param, donc on teste le bon ocp pour le bon param etc..
	//SI i != op->param_numbers || tmp => le nombre de parametres n'est pas bon
		//error
