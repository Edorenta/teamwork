#include "lem_in.h"

static void		sig_handler(int sig)
{
	signal(sig, SIG_IGN);
	pstr(2, ("\rLem-in Force Quit\n"), '\0');
	exit(0);
}

static int		interpret_line(t_env *env, char *p)
{
	return (1);
}

static int		get_lines(t_env *env)
{
	static char input[1024] = {0};
	char		*p;
	char		c;
	int			i;

	p = (char *)input;
	while (1)
	{
		i = -1;
		while ((read(0, &c, 1) > 0) && (c != 13 && c != 10))
			p[++i] = c;
		p[++i] = '\0';
		interpret_line(env, p);
	}
	return (1);
}

int				main(int ac, char **av)
{
	t_env		env;

	signal(SIGINT, sig_handler);
	init_env(&env, ac);
	get_lines(&env);
	!anthill_compliant(&env) ? put_error(&env, "Error: anthill not compliant") : 0;
	put_anthill(&env);
	put_paths(&env);
	return (1);
}