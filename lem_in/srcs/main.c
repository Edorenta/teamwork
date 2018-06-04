#include "lem_in.h"

static void		make_magic_happen(t_env *env)
{
	//solve(env);
	//put_anthill(env);
	//put_paths(env);
}

int				main(int ac, char **av)
{
	t_env		env;

	signal(SIGINT, sig_handler);
	init_env(&env, ac);
	get_lines(&env);
	!anthill_compliant(&env) ? put_error(&env, "Error: anthill not compliant") : 0;
	make_magic_happen(&env);
	return (1);
}