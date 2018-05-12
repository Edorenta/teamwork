/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyildiz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 05:11:42 by jyildiz-          #+#    #+#             */
/*   Updated: 2018/05/12 06:07:02 by jyildiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_error(void)
{
	ft_putstr("Error\n");
	exit(1);
}

static void max_int(char *av, int sign)
{
	int i;

	i = (sign == -1) ? 1 : 0;
	if (av[i] > 2)
		ft_error();
	if (av[++i] > 2)
		ft_error();
	if (av[++i] > 4)
		ft_error();
	if (av[++i] > 7)
		ft_error();
	if (av[++i] > 4)
		ft_error();
	if (av[++i] > 8)
		ft_error();
	if (av[++i] > 3)
		ft_error();
	if (av[++i] > 6)
		ft_error();
	if (av[++i] > 4)
		ft_error();
	if ((sign == 1 && av[++i] > 7) || (sign == -1 && av[++i] > 8))
		ft_error();
}

void		check_nb(int ac, char **av)
{
	int		i;
	int		j;
	int		spaces;

	i = env->index;
	j = i;
	while (j < ac && i > 0 && av[i])
	{
		if (!full_digits(av[i]))
			return (-1);
		spaces = space_in(av[i]);
		if (spaces)
		{
			ac += spaces;
			j += split_push(av[i], spaces, env);
			i++;
		}
		else
		{
			j += push_to_stack(av[i], env);
			i++;
		}
	}
	return (j);
}

void		check_same(int ac, char **av)
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
				ft_error();
			j++;
		}
		i++;
	}
}

void		check_int(int ac, char **av)
{
	int i;
	int j;
	int	len;
	int	sign;

	i = 1;
	sign = 1;
	while (av[i])
	{
		len = ft_strlen(av[i]);
		if (av[i][0] == '-')
		{
			len--;
			sign = -1;
		}
		if (len > 10)
			ft_error();
		if (len == 10 || len == 11 && sign == -1)
			if (max_int(av[i], sign) == 1)
				ft_error();
		i++;
	}
}
