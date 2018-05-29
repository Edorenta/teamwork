#include "lem_in.h"

static int		get_room(t_env *env, const char *p, int state)
{
	t_room	*room;
	int		i;
	int		x;
	int		y;
	char	tmp[3][256];

	i = -1;
	while (!is_space(p[++i]))
		if (!p[i])
			return (0);
		else
			tmp[0][i] = p[i];
	tmp[0][i + 1] = '\0';
	x = -1;
	while (!is_space(p[++i]))
		if (!p[i] || !is_digit(p[i]))
			return (0);
		else
			tmp[1][++x] = p[i];
	tmp[1][++x] = '\0';
	y = -1;
	while ((p[++i]))
		if (!is_digit(p[i]))
			return (0);
		else
			tmp[2][++y] = p[i];
	tmp[2][++y] = '\0';
	return ((new_room(env, tmp)) ? 1 : 0);
}

static int		get_link(t_env *env, const char *p)
{
	t_room	*room1;
	t_room	*room2;
	int		i;
	char	tmp[256];

	i = -1;
	while (p[++i] != '-')
		if (!p[i] || is_space(p[i]))
			return (0);
		else
			tmp[i] = p[i];
	tmp[i + 1] = '\0';
	str_to_room(env, tmp, room1);
	while (p[++i])
		if (is_space(p[i]))
			return (0);
		else
			tmp[i] = p[i];
	tmp[i + 1] = '\0';
	str_to_room(env, tmp, room2);
	room1->links->next->linked_room = room2;
	room2->links->next->linked_room = room1;
	return (1);
}

//here comes the manual entry interpreter
int				interpret_line(t_env *env, const char *p)
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
