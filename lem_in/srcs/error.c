#include "lem_in.h"

void		put_error(t_env *env, const char *err_msg)
{
	pstr(2, err_msg, '\n');
	deinit_env(env);
	//sleep(50);
	exit(EXIT_FAILURE);
}

void		sig_handler(int sig)
{
	signal(sig, SIG_IGN);
	pstr(2, ("\rLem-in Force Quit\n"), '\0');
	exit(EXIT_FAILURE);
}

int			anthill_complete(t_env *env)
{
	t_parsed_room *parsed;

	env->nb_ants <= 0 ? put_error(env, "Error: no ants") : 0;
	!env->start ? put_error(env, "Error: no start room") : 0;
	!env->end ? put_error(env, "Error: no end room") : 0;
	parsed = R1;
	if (!(parsed && parsed->room && parsed->room->link))
		put_error(env, "Error: incomplete anthill");
	while (parsed->next && parsed->next->room)
	{
		parsed = parsed->next;
		//dprintf(2, "room: %s\n", parsed->room->id);
		if (!(parsed->room->link))
			put_error(env, "Error: a room has no link");
	}
	return (1);
}
