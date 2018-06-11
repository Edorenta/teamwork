#include "lem_in.h"

void		put_error(t_env *env, const char *err_msg)
{
	deinit_env(env);
	pstr(2, err_msg, '\n');
	exit(1);
}

void		sig_handler(int sig)
{
	signal(sig, SIG_IGN);
	pstr(2, ("\rLem-in Force Quit\n"), '\0');
	exit(0);
}

int			anthill_complete(t_env *env)
{
	t_parsed_room *parsed;

	if (env->nb_ants <= 0 || !env->start || !env->end)
	{
		printf("%d, %s, %s\n", env->nb_ants, env->start->id, env->end->id);
		return (0);
	}
	parsed = R1;
	if (!(parsed && parsed->room && parsed->room->link))
	{
		printf("test2\n");
		return (0);
	}
	while (parsed->next && parsed->next->room)
	{
		parsed = parsed->next;
		if (!(parsed->room->link))
		{
			printf("test2\n");
			return (0);
		}
	}
	return (1);
}
