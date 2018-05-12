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
		if (!full_digits(av[i]))
			return (0);
		spaces += space_in(av[i]);
		if (spaces && ac += spaces)
			//env->size += split_push(av[i], spaces, env);
			env->size += (spaces + 1);
		else
			env->size += 1;
		i++;
	}
	return (1);
}
