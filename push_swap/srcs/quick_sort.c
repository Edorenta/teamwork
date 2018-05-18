/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ext_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 17:59:42 by fmadura           #+#    #+#             */
/*   Updated: 2018/05/18 09:39:14 by jyildiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int 	quick_fix_a(t_env *env)
{
	//pstr(2, "before A fix:",'\n');
	//put_piles(env);

	//if (A1 > A2 && A1 < MEAN_A)
	if (A1 > A2)
		SA;
	if (A1 > MEAN_A && A4 >= MEAN_A)
		RA;
	if (A4 < MEAN_A)
	{
		RRA;
		SA;
	}
	//pstr(2, "after A fix:",'\n');
	//put_piles(env);
	return (1);
}

int 	quick_fix_b(t_env *env)
{
	//pstr(2, "before B fix:",'\n');
	//put_piles(env);
	if (B1 < B2 && B1 > MEAN_B)
		SB;
	if (B1 < MEAN_B)
		RB;
	if (B4 > MEAN_B)
	{
		if (B1 < MEAN_B)
		{
			RRB;
			SB;
		}
		RB;
	}
	//pstr(2, "after B fix:",'\n');
	//put_piles(env);
	return (1);
}

int 	insert_b(t_env *env)
{
	pstr(2, "before insertion:",'\n');
	put_piles(env);

	while (B1 != NONE)
	{
		quick_fix_a(env);
		PA;
		quick_fix_a(env);
		quick_fix_b(env);
		if (A1 > A2)
			SA;
		pstr(2, "after insertion:",'\n');
		put_piles(env);
	}
	return (1);
}

int		quick_sort(t_env *env)
{
	//step 1: compare mean values of first and second half:
	double mean;

	//reinsert smartly on stack 1
	//while (!all_sort(env))
	for (int i = 0; i < 1; i++)
	{
		mean = mean_value(env->a, env->a1, (env->size - 1));
		dprintf(2, "mean: %f\n", mean);
		//put small half on stack 2
		median_split(env, 'b', mean, 1);
		//median_split(env, 'b', mean, 0.5);
		//pstr(2, "after split:",'\n');
	}
	return (1);
}

int		median_split(t_env *env, char to, double mean, double coef)
{
	int		*i;
	//int		*j;
	long	*pilefrom;
	//long	*pileto;

	mean *= coef;
	pilefrom = (to == 'b' ? env->a : env->b);
	//pileto = (to == 'b' ? env->b : env->a);
	i = (to == 'b' ? &env->a1 : &env->b1);
	//j = (to == 'b' ? &env->b1 : &env->a1);
	//while (++i <= start)
	//	rotate(env, (to == 'b' ? 'a' : 'b'));
	while (*i <= ((env->size - 1) / 2 * coef))
	{
		//*i ? dprintf(2, "coef: %f j/i: %f\n", coef, (double)(*j / *i)) : 0;
		//quick_fix_a(env);
		if (pilefrom[*i] <= mean)
		{
			//plong(1, pileto[*j], ' ');
			push(env, to);
			quick_fix_a(env);		
			quick_fix_b(env);  
			//pileto[*j] <= (mean / 2) ? reverse_rotate(env, to) : 0;
		}
		is_sort(env->a, env->a1, env->size - 1) ? 0 : rotate(env, (to == 'b' ? 'a' : 'b'));
		//printf("i: %d j: %d\n", *i, *j);
	}
	//quick_fix_a(env);
	insert_b(env);
	return (1);
}
