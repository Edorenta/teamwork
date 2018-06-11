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
		if (!handler)
			break;
		p[++i] = c;
		if (c == 10)
		{
			p[i] = '\0';
			if (!*p || (*p && !interpret_line(env,p)))
				break;
			i = -1;
		}
	}
	return (1);
}
