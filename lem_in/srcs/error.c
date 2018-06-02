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
