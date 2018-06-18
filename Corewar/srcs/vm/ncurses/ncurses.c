#include "corewar.h"

//attron :Normal (A_NORMAL)
// Meilleur surlignement (A_STANDOUT)
// Inversion vidéo (A_REVERSE)
// À moitié brillant (A_DIM)
// Très brillant ou en gras (A_BOLD)
// Souligné (A_UNDERLINE)
// Mode invisible ou blanc (A_INVIS)

void init_ncurses(WINDOW **w)
{
    *w = initscr();         // Initialise la structure WINDOW et autres paramètres
	*w = subwin(stdscr, 10, 10, LINES / 2, COLS /2);
	box(*w, ACS_VLINE, ACS_HLINE); // ACS_VLINE et ACS_HLINE sont des constantes qui génèrent des bordures par défaut
    printw("Hello World");  // Écrit Hello World à l'endroit où le curseur logique est positionné

	attron(A_UNDERLINE);
    printw(" Texte en souligne\n");
    attroff(A_UNDERLINE);

	// border_ncurses();

    refresh();              // Rafraîchit la fenêtre courante afin de voir le message apparaître
    getch();                // On attend que l'utilisateur appui sur une touche pour quitter
    endwin();               // Restaure les paramètres par défaut du terminal

	free(*w); //q deplacer dans les fonctions free a la fin
}
