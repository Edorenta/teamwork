#include "corewar.h"

//attron :Normal (A_NORMAL)
// Meilleur surlignement (A_STANDOUT)
// Inversion vidéo (A_REVERSE)
// À moitié brillant (A_DIM)
// Très brillant ou en gras (A_BOLD)
// Souligné (A_UNDERLINE)
// Mode invisible ou blanc (A_INVIS)

void border_ncurses(WINDOW **w)
{
	box(*w, ACS_VLINE, ACS_HLINE); // ACS_VLINE et ACS_HLINE sont des constantes qui génèrent des bordures par défaut
}

void init_ncurses(WINDOW **w)
{
    *w = initscr();         // Initialise la structure WINDOW et autres paramètres
	*w = subwin(stdscr, LINES, COLS / 2, 0, 0);
    printw("Hello World");  // Écrit Hello World à l'endroit où le curseur logique est positionné

	attron(A_UNDERLINE);
	mvwprintw(*w, 50, 50, "panda powa !");
    wprintw(*w, "Hello World");  // Écrit Hello World à l'endroit où le curseur logique est positionné
	mvwprintw(*w, 1, 1, "Ceci est la fenetre du haut");
    attroff(A_UNDERLINE);
	wrefresh(*w);
	border_ncurses(w);

    refresh();              // Rafraîchit la fenêtre courante afin de voir le message apparaître
    getch();                // On attend que l'utilisateur appui sur une touche pour quitter
    endwin();               // Restaure les paramètres par défaut du terminal

	free(*w); //a deplacer dans les fonctions free a la fin
}
