#include "lem_in.h"

//here comes the manual entry interpreter
int		interpret_line(t_env *env, const char *p)
{
	static char state = 0; //1 = ant intake; 2 = 

	if (p[0] == '#')
		if (p[1] != '#' || p[2] == '#')
			return (0);
	get_room(env, p, state);
	get_link(env, p);
	state = 0;
	if (scmp(p, "##start"))	//next room is the anthill entry
		state = 1;
	if (scmp(p, "##end"))	//next room is the last room (queen)
		state = 2;
	return (1);
}
