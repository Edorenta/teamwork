/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debt.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 01:25:04 by fmadura           #+#    #+#             */
/*   Updated: 2018/05/18 07:18:22 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_debt(t_env *env, t_debt *debt)
{
	int		i;

	i = 0;
	printf("index\tdebt : %d \n", debt->inxdebt);
	printf("min\tdebt : %d \n", debt->mindebt);
	while (i < env->size)
	{
		printf("%ld %d \n", debt->a[i], debt->da[i]);
		i++;
	}
}
int		ft_abs(int x)
{
	return (x < 0 ? -x : x);
}

int		ft_min(int a, int b)
{
	if (ft_abs(a) > ft_abs(b))
		return (b);
	else
		return (a);
}

void	init_debt(t_env *env)
{
	t_debt	*debts;
	int		index;

	if ((debts = (t_debt *)malloc(sizeof(t_debt))) == NULL)
		put_error(env, "debt malloc failed... :(");
	if ((debts->a = (long *)malloc(sizeof(long) * env->size)) == NULL)
		put_error(env, "pile of debts malloc failed... :(");
	if ((debts->da = (int *)malloc(sizeof(int) * env->size)) == NULL)
		put_error(env, "pile of debt malloc failed... :(");
	duplicate_pile(env->a, debts->a, 0, env->size);
	debts->iter = 0;
	debts->mindebt = INT_MAX;
	debts->inxdebt = 0;
	index = -1;
	while (++index != env->size)
		calc_debt(env, debts, index);
	debts->iter = debts->inxdebt;
	debts->da[debts->iter] = ft_min((debts->a[debts->iter] - debts->iter), (env->size - debts->iter + debts->a[debts->iter]));
	debts->iter++;
	while (debts->iter != debts->inxdebt)
	{
		debts->da[debts->iter] = ft_min((debts->a[debts->iter] - debts->iter), (env->size - debts->iter + debts->a[debts->iter]));
		debts->iter++;
		if (debts->iter > env->size - 1)
			debts->iter = 0;
	}
	print_debt(env, debts);
}

void	calc_debt(t_env *env, t_debt *debt, int index)
{
	int		this;

	debt->iter = index;
	this = 0;
	this += debt->a[debt->iter] - debt->iter;
	debt->iter++;
	while (debt->iter != index)
	{
		this += ft_min(ft_abs((debt->a[debt->iter] - debt->iter)), ft_abs((env->size - debt->iter + debt->a[debt->iter])));
		debt->iter++;
		if (debt->iter > env->size - 1)
			debt->iter = 0;
	}
	if (this < debt->mindebt)
	{
		debt->inxdebt = index;
		debt->mindebt = this;
	}
	debt->iter = 0;
}
