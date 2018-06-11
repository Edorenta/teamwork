//----------------------VM------------------------------------------------------

//------------------les instructions-----------------
//creer les fonctions de chaques instructions:
/*
	live
	ld
	st
	add
	sub
	and
	or
	xor
	zjmp
	ldi
	sti
	fork
	lld
	lldi
	lfork
	aff
*/

//--------------parsing-------------------------

//--------------ncurses-------------------------

//-----------------execution(core)--------------------
//main:
	//on initialise la vm
	//check les arguments
	//creee les players
	//initialise ncurse

	//on run le programme => run()

	//on get le winner
	//on appel ncurses
	//on afficher le resultat en sortie standard

	//free

//run: return un void
	// while tant qu'il y a des process
		//si le cycle en cour == cdt: (cycle to die), on reset les lives dans reset_live()
		//call ncurse*
		//parcour de tous les process (list chainee)
			//si le proc est actif, n l'execute => animate_proc()
		//on augmente le nb de cycles passé
		//ncurse*
	//

//exec_proc: return un void //2 questions !!!!!
	//=====> toutes les fonctions utilisées:
	// is_opcode()
	// create_op()
	// fill_cur_op()
	// show_pc_move()
	// delete_op()
	//
	//mettre le PC a 0
	//si le process est pas sur une instruction (!proc->op.active) ex:il est sur un argument
		//si c'est un opcode : is_opcode()
			// on cree op : create_op()
		//sinon on augmente le pc de 10.
	//sinon
		// on decremente le cycle de 1
        // si le loadtime est 0 (on execute l'instruction a la fin du loadtime : si au debut ca peut poser des probleme de chment de mem)
            // si fill_cur_op() ? on appel la fonction de l'instruction (tab de ptr sur fonction)*****
            // si op est != de zjmp, on move le pc ===> l'instruction zjump modifie le pc, donc on ne le refait pas ici
            // si ==> ncurses -> show_pc_move()
            // delete_op() => remet a zero l'instruction en cours ?????
	// mettre dans la case du pc le nom du joueur (????)

//fill_cur_op: => remplir l'op courant,  return un int (si valide ou pas)
	//check_ocp()
	//find_args()
	//
	//check si on a besoin d'un ocp
	 	//si oui
			//on check si l'ocp est bon
				// si oui
					//on parcours chaque arguments
					//on appel find_args() pour chaques
				//sinon
					// return 0
		//sinon apeler get_reg() => get_registre (il n'y a qu'avec les registre qu'il n'y a pas d'ocp)
		//return 1

//check_ocp()
	// arg_available()
    //
    //

//find_args(), return un int => la taille ou dois sauter l'op
	//get_reg() => faire les decalages en fnct du nombre d'octets, puis stocker l'arg dans proc->op.ar[num] = value; //num = arg
	//get_dir()
	//get_ind()
	//
	//en fonction du type de 'argument, renvoi sa taille
