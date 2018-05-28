int		get_lines(t_env *env)
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