/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ext_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 17:59:42 by fmadura           #+#    #+#             */
/*   Updated: 2018/05/15 17:59:43 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		sort_pile(t_env *env)
{
	return (((ext_sort(env) && all_sort(env)) ? 1 : 0));
}

int		mean_value(long *pile, int start, int end)
{
	int		i;
	int		sum;

	i = start - 1;
	sum = 0;
	while (++i <= end)
		sum += pile[i];
	return (sum / (i - start));
}

int		mass_push(t_env *env, char to, int start, int end)
{
	int i;

	i = to == 'b' ? env->a1 : env->b1;
	while (++i <= start)
		rotate(env, (to == 'b' ? 'a' : 'b'));
	i = to == 'b' ? env->a1 : env->b1;
	while (++i <= (end - start + 1))
		push(env, to);
	return (1);
}

int		mass_smart_insert(t_env *env, char to, int mean)
{
	int		*i;	
	long	*pilefrom;

	i = to == 'b' ? &env->a1 : &env->b1;
	pilefrom = (to == 'b' ? env->a : env->b);
	while (pilefrom[*i] != NONE && dprintf(1, "i: %d\n", *i))
		smart_insert(env, to, mean);			
	//put_piles(env);
	//dprintf(1, "ok\n");
	return (1);
}

int 	quick_fix(t_env *env)
{
	while ((env->a[env->a1] != NONE)
		&& (env->a[env->a1] > env->a[env->size - 1] ||
		env->a[env->a1] > env->a[env->a1 + 1]))
	{
		//RRA;
		(env->a[env->a1] != NONE && env->a[env->a1] > env->a[env->size - 1]) ? RA : RRA;
		(env->a[env->a1] != NONE && env->a[env->a1] > env->a[env->a1 + 1]) ? SA : 0;
	}
	while ((env->b[env->b1] != NONE)
		&& (env->b[env->b1] > env->b[env->size - 1] ||
		env->b[env->b1] > env->b[env->b1 + 1]))
	{
		//RRB;
		(env->b[env->b1] != NONE && env->b[env->b1] > env->b[env->size - 1]) ? RB : RRB;
		(env->b[env->b1] != NONE && env->b[env->b1] > env->b[env->b1 + 1]) ? SB : 0;
	}
		pstr(1, "fixed:",'\n');
		put_piles(env);
	return (1);
}

int		smart_insert(t_env *env, char to, int mean)
{
	int		*i;	
	long	*pilefrom;

	i = to == 'b' ? &env->a1 : &env->b1;
	pilefrom = (to == 'b' ? env->a : env->b);
	while (pilefrom[*i] != NONE
		&& (pilefrom[*i] > mean || pilefrom[env->size - 1] > mean))
	{
		quick_fix(env);
		push(env, to);
		pstr(1, "pushed:",'\n');
		put_piles(env);
		quick_fix(env);
	}
	while (pilefrom[*i] != NONE
		&& (pilefrom[*i] < mean || pilefrom[env->size - 1] < mean))
	{
		//dprintf(1, "second loop\n");
		quick_fix(env);
		pilefrom[*i] < pilefrom[env->size - 1] ? reverse_rotate(env, to == 'b' ? 'a' : 'b') : 0;
		push(env, to);
		pstr(1, "pushed:",'\n');
		put_piles(env);	
		quick_fix(env);
	}
	return (1);
}

/*
	int max;
	int gap[4];

	//i = to == 'b' ? env->a1 : env->b1;
	gap[0] = labs(env->a[env->a1] - env->b[env->b1]);				//PA
	gap[1] = labs(env->a[env->size - 1] - env->b[env->b1]);			//RRA PA RA RA
	gap[2] = labs(env->a[env->a1] - env->b[env->size - 1]);			//RRB PA
	gap[3] = labs(env->a[env->size - 1] - env->b[env->size - 1]);	//RRR PA
	i = 0;
	max = 0;
	while (++i < 4)
		max = gap[i] > gap[i - 1] ? i : max;
*/

int		ext_sort(t_env *env)
{
	//step 1: compare mean values of first and second half:
	int mean[2];

	//reinsert smartly on stack 1
	//while (!all_sort(env))
	for (int i = 0; i < 2; i++)
	{
		mean[0] = mean_value(env->a, env->a1, (env->size - 1) / 2);
		mean[1] = mean_value(env->a, 1 + (env->size - 1) / 2, env->size - 1);
		dprintf(1, "mean[0]: %d mean[1]: %d\n", mean[0], mean[1]);
		//put small half on stack 2
		mean[0] < mean[1] ? mass_push(env, 'b', env->a1, (env->size - 1) / 2)
		: mass_push(env, 'b', (env->size - (env->a1)) / 2, (env->size - 1));
		pstr(1, "after split:",'\n');
		put_piles(env);
		mass_smart_insert(env, 'a', (mean[1] > mean[0] ? mean[1] : mean[0]));
	}
	return (1);
}
