#include <stdio.h>
#include <stdlib.h>

int			modulo(int a, int b) //un peu spe, en gros on m'as explique que le modulo du c etait signe, pour la mem il faut pas, pour ncurses
{
	if (a % b >= 0)
		return (a % b);
	else
		return ((a % b) + b);// le remet en positif
}

int main (void)
{
	printf("\nmodulo = %d\n", -10 % 4096));
	printf("\nmodulo = %d\n", modulo(-10, 4096));
}
