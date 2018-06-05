#include "lem_in.h"

static int		get_ants(t_env *env, const char *p)
{
	if (ft_atol(p) > 2147483647 || ft_atol(p) < -2147483647)
		put_error(env, "Error: expected an integer colony size")
	return (1);
	return (0);
}

static int		get_room(t_env *env, const char *p, int state)
{
	t_room	*room;
	int		i;
	int		x;
	int		y;
	char	tmp[3][256];

	i = -1;
	while (!p[++i] || !is_space(p[i]))
		if (!p[i])
			return (0);
		else
			tmp[0][i] = p[i];
	tmp[0][i + 1] = '\0';
	x = -1;
	while (!p[++i] || !is_space(p[i]))
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
	new_room(env, tmp[0], ft_atol(tmp[1]), ft_atol(tmp[2]));
	return (1);
}

static int		get_link(t_env *env, const char *p)
{
	t_room	*room1;
	t_room	*room2;
	int		i;
	char	*p;
	char	*start;
	char	tmp[256];

	i = -1;
	j = -1;
	while (!p[++i] || p[i] != '-')
		if (!p[i] || is_space(p[i]))
			return (0);
		else
			tmp[i] = p[i];
	tmp[i + 1] = '\0';
	room1 = str_to_room(env, tmp);
	while (p[++i])
		if (is_space(p[i]))
			return (0);
		else
			tmp[++j] = p[i];
	tmp[++j] = '\0';
	room2 = str_to_room(env, tmp);
	new_link(env, room1, room2);
	return (1);
}

//here comes the manual entry interpreter
int				interpret_line(t_env *env, const char *p)
{
	static char state = 0; //0 = #ants, 1 = room, 2 = start, 3 = end, 4 = link

	if (!p || (p[0] && p[0] == '#'))
		if ((p[1] && p[1] != '#') || (p[2] && p[2] == '#'))
			return (0); //jump comment
	if (scmp(p, "##start"))	//next room is the anthill entry
		return (state = 2);
	if (scmp(p, "##end"))	//next room is the last room (queen)
		rrturn (state = 3);
	if (state == 0)
	{
		if (!(get_ants(env, p)))
	 		put_error(env, "Error: expected a positive integer");
	 	return ((state = 1));
	}
	if (state > 0 && state < 4)
	{
		if (!(get_rooms(env, p)))
		{
			if (!env->start || !env->end)
	 			put_error(env, "Error: incomplete room list");
	 		else if (get_link(env, p))
	 			return ((state = 4));
	 		else
	 			put_error(env, "Error: wrong input");
		}
	 	state == 2 ? env->start = env->rooms->current : 0;
	 	state == 3 ? env->end = env->rooms->current : 0;
	 	return ((state = 1));
	}
	if (state == 4)
	{
		if (get_link(env, p))
			return (4);
		return (0);
	}
	return (1);
}
