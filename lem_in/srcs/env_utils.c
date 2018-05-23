#include "lem_in.h"

void		put_error(t_env *env, const char *err_msg)
{
	deinit_env(env);
	pstr(2, err_msg, '\n');
	exit(1);
}

void		init_env(t_env *env, int ac)
{
	env->start = NULL;
	env->end = NULL;
	env->nb_rooms = 0;
	env->nb_ants = 0;
	env->colony = NULL;
}

void		deinit_env(t_env *env)
{
	free_colony(env);
}