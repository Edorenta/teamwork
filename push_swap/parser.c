/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyildiz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 05:11:42 by jyildiz-          #+#    #+#             */
/*   Updated: 2018/05/12 06:07:02 by jyildiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void		check_nb(int ac, char **av)
{
	int i;
	int j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (ft_isdigit(av[i][j]) == 0 && (j != 0 || av[i][j] != '-'))
				put_error();
			j++;
		}
		i++;
	}
}

void		check_dup(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = i + 1;
		while (av[j])
		{
			if (ft_strcmp(av[i], av[j]) == 0)
				put_error();
			j++;
		}
		i++;
	}
}

int		check_int(char *av)
{
	return ((av && full_digits(av)))
}

inline int	push_to_stack(t_env *env, char *av)
{
	long		nb;
	static int  i = -1;

	if (!check_nb(av) || !check_dup(av) || !check_int(ac, av)
		|| !full_digits(av))
		put_error();
	env->a[++i] = ft_atol(av[i]);
	return (1);
}

static int	split_push(char *str, int spaces, t_env *env)
{
	char	av[spaces][10];
	char	*p;
	int		i;
	int		j;

	i = 0;
	p = str;
	while (*p)
	{
		while (*p && is_space(*p))
			p++;
		j = -1;
		while (*p && (*p >= '0' && *p <= '9'))
			av[i][++j] = *p++;
		av[i][++j] = '\0';
		dprintf(1, "tok[%d] : %s\n", i, av[i]);
		i++;
	}
	dprintf(1, "tokens: %d theorical: %d\n", i, spaces + 1);
	i = -1;
	while (++i < (spaces + 1))
		push_to_stack(av[i], env);
	return (spaces + 1);
}

int 		get_stacks(int ac, char **av, t_env *env)
{
	int spaces;

	env->size = 0;
	while (env->size < ac && i > 0 && av[i])
	{
//		if (!full_digits(av[i]))
//			return (0);
		spaces += space_in(av[i]);
		if (spaces && ac += split_push(av[i], spaces, env))
			//env->size += split_push(av[i], spaces, env);
			env->size += (spaces + 1);
		else
			env->size += push_to_stack(env, av[i]);
		i++;
	}
	return (1);
}
