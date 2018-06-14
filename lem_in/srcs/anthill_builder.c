/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anthill_builder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyildiz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 16:49:05 by jyildiz-          #+#    #+#             */
/*   Updated: 2018/06/05 17:43:17 by jyildiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		move_colony(t_env *env)
{
	int		i;

	while (env->colony[env->nb_ants - 1]->path->room != env->end)
	{
		i = -1;
		while (++i < env->nb_ants)
			move_ant_forward(env, env->colony[i]);
		pstr(1, "\n", '\0');
	}
}
