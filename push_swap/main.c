/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyildiz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 18:26:08 by jyildiz-          #+#    #+#             */
/*   Updated: 2018/05/12 12:06:28 by jyildiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(long *a, long *b, int nb)
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
	//a = stock_table(ac, av); >> get_stack
	//b = create_table(ac); >> get_stack
	push_swap(a, b, ac - 1);
	free_pile(a, b);
	return (1);
}
