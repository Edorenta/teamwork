#include "lem_in.h"

int				get_lines(t_env *env)
{
	static char input[10240] = {0};
	char		*p;
	char		c;
	int			i;
	int			handler;

	p = (char *)input;
	i = -1;
	while ((handler = read(0, &c, 1)) >= 0)
	{
		p[++i] = c;
		!handler ? sig_handler(SIGINT) : 0;
		if (c == 10)
		{
			p[i] = '\0';
			if (*p)
			{
				if (interpret_line(env,p) == 0)
					break;
			}
			else
				break;
			i = -1;
		}
	}
	return (1);
}
