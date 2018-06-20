#include "lem_in.h"

static void		store_line(t_env *env, char *s)
{
	static t_lines	*last = NULL;
	t_lines			*l;

	(s && *s) ? 0 : put_error(env, "Error: no line to store");
	(l = (t_lines *)malloc(sizeof(t_lines)))
	? 0 : put_error(env, "t_lines malloc failed");
	(l->txt = (char *)malloc(sizeof(char) * (slen(s) + 2)))
	? 0 : put_error(env, "char* malloc failed");
	l->txt[0] = '\0';
	scat(&(l->txt[0]), s, '\0');
	env->first_line ? 0 : (env->first_line = l);
	last ? (last->next = l) : 0;
	last = last ? last->next : l;
	last->next = NULL;
}

void			put_lines(t_env *env)
{
	t_lines			*l;

	l = env->first_line;
	(l && l->txt) ? 0 : put_error(env, "Error: no anthill to print");
	//dprintf(2, "l->txt: %s\n", l->txt);
	pstr(1, l->txt, '\n');
	while (l->next && (l = l->next))
		pstr(1, l->txt, '\n');
}

void			free_lines(t_env *env)
{
	t_lines			*l;
	t_lines			*prev;

	l = env->first_line;
	prev = l;
	while (l && l->next)
	{
		l = l->next;
		(prev && prev->txt) ? free(prev->txt) : 0;
		prev ? free(prev) : 0;
		prev = l;
	}
	(l && l->txt) ? free(l->txt) : 0;
	l ? free(l) : 0;
}

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
			//dprintf(2, "line: %s\n", p);
			if (!*p || (*p && !interpret_line(env,p)))
				break;
			store_line(env, p);
			i = -1;
		}
	}
	return (1);
}
