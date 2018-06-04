/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_jsonifier.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 20:21:26 by pde-rent          #+#    #+#             */
/*   Updated: 2018/06/04 19:57:14 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static inline int	slen(char *s)
{
	return (*s ? slen(++s) + 1 : 0);
}

static inline int	error(void)
{
	write(2, "use: ./list_jsonifier [\"list name\"][\"element list\"]
			[stringify (0/1)]\nplease make sure that your input is either
			space or newline delimited\n\0", 138);
	return (-1);
}

static inline void	f_write(char **av)
{
	write(1, "{\"", 2);
	write(1, av[1], slen(av[1]));
	write(1, "\":[\0", 3);
}

int					main(int ac, char **av)
{
	int		nb;
	int		stringify;

	nb = 0;
	if (ac != 4)
		return (error());
	f_write(av);
	stringify = av[3][0] == '0' ? 0 : 1;
	while (*av[2])
	{
		nb ? write(1, ",", 1) : 0;
		stringify ? write(1, "\"", 1) : 0;
		while (*av[2] == 32 || *av[2] == 10)
			++av[2];
		while (*av[2] && *av[2] != 32 && *av[2] != 10)
		{
			write(1, av[2], 1);
			++av[2];
		}
		stringify ? write(1, "\"", 1) : 0;
		*av[2] ? ++av[2] : 0;
		nb++;
	}
	write(1, "]}\0", 3);
}
