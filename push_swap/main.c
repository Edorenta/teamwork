/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyildiz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 18:26:08 by jyildiz-          #+#    #+#             */
/*   Updated: 2018/05/12 04:38:55 by jyildiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(long *pile1, long *pile2, int nb)
{

}

int		main(int ac, char **av)
{
	t_env env;

	env.size = 0;
	if (ac < 2 || !av[1] || !compliant_arg(ac, av, &env)
		|| !alloc_piles(env) || !get_stacks(ac, av, &env))
		put_error();
	//get_option(ac, av, &env);
	begin_sort(&env);
	//pile1 = stock_table(ac, av); >> get_stack
	//pile2 = create_table(ac); >> get_stack
	push_swap(pile1, pile2, ac - 1);
	free_pile(pile1, pile2);
	return (1);
}
