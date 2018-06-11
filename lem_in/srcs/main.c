#include "lem_in.h"

static void		make_magic_happen(t_env *env)
{
	(anthill_complete(env)) ? 0 : put_error(env, "Error: incomplete anthill");
	(void)env;
	put_room_links(env, env->start);
	solve(env);
	//put_anthill(env);
	//put_paths(env);
}

static void		get_options(t_env *env, int ac, char **av)
{
	(void)env;
	(void)ac;
	(void)av;
}

int				main(int ac, char **av)
{
	t_env		env;

	signal(SIGINT, sig_handler);
	init_env(&env);
	get_options(&env, ac, av);
	get_lines(&env);
	make_magic_happen(&env);
	return (1);
}
