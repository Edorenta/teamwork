/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyildiz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 05:11:42 by jyildiz-          #+#    #+#             */
/*   Updated: 2018/05/12 12:06:30 by jyildiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		alloc_piles(t_env *env)
{
	int i;

	i = -1;
	if (!(env->a = (int *)malloc(sizeof(int) * env->size)))
		put_error();
	if (!(env->b = (int *)malloc(sizeof(int) * env->size)))
		put_error();
	while (++i < env->size)
	{
		env->a[i] = NONE;
		env->b[i] = NONE;
	}
	return (1);
}
