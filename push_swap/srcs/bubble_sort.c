/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyildiz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 14:29:14 by jyildiz-          #+#    #+#             */
/*   Updated: 2018/05/15 10:35:44 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		bb_sort(long *pile, int start, int end)
{
	int		i;
	int		j;
	int		min;
	int		tmp;

	i = start - 1;
	while (++i < end)
	{
		min = pile[i];
		tmp = i;
		j = i + 1;
		while (j <= end)
		{
			if (min > pile[j])
			{
				min = pile[j];
				tmp = j;
			}
			j++;
		}
		pile[tmp] = pile[i];
		pile[i] = min;
	}
	return (is_sort(pile, start, end) ? 1 : 0);
}

/*
void	sort_3A(t_env *env)
{
	(A1 == MAX_A) ? RA : 0;
	(A2 == MAX_A) ? RRA : 0;
	(A1 > A2) ? SA : 0;
}

void	sort_4A(t_env *env)
{
	if(num1>num2) swap(&num1,&num2);
	if(num3>num4) swap(&num3,&num4);
	if(num1>num3) swap(&num1,&num3);
	if(num2>num4) swap(&num2,&num4);
	if(num2,num3) swap(&num2,&num3);
	if (A4 == MAX_A && A1 == (MAX_A - 1))
	{
		RRA; SA; RA; RA;
	}
	else if (A2 == MAX_A && A3 == (MAX_A - 1))
	{
		RA; SA; RA; RA;
	}
	else if (A1 == MAX_A && A3 == (MAX_A - 1))
	{
		SA; RA; SA; RRA;
	}
	else if (A1 == MAX_A && A2 == (MAX_A - 1))
	{
		SA; RA; RA;
	}
	else if (A3 == MAX_A && A1 == (MAX_A - 1))
	{
		SA; RRA;
	}
	if (A3 == MAX_A)
	{
		RRA;
		//if (A2 > A4)
		//{RA;RA;}
		//else
		//{SA;RA;}
	}
	(A1 > A2) ? SA : 0;
}
*/
