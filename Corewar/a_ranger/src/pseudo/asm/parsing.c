// ---------------------------------------H-------------------------------------
//creer un tab de structure qui correspond au tab dans op.c (chaque champ du tableau pour un op)
typedef struct		s_op//?
{
	char			*short_name;
	int				param_numbers;
	int				perm[4];
	int				opcode;
	int				cycles_numbers;
	char			*full_name;
	int				has_ocp;
	int				dir_size;
}					t_op;
t_op				g_op_tab[17]; //en faire un tableau global?

// une struct pour les commande 'cmd', lst_chainnee
// une struct pour les parametres 'param' lst_chainee
// une struct pour les label, lst_chainee
// et une struct pour le champ(?)
		//un index i, pour on se trouve dans le fichier

//--------------------------------main------------------------------------------
//main()
	//F: read_file(), ft_asm(), file_creation(), free_champ()
	//
	//structure: t_champ	champ;
	//si argument < 2 afficher l'usage et return 0
	//on fait l'assemblage pour chaque champion entré en param (while counter < argc)
		//strlen de argv en cours (-1?)
		//si le format du fichier est bon (len > 1, et se termine par .s)
			//initialisation de toute la structure a zero, (bzero)
			//read_file => on ouvre on lit, on fill le res dans la structure, on check
			//ft_asm => assignation des bonne values dans la structure (store_header(), parse_args(), valid_labels())
			//file_creation() => cree le file, le fichier binaire
			//free_champ(), tous les free du champion
		//sinon file invalid, afficher l'error

//read_file() |void| |structure, file_name| => on ouvre on lit, on fill le res dans la structure, on check
	//F: open, close, lseek, read
	//
	//si on a resussi a ouvrir le fichier
	//si il est pas vide (lseek?)
	//on malloc champ->file de la taille du fichier (check si malloc ok)
	//on remet lseek a zero
	//on read le file, stock la value dans champ->file (check si read ok)
	//close le fichier (check si close ok)

//fill_asm/champ() |R: void| |P: structure| => remplis la structure avec les bonnes data
	//F: store_header(), parse_args(), valid_label => in file store_header, et store_cmd
	//
	//penser au caractere de commentaire (?)
	//si il y a pas de parametres (dans champ->cmd)
	//store_header()
	//parse_args()
	//labels_valid()

//du coup si on met le .comment avant le .name ca marche?
//ou est le magic number?
// ------------------------------store_header----------------------------------- 3 questions
//store_header() |void| |structure| =>
	//F: toutes les fonctions de ce fichier
	//
	//TANT QUE le champ->file[i] existe (tant que le fichier est pas fini) ET (si on a un nom OU un comment) =>
		//passer tant que carac est blank (virer les padding, etc..)
		//SI //si c'est egal au nom, ft_strnequ() avec le nom: NAME_CMD_STRING
			//store_name()
		//ELSE IF //si c'est egal au COMMENT_CMD_STRING (le commentaire du champion)
			//store comment()
		//ELSE IF //si c'est un commentaire(COMMENT_CHAR), ou ;
			//store_hash()
		//ELSE
			//error, pas de nom ou de commentaire
		//augmenter i

//store_comment() |void| |structure| => recupere le comment du champion
	//resemble a store_name

//store_hash() |void| |structure| => recup les commentaires(?)
	//augmenter champ->i de 1
	//strcspn(?) de &champ->file[champ->i] jusqu'a \n

//store_name() |void| |structure| => recupere le nom du champion
	//while TANT QUE isspace
		//champ->i++
	//SI champ->file[champ->i] est pas une => "
		//error, le nom dois etre entre double quotes
	//SI ft_strchr() ne trouve pas de => " sur le reste du file
		//error, le nom dois etre entre double quotes
	//strcsnp??????
	//champ->name = strsub() dans champ->file a partir de champ->i, jusqu'a tmp => recup le nom
	//recuperer la len du champ->name
	//SI len est superieur PROG_NAME_LENGTH  OU  len = 0
		//la size du nom est invalid
	//augmenter champ->i a += tmp (tmp = apres le name)

// ------------------------------parse_arg--------------------------------------
//parse_args() |void| |struct champ| =>
	//TANT QUE le file est pas terminer (champ->file[champ->i])
		//TANT QUE blank => enleve tous les pdding(?)
			// champ->i++
		//if c'est un comment ou un COMMENT_CHAR
			//store_hash()
 		//ELSE
			//parse_instruction()
	//FIN TANT QUE

//parse_instruct()
	//

//parse_label()

//find_op()

// -------------------------------store_labels----------------------------------
//valid_label() |void| |struct champ| =>
	//F: find_label()
	//
	//
