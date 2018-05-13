/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyildiz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 05:11:42 by jyildiz-          #+#    #+#             */
/*   Updated: 2018/05/12 12:06:01 by jyildiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		no_duplicates(int *pile, int size)
{
	int *i;
	int *j;

	j = pile;
	while (j != (pile + size - 1))
	{
		i = j + 1;
		while (i != (pile + size))
		{
		 	//dprintf(1, "i:%d j:%d\n", *i,*j);
			if (i != j && *i == *j)
				return (0);
			++i;
		}
		++j;
	}
	return (1);
}

inline int	push_to_stack(t_env *env, char *av)
{
	long		nb;
	static int  i = -1;

	if (!no_duplicates(av) || !is_int(ac, av))
		put_error();
	env->a[++i] = ft_atol(av[i]);
	return (1);
}

static int	split_push(char *str, int spaces, t_env *env)
{
	char	av[spaces][16];
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
