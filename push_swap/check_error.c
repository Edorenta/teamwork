/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyildiz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 05:11:42 by jyildiz-          #+#    #+#             */
/*   Updated: 2018/05/12 12:06:25 by jyildiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	put_error(void)
{
	ft_putstr("Error\n");
	exit(1);
}

int 		compliant_arg(int ac, char **av, t_env *env)
{
	int spaces;
	int	i;

	i = 1;
	while (env->size < ac && av[i])
	{
		spaces += space_in(av[i]);
		if (spaces && ac += spaces)
			//env->size += split_push(av[i], spaces, env);
			env->size += (spaces + 1);
		else if (full_digits(av[i]))
			env->size += 1;
		else
			return (0);
		i++;
	}
	return (1);
}
